#include "Socket.h"
#include <iostream>

void Socket::setMode(bool host)
{
	m_host = host;
}

bool Socket::openHost()
{
	if (!m_host)
		return false;

	sf::TcpListener listener;
	listener.listen(PORT);

	listener.accept(m_socket);
	std::cout << "New client connected: " << m_socket.getRemoteAddress() << std::endl;

	return true;
}

bool Socket::connect(const std::string& address)
{
	if (m_host)
		return false;

	auto status = m_socket.connect(address, PORT);
	if (status == sf::Socket::Status::Done)
		return true;

	return false;
}

void Socket::receive(playerData& inputData)
{
	m_socket.receive(&m_receive, sizeof(m_receive), m_size);
	inputData.direction = m_receive.direction;
	inputData.shoot = m_receive.shoot;
	inputData.typeOfGift = m_receive.typeOfGift;
}

void Socket::send(const playerData& inputData)
{
	m_toSend.direction = inputData.direction;
	m_toSend.shoot = inputData.shoot;
	m_toSend.typeOfGift = inputData.typeOfGift;
	m_socket.send(&m_toSend, sizeof(m_toSend));
}

std::string Socket::getLocalIp()
{
	return sf::IpAddress::getLocalAddress().toString();
}

void Socket::disconnect()
{
	m_socket.disconnect();
}