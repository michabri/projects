#include "Board.h"

//-------------------------------------------------------------------------
Board::Board() 
{
	buildBoard();
}
//-------------------------------------------------------------------------
void Board::buildBoard() 
{
    for (auto row = 0; row < BOARD_SIZE; row++)
        for (auto col = 0; col < BOARD_SIZE; col++)
            m_board.push_back(std::move(std::make_unique<Tile>(row, col)));
}
//-------------------------------------------------------------------------
void Board::draw(sf::RenderWindow& window) const 
{
    for (auto& circle : m_board)
        circle->draw(window);
}
//-------------------------------------------------------------------------
bool Board::handleClick(const sf::Vector2f& location, const Location& cat_location, Location& player_action)
{
    for (auto& circle : m_board)
    {
        if (circle->handleClick(location, cat_location))
        {
            player_action = circle->getLocation();
            return true;
        }
    }
    return false;
}
//-------------------------------------------------------------------------
bool Board::BFS(int pred[], int dist[], int &destination_index, const Location& cat_location)
{
    int quickest_path = (int)BOARD_SIZE*(int)BOARD_SIZE;
    std::vector<int> quickest_path_vec;
    // a queue to maintain queue of tiles whose
    // adjacency list is to be scanned as per normal
    // BFS algorithm
    std::list<Location> queue;
    queue.push_back(cat_location);

    // boolean array visited[] which stores the
    // information whether its vertex is reached
    // at least once in the Breadth first search
    bool visited[(int)BOARD_SIZE*(int)BOARD_SIZE] = {false};
    visited[cat_location.row * (int)BOARD_SIZE + cat_location.col] = true;
    
    //predecessor of index of cat is -1
    pred[cat_location.row * (int)BOARD_SIZE + cat_location.col] = -1;
    dist[cat_location.row * (int)BOARD_SIZE + cat_location.col] = 0;
    // standard BFS algorithm
    while (!queue.empty()) 
    {
        auto curr_location = queue.front();
        int curr_index_location = curr_location.row * (int)BOARD_SIZE + curr_location.col;
        queue.pop_front();
        
        //loop for checking the adjacent tiles
        for (int i = 0; i < m_board[curr_index_location]->getSizeAdjTiles(); i++)
        {
            Location adj_loc = m_board[curr_index_location]->getIndexAdjacentTile(i);
            int index_adj = adj_loc.row * (int)BOARD_SIZE + adj_loc.col;
            if (visited[index_adj] == false && !m_board[index_adj]->getIsPressed())
            {
                visited[index_adj] = true;
                queue.push_back(m_board[index_adj]->getLocation());
                pred[index_adj] = curr_index_location;
                dist[index_adj] = dist[curr_index_location] + 1;

                // We stop BFS when we find the edge
                if (adj_loc.row == 0 || adj_loc.row == (int)BOARD_SIZE - 1 || 
                    adj_loc.col == 0 || adj_loc.col == (int)BOARD_SIZE - 1)
                {
                    if (dist[index_adj] <= quickest_path)
                    {
                        quickest_path = dist[index_adj];
                        quickest_path_vec.push_back(index_adj);
                    }
                }
            }
        }
    }
    // if the cat is blocked
    if (quickest_path_vec.size() == 0)
        return false;
    
    //randomize the quickest path
    srand(time(NULL));
    int i = rand() % quickest_path_vec.size();
    destination_index = quickest_path_vec[i];
    return true;
}

//-------------------------------------------------------------------------
Location Board::getNextCatLocation(const Location& cat_location)
{
    // predecessor[i] array stores predecessor of i
    int pred[(int)BOARD_SIZE*(int)BOARD_SIZE];
    int dist[(int)BOARD_SIZE * (int)BOARD_SIZE] = {INT_MAX};
    int destination; // the last tile (the edge)

    // if the cat is blocked
    if (BFS(pred, dist, destination, cat_location) == false) 
    {
        int index_cat = cat_location.row * (int)BOARD_SIZE + cat_location.col;
        for (int i = 0; i < m_board[index_cat]->getSizeAdjTiles(); i++)
        {
            Location adj_loc = m_board[index_cat]->getIndexAdjacentTile(i);
            int index_adj = adj_loc.row * (int)BOARD_SIZE + adj_loc.col;
            if (!m_board[index_adj]->getIsPressed())
                return adj_loc;
        }
        //won
        return Location(-1, -1);
    }

    // vector path stores the shortest path
    std::vector<int> path;
    while (pred[destination] != -1) 
    {
        path.push_back(destination);
        destination = pred[destination];
    }
    int row = path[path.size() - 1] / (int)BOARD_SIZE;
    int col = path[path.size() - 1] % (int)BOARD_SIZE;
    Location loc(row, col);
    return loc;
}
//-------------------------------------------------------------------------
void Board::randomizeBoard(const int& level)
{
    if(level > 1)
        clearBoard();
    srand(time(NULL));
    auto pressed_tiles = 0;
    switch (level)
    {
    case 1: pressed_tiles = 14; break;
    case 2: pressed_tiles = 9; break;
    case 3: pressed_tiles = 5; break;
    }
    for (int i = 0; i < pressed_tiles; i++)
    {
        auto index = rand() % ((int)BOARD_SIZE * (int)BOARD_SIZE);
        auto index_cat = (int)BOARD_SIZE / 2 * (int)BOARD_SIZE + (int)BOARD_SIZE / 2;
        if (!m_board[index]->getIsPressed() && index != index_cat)
            m_board[index]->setIsPressed(true);
        else
            i--;
    }
}
//-------------------------------------------------------------------------
void Board::undoTile(const Location& loc)
{
    int index = loc.row * (int)BOARD_SIZE + loc.col;
    m_board[index]->setIsPressed(false);
}
//-------------------------------------------------------------------------
void Board::clearBoard()
{
    for (auto& circle : m_board)
        circle->setIsPressed(false);
}