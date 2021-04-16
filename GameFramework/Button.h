#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
	//int x, y, w, h; // why in the name of god almighty would you have a rectangle with x,y,w,h in it
	// and then have variables for it too? you should be ashamed.
	sf::RectangleShape r;
	bool isPressed = false;
	//sf::Text buttonName; // a name like button text or text would be better
	sf::Text text;
	//sf::Font font; // This is bad and wasteful i used to do this in the past
	// you should pass the font by reference though the constructor. 
	// because making a new font for each button is really wasteful.

	// A (hopefully) better text centering function. see the docs for the set origin function.
	// this function should be run when the text is initialised or changes.
	inline void centerText();
	inline bool isOver(const int& x, const int& y) const;

public:
	// charsz is the size of the text
	Button(const std::string& name, const sf::Font& f, const float& x, const float& y, const float& w, const float& h, const unsigned int& charsz = 30U);
	void draw(sf::RenderWindow& window);
	void update(const sf::Event& e);
	bool pressed();
};