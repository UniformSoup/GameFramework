#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Widget {
protected:
	sf::Text text;

	virtual void centerText() = 0;
	inline bool isOver(const int& x, const int& y, const sf::FloatRect& r) const;
	Widget(const std::string& name, const sf::Font& f, const unsigned int& charsz)
		: text(name, f, charsz) { text.setFillColor(sf::Color::Black); }

public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(const sf::Event& e) = 0;
	
	std::string getText() const { return text.getString(); };
	virtual void setText(const std::string& s) = 0;
	
	unsigned int getCharSize() const { return text.getCharacterSize(); };
	virtual void setCharSize(const unsigned int& charsz) = 0;

	inline void setTextColour(const sf::Color& c) { text.setFillColor(c); };
	inline sf::Color getTextColour() const { return text.getFillColor(); };

};

inline bool Widget::isOver(const int& x, const int& y, const sf::FloatRect& r) const
{
	return r.contains(static_cast<float>(x), static_cast<float>(y));
	/*(x >= r.left &&
		x <= r.left + r.width &&
		y >= r.top &&
		y <= r.top + r.height);*/
};

