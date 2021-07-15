#pragma once

#include "Timing.h"
#include "StateMachine.h"
#include <SFML/Graphics.hpp>

struct GameData
{
	sf::RenderWindow window;
	sf::Font f;
};

class GameState
{
protected: // anything that all of the different states need (ie a single font, or options) can be shared here.
	StateMachine<GameState>* s;
	GameData * const pdata;
	GameState(GameData* data, StateMachine<GameState>* machine) : pdata(data), s(machine) {};
	GameState(GameState * last) : GameState(last->pdata, last->s) {};

public:
	~GameState() {};
	virtual void update(const Timing::duration& elapsed) = 0;
	virtual void render() = 0;
};