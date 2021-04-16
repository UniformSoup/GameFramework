#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Widget {
private:
	sf::Text text;

	inline virtual void centerText() = 0;
	inline virtual bool isOver(const int& x, const int& y) const = 0;

public:
	// charsz is the size of the text
	Widget(const std::string& name, const sf::Font& f, const float& x, const float& y, const float& w, const float& h, const unsigned int& charsz = 30U);
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(const sf::Event& e) = 0;
};
