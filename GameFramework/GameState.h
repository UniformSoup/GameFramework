#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

#include "Timing.h"

class GameState
{
protected: // anything that all of the differenet states need (ie a single font, or options) can be shared here.
	sf::RenderWindow* window;
	std::stack<GameState*>* states;
	sf::Font* f;

	GameState(sf::RenderWindow* window, std::stack<GameState*>* states, sf::Font* f) : window(window), states(states), f(f) {};
	GameState(GameState* state) { *this = *state; };

public:
	virtual void update(const Timing::duration& elapsed) = 0;
	virtual void render() = 0;
};