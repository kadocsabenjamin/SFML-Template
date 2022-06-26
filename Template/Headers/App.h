#pragma once

#include <SFML/Graphics.hpp>

constexpr int kViewSpeed = 10;

class App
{
public:
	App();
	~App();


private:
	void MainLoop();
	void EventPoll();
	void UpdateView();

	sf::RenderWindow* window;
	sf::View view;
};

