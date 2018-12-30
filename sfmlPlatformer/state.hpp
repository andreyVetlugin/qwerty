#pragma once
#include "game.hpp"
//class Game;
class State {
public :
	Game game;
	State(Game game):game(game)
	{
	}
	//State() 
	//{
	//}
	virtual void Update(const float time)=0;
	virtual void Draw()=0;//dt?
	virtual void HandleInput()=0;

};