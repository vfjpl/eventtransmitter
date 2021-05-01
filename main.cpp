#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Network/UdpSocket.hpp>

int main(int argc, char* argv[])
{
    if(argc != 2)
        return EXIT_FAILURE;

    sf::RenderWindow app(sf::VideoMode::getDesktopMode(), "SFML window", sf::Style::Fullscreen);
    sf::UdpSocket socket;

    while(app.isOpen())
    {
        sf::Event event;
        while(app.pollEvent(event))
        {
            socket.send(&event, sizeof(sf::Event), argv[1], 7000);
            if(event.type == sf::Event::Closed)
                app.close();
        }
        app.clear();
        app.display();
    }

    return EXIT_SUCCESS;
}
