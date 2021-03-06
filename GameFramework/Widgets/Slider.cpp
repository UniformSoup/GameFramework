#include "Slider.h"

#include <iostream>

void Slider::centerText()
{
	text.setOrigin(
		text.getLocalBounds().left + text.getLocalBounds().width / 2.0f,
		text.getLocalBounds().top + text.getLocalBounds().height / 2.0f
	);
	text.setPosition(
		rect.left + rect.width / 2.f,
		rect.top + rect.height / 4.f
	);
}

void Slider::draw(sf::RenderWindow& window)
{
	window.draw(bar);
	window.draw(notch);
	window.draw(text);
}

void Slider::update(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		if (isOver(e.mouseButton.x, e.mouseButton.y, notch.getGlobalBounds()))
			isHeld = true;
		else if (!isHeld && isOver(e.mouseButton.x, e.mouseButton.y, bar.getGlobalBounds()))
		{
			notch.setPosition(sf::Vector2f(static_cast<float>(e.mouseButton.x), notch.getPosition().y));
			value = (notch.getPosition().x - rect.left) / rect.width;
			changed = true; isHeld = true;
		}
	}

	else if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
		isHeld = false;

	else if (e.type == sf::Event::MouseMoved)
	{
		if (isHeld)
		{
			if (e.mouseMove.x < rect.left)
				notch.setPosition(rect.left, notch.getPosition().y);
			else if (e.mouseMove.x > rect.left + rect.width)
				notch.setPosition(rect.left + rect.width, notch.getPosition().y);
			else
				notch.setPosition(static_cast<float>(e.mouseMove.x), notch.getPosition().y);

			value = (notch.getPosition().x - rect.left) / rect.width;
			changed = true;
		}
		else if (isOver(e.mouseMove.x, e.mouseMove.y, rect))
		{
			notch.setFillColor(sf::Color(colour.r / 2U, colour.g / 2U, colour.b / 2U));
			bar.setFillColor(sf::Color(colour.r / 2U, colour.g / 2U, colour.b / 2U));
		}
		else
		{
			notch.setFillColor(colour);
			bar.setFillColor(colour);
		}
	}
}

void Slider::setText(const std::string& s)
{
	text.setString(s);
	centerText();
}

void Slider::setCharSize(const unsigned int& charsz)
{
	text.setCharacterSize(charsz);
	centerText();
}

Slider::Slider(const std::string& name, const sf::Font& f, const float& value, const sf::FloatRect& rect, const unsigned int& charsz)
	: Widget(name, f, charsz), value(value), bar(sf::Vector2f(rect.width, rect.height / 6.0f)), notch(sf::Vector2f(rect.width / 20.0f, rect.height / 2.0f)), rect(rect)
{
	// notch width is w/20, notch height is h/2, bar height is h/6. 
	notch.setOrigin(sf::Vector2f(rect.width / 40.f, rect.height / 4.0f));
	notch.setPosition(sf::Vector2f(rect.left + rect.width*value, rect.top + 3.f*rect.height/4.f));
	notch.setFillColor(sf::Color::White);
	notch.setOutlineColor(sf::Color::Black);
	notch.setOutlineThickness(5.f);
	
	bar.setPosition(sf::Vector2f(rect.left, rect.top + 2 * rect.height / 3.f));
	bar.setFillColor(sf::Color::White);
	bar.setOutlineColor(sf::Color::Black);
	bar.setOutlineThickness(5.f);

	centerText();
}