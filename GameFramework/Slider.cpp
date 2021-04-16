#include "Slider.h"

#include <iostream>

void Slider::centerText()
{
	text.setOrigin(
		text.getLocalBounds().left + text.getLocalBounds().width / 2.0f,
		text.getLocalBounds().top + text.getLocalBounds().height / 2.0f
	);
	text.setPosition(
		rect.getPosition().x + rect.getSize().x / 2.f,
		rect.getPosition().y + rect.getSize().y / 4.f
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
		if (isOver(e.mouseButton.x, e.mouseButton.y, notch))
			isHeld = true;
		else if (!isHeld && isOver(e.mouseButton.x, e.mouseButton.y, bar))
		{
			notch.setPosition(sf::Vector2f(e.mouseButton.x, notch.getPosition().y));
			value = (notch.getPosition().x - rect.getPosition().x) / rect.getSize().x;
			changed = true;
			isHeld = true;
		}
	}
	else if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
		isHeld = false;
	if (e.type == sf::Event::MouseMoved)
	{
		if (isHeld)
		{
			if (e.mouseMove.x < rect.getPosition().x)
				notch.setPosition(rect.getPosition().x, notch.getPosition().y);
			else if (e.mouseMove.x > rect.getPosition().x + rect.getSize().x)
				notch.setPosition(rect.getPosition().x + rect.getSize().x, notch.getPosition().y);
			else
				notch.setPosition(e.mouseMove.x, notch.getPosition().y);

			value = (notch.getPosition().x - rect.getPosition().x) / rect.getSize().x;
			changed = true;
		}
		else if (isOver(e.mouseMove.x, e.mouseMove.y, rect))
		{
			notch.setFillColor(sf::Color(128, 128, 128));
			bar.setFillColor(sf::Color(128, 128, 128));
		}
		else
		{
			notch.setFillColor(sf::Color::White);
			bar.setFillColor(sf::Color::White);
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

Slider::Slider(const std::string& name, const sf::Font& f, const float& value, const float& x, const float& y, const float& w, const float& h, const unsigned int& charsz)
	: Widget(name, f, charsz), value(value), bar(sf::Vector2f(w, h / 6.0f)), notch(sf::Vector2f(w / 20.0f, h / 2.0f)), rect(sf::Vector2f(w, h))
{
	rect.setPosition(sf::Vector2f(x, y));
	// notch width is w/20, notch height is h/2, bar height is h/6. 
	notch.setOrigin(sf::Vector2f(w / 40.f, h / 4.0f));
	notch.setPosition(sf::Vector2f(x + w*value, y +  3.0*h/4.0f));
	notch.setFillColor(sf::Color::White);
	notch.setOutlineColor(sf::Color::Black);
	notch.setOutlineThickness(5.f);
	
	bar.setPosition(sf::Vector2f(x, y + 2 * h / 3.0f));
	bar.setFillColor(sf::Color::White);
	bar.setOutlineColor(sf::Color::Black);
	bar.setOutlineThickness(5.f);

	centerText();
}