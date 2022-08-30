#pragma once
#include <SFML\Network.hpp>
#include <SFML\Graphics.hpp>

const unsigned short PORT = 55001;

struct playerData
{
	sf::Vector2f direction = sf::Vector2f(0, 0);
	bool shoot = false;
	int typeOfGift = -1;
};

class Socket
{
public:
	Socket() = default;

	void setMode(bool host);
	bool connect(const std::string& address);
	bool openHost();
	void receive(playerData& inputData);
	void send(const playerData& inputData);
	void disconnect();

	std::string getLocalIp();

private:
	sf::TcpSocket m_socket;
	playerData m_toSend;
	playerData m_receive;
	std::size_t m_size;
	bool m_host = false;
};