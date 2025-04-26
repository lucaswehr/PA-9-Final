#include "network.hpp"

void Network::Networking()
{

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect({ 192, 168, 0, 5 }, 53000);

    if (status != sf::Socket::Status::Done)
    {
        std::cout << "Error" << std::endl;

    }

    sf::TcpListener listener;

    // bind the listener to a port
    if (listener.listen(53000) != sf::Socket::Status::Done)
    {
        std::cout << "Error" << std::endl;
    }

    // accept a new connection
    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Status::Done)
    {
        std::cout << "Error" << std::endl;
    }

    std::array<char, 100> data;

    // TCP socket:
    if (socket.send(data.data(), data.size()) != sf::Socket::Status::Done)
    {
        std::cout << "Error" << std::endl;
    }
    std::size_t received;

    // TCP socket:
    if (socket.receive(data.data(), data.size(), received) != sf::Socket::Status::Done)
    {
        // error...
    }
    std::cout << "Received " << received << " bytes" << std::endl;

    sf::SocketSelector selector;
    selector.add(socket);

    if (selector.wait(sf::seconds(10.f)))
    {
        std::cout << "WORKS";
    }
    else
    {
        std::cout << "Error" << std::endl;
    }


}
