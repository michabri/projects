#include "Board.h"

//=======================================================================================
void Board::setBoard(std::string name_level, b2World* world)
{
	srand(time(NULL));
	std::fstream in;
	in.open(name_level);
	if (!in.is_open())
	{
		std::cerr << "could not open the file -" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	int i = 0;

	while (getline(in, line))
	{
		m_board.push_back(line);
		i++;
	}
	m_cols = (int)line.size();
	m_rows = i;
	in.close();

	createObject(world);
	buildFloor(world);
	//buildCeiling(world);
}
//=======================================================================================
void Board::draw(sf::RenderWindow& window) 
{
	window.draw(m_floor);
	window.draw(m_ceiling);

	for (auto& ball : m_balls)
		ball->draw(window);
	
	for (auto& it : m_static_objects)
		it->draw(window);
}
//=======================================================================================
void Board::buildFloor(b2World* world)
{
	m_floor.setSize(sf::Vector2f(WINDOW_WIDTH - STATIC_OBJECT_SIZE_PIXEL, 5.f));
	m_floor.setFillColor(sf::Color::Black);
	m_floor.setPosition(sf::Vector2f(STATIC_OBJECT_SIZE_PIXEL / 2.f, WINDOW_HEIGHT - STATIC_OBJECT_SIZE_PIXEL * 0.7f));

	b2BodyDef bodyDef;
	b2PolygonShape groundBox;
	b2FixtureDef fixtureDef;

	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(STATIC_OBJECT_SIZE_PIXEL / 2.f, WINDOW_HEIGHT - STATIC_OBJECT_SIZE_PIXEL * 0.7f);
	m_body_floor = world->CreateBody(&bodyDef);
	groundBox.SetAsBox(m_floor.getSize().x , m_floor.getSize().y );
	fixtureDef.shape = &groundBox;
	fixtureDef.filter.categoryBits = entity::BORDER_FLOOR;
	fixtureDef.filter.maskBits = entity::BALL | entity::PLAYER | entity::GIFT;
	fixtureDef.filter.groupIndex = -1;
	fixtureDef.density = 0.5;
	m_fixture_floor = m_body_floor->CreateFixture(&fixtureDef);
}
//=======================================================================================
void Board::buildCeiling(b2World* world)
{
	m_ceiling.setSize(sf::Vector2f(WINDOW_WIDTH, 5.f));
	m_ceiling.setFillColor(sf::Color::Black);
	m_ceiling.setPosition(sf::Vector2f(STATIC_OBJECT_SIZE_PIXEL / 2.f, STATIC_OBJECT_SIZE_PIXEL* 0.9));

	b2BodyDef bodyDef;
	b2PolygonShape groundBox;
	b2FixtureDef fixtureDef;

	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(STATIC_OBJECT_SIZE_PIXEL / 2.f, STATIC_OBJECT_SIZE_PIXEL * 0.9f);
	m_body_ceiling = world->CreateBody(&bodyDef);

	groundBox.SetAsBox(m_ceiling.getSize().x / 2.f, m_ceiling.getSize().y / 2.f);
	fixtureDef.shape = &groundBox;
	fixtureDef.filter.categoryBits = entity::BORDER_CEILING;
	fixtureDef.filter.maskBits = entity::BALL | entity::WEAPON;
	fixtureDef.filter.groupIndex = -2;
	//fixtureDef.density = 0.5;
	m_fixture_ceiling = m_body_ceiling->CreateFixture(&fixtureDef);
}
//=======================================================================================
sf::Vector2f Board::resizeObject()
{
	float width_object_scale = (float)WINDOW_WIDTH / (float)m_cols;
	float height_object_scale = (float)WINDOW_HEIGHT / (float)m_rows;

	return sf::Vector2f((width_object_scale / (float)(STATIC_OBJECT_SIZE_PIXEL-10)),
		(height_object_scale / (float)(STATIC_OBJECT_SIZE_PIXEL-5)));
}
//=======================================================================================
static std::unique_ptr<StaticObject> createStaticObject(const char c, sf::Vector2f& loc, b2World* world, const sf::Vector2f& scale)
{
	switch (c)
	{
	case '=': 
		return std::make_unique<Wall>(loc, world, scale);
	case '#':
		return std::make_unique<Gate>(loc, world, scale);
	}
	return nullptr;
}
//=======================================================================================
static std::unique_ptr<Ball> createBall(const char c, sf::Vector2f& loc, b2World* world)
{
	switch (c)
	{
	case 'O':
		return std::make_unique<Ball>(sf::Vector2f(loc.x, 3 * STATIC_OBJECT_SIZE_PIXEL),
									  ballRadius::MEGA_BIG, world, b2Vec2(40.f, 1.f));
	case 'o':
		return std::make_unique<Ball>(sf::Vector2f(loc.x , 3 *STATIC_OBJECT_SIZE_PIXEL),
									  ballRadius::BIG, world, b2Vec2(40.f, 1.f));
	case '*':
		return std::make_unique<Ball>(sf::Vector2f(loc.x, 3 * STATIC_OBJECT_SIZE_PIXEL),
									  ballRadius::MEDIUM, world, b2Vec2(40.f, 1.f));
	case '.':
		return std::make_unique<Ball>(sf::Vector2f(loc.x, 3 * STATIC_OBJECT_SIZE_PIXEL),
									  ballRadius::SMALL, world, b2Vec2(40.f, 1.f));
	}
	return nullptr;
}
//=======================================================================================
void Board::createObject(b2World* world)
{
	float width_object_scale = (float)WINDOW_WIDTH / (float)m_cols;
	float height_object_scale = (float)WINDOW_HEIGHT / (float)m_rows;
	for (int row = 0; row < m_rows; row++)
	{
		for (int col = 0; col < m_cols; col++)
		{
			sf::Vector2f loc((col * width_object_scale) + width_object_scale * 0.5,
							(row * height_object_scale) + height_object_scale * 0.5);
			char c = m_board[row][col];
			sf::Vector2f scale = resizeObject();
			
			std::unique_ptr<StaticObject> static_object = createStaticObject(c, loc, world, scale);
			if (static_object)
				m_static_objects.push_back(std::move(static_object));
			if (c == '#')
				m_num_gates++;

			std::unique_ptr<Ball> ball = createBall(c, loc, world);
			if(ball)
				m_balls.push_back(std::move(ball));
		}
	}
}
//=======================================================================================
bool Board::checkAllBallsCleared() const
{
	return m_balls.empty();
}
//=======================================================================================
bool Board::checkSplit(ContactListener &cl, b2World* world, playerData& onlineData)
{
	int index = -1;
	static sf::Vector2f loc;
	static float radius;
	if (cl.isWeaponHitBall(index))
	{
		for (auto it = m_balls.begin(); it < m_balls.end(); it++)
		{
			if ((*it)->getId() == index)
			{
				radius = (*it)->getRadius() / 2;
				loc = (*it)->getLocation();
				world->DestroyBody(&(*it)->getBody());
				m_balls.erase(it);	// split here
				if (radius > ballRadius::SMALL)
				{
					m_balls.push_back(std::move(std::make_unique<Ball>(Ball(loc + sf::Vector2f(radius / 2, 0), radius, world, b2Vec2(40.f, -80.f)))));
					m_balls.push_back(std::move(std::make_unique<Ball>(Ball(loc - sf::Vector2f(radius / 2, 0), radius, world, b2Vec2(-40.f, -80.f)))));
					if (!m_usingSocket)
						auto type = addGift(loc, world);
					else if (m_usingSocket && m_host)
						onlineData.typeOfGift = addGift(loc, world);
				}
				return true;
			}
		}
	}
	if (m_usingSocket && !m_host)
	{
		addGift(loc, world, onlineData.typeOfGift);
		onlineData.typeOfGift = -1;
	}
	return false;
}
//=======================================================================================
int Board::addGift(const sf::Vector2f& loc, b2World* world)
{
	int num_of_gifts = 7;
	int chance = rand() % 3;
	if (chance == 0)
	{
		int type = rand() % num_of_gifts;
		m_static_objects.push_back(std::move(std::make_unique<Gift>(Gift(loc, world, type))));
		return type;
	}
	return -1;
}
//=======================================================================================
void Board::addGift(const sf::Vector2f& loc, b2World* world, int type)
{
	if(type != -1)
		m_static_objects.push_back(std::move(std::make_unique<Gift>(Gift(loc, world, type))));
}
//=======================================================================================
bool Board::checkHitGift(ContactListener& cl, b2World* world, int& value, int &index_player)
{
	int index;
	if (cl.isPlayerHitGift(index, index_player))
	{
		for (auto gift = m_static_objects.begin(); gift != m_static_objects.end(); gift++)
		{
			if ((typeid(**gift) == typeid(Gift)) && ((*gift)->getId() == index))
			{
				value = (*gift)->getValue();
				world->DestroyBody(&(*gift)->getBody());
				m_static_objects.erase(gift);
				return true;
			}
		}
	}
	return false;
}
//=======================================================================================
void Board::updateObjects(b2World* world)
{
	for (auto& ball : m_balls)
		ball->upadateBall();
	for (auto it = m_static_objects.begin(); it != m_static_objects.end(); it++)
	{
		if ((typeid(**it) == typeid(Gift)) && !(*it)->updateObj())
		{
			world->DestroyBody(&(*it)->getBody());
			m_static_objects.erase(it);
			break;
		}
	}
}
//=======================================================================================
void Board::clearBoard()
{
	m_static_objects.clear();
	m_balls.clear();
	m_board.clear();
}

//=======================================================================================
void Board::checkAllBallsToTheRightAndDownGone(b2World* world)
{
	for (int i = 0; i < m_num_gates; i++)
	{
		for (auto gate = m_static_objects.begin(); gate != m_static_objects.end(); gate++)
		{
			bool found = false;
			for (auto ball = m_balls.begin(); ball != m_balls.end(); ball++)
			{
				if ((typeid(**gate) == typeid(Gate)) && (*gate)->getLocation().x < (*ball)->getLocation().x )
				{
					found = true;
					break;
				}
			}
			if (typeid(**gate) == typeid(Gate) && !found)
			{
				world->DestroyBody(&(*gate)->getBody());
				m_static_objects.erase(gate);
				m_num_gates--;
				return ;
			}
		}
	}
}
//=======================================================================================
void Board::usingSocket(bool isHost)
{
	m_usingSocket = true;
	m_host = isHost;
}
//=======================================================================================
void Board::restartTimers()
{
	for (auto& it : m_static_objects)
		it->restartTimer();
}