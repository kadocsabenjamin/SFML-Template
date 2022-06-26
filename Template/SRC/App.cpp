#include "../Headers/App.h"
#include <Windows.h>

App::App()
{
    view.setSize(1000, 800);
    window = new sf::RenderWindow(sf::VideoMode(1000, 800), "");
    
    MainLoop();
}

App::~App()
{
}

void App::MainLoop()
{
    while (window->isOpen())
    {

        EventPoll();
        UpdateView();

        window->display();
        window->clear();
        Sleep(30);
    }
}

void App::EventPoll()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void App::UpdateView()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        view.move(0, kViewSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        view.move(0, -1 * kViewSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        view.move(-1 * kViewSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        view.move(kViewSpeed, 0);
    }
    window->setView(view);
}

