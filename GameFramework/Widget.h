#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Widget {
protected:
	sf::Text text;

	virtual void centerText() = 0;
	inline bool isOver(const int& x, const int& y, const sf::RectangleShape& r) const;
	Widget(const std::string& name, const sf::Font& f, const unsigned int& charsz);

public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(const sf::Event& e) = 0;
	
	virtual std::string getText() const { return text.getString(); };
	virtual void setText(const std::string& s) = 0;
	
	virtual unsigned int getCharSize() const { return text.getCharacterSize(); };
	virtual void setCharSize(const unsigned int& charsz) = 0;
};

inline bool Widget::isOver(const int& x, const int& y, const sf::RectangleShape& r) const
{
	return (x >= r.getPosition().x &&
		x <= r.getPosition().x + r.getSize().x &&
		y >= r.getPosition().y &&
		y <= r.getPosition().y + r.getSize().y);
};
