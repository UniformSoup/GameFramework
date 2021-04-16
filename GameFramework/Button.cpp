#include "Button.h"

inline void Button::centerText()
{
	text.setOrigin(
		text.getLocalBounds().left + text.getLocalBounds().width / 2.0f,
		text.getLocalBounds().top + text.getLocalBounds().height / 2.0f
	);
	text.setPosition(
		r.getPosition().x + r.getSize().x / 2.f,
		r.getPosition().y + r.getSize().y / 2.f
	);
}

Button::Button(const std::string& name, const sf::Font& f, const float &x, const float& y, const float& w, const float& h, const unsigned int& charsz)
	: r(sf::Vector2f(w, h)), Widget(name,f, charsz)
{
	r.setPosition(sf::Vector2f(x, y));
	r.setFillColor(sf::Color::White);
	r.setOutlineColor(sf::Color::Black);
	r.setOutlineThickness(5.f);

	centerText();
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(r);
	window.draw(text);
}

void Button::update(const sf::Event& e)
{
	if (e.type == sf::Event::MouseButtonPressed)
		isPressed = isOver(e.mouseButton.x, e.mouseButton.y, r);
	else if (e.type == sf::Event::MouseMoved && isOver(e.mouseMove.x, e.mouseMove.y, r))
		r.setFillColor(sf::Color(128, 128, 128));
	else
		r.setFillColor(sf::Color::White);
}

void Button::setText(const std::string& s)
{
	text.setString(s);
	centerText();
}
void Button::setCharSize(const unsigned int& charsz)
{
	text.setCharacterSize(charsz);
	centerText();
}