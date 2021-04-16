#include "Game.h"

inline void Game::run()
{ 
	while (window.isOpen())
	{ 
		assert(!states.empty());
		update();
		render();
	}
}