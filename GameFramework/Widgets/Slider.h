#pragma once

#include "Widget.h"
#include <string>

class Slider : public Widget {
private:
	float value;
	bool isHeld = false, changed = false;
	sf::RectangleShape notch, bar;
	sf::FloatRect rect;
	sf::Color colour = sf::Color::White;

	void centerText();

public:
	Slider(const std::string& name, const sf::Font& f, const float& value, const sf::FloatRect& rect, const unsigned int& charsz = 30U);
	
	void draw(sf::RenderWindow& window);
	void update(const sf::Event& e);

	void setText(const std::string& s);
	void setCharSize(const unsigned int& charsz);

	inline bool hasChanged();
	inline float getValue() const { return value; };
	inline void setValue(const float& f);
};

inline void Slider::setValue(const float& f)
{
	if (f >= 0 && f <= 1)
	{
		value = f; changed = true;
		notch.setPosition(sf::Vector2f(rect.left + rect.width * value, notch.getPosition().y));
	}
}

inline bool Slider::hasChanged()
{
	bool temp = changed;
	changed = false;
	return temp;
};