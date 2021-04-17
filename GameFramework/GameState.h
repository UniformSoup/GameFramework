#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

#include "Timing.h"

struct GameData;

class GameState
{
protected: // anything that all of the differenet states need (ie a single font, or options) can be shared here.
	GameData* pdata;
	GameState(GameData * data) : pdata(data) {};

public:
	~GameState() {};
	virtual void update(const Timing::duration& elapsed) = 0;
	virtual void render() = 0;
};