#pragma once
#include "animation_handler.hpp"
#include <iostream>
#include <windows.h>
#include "game.hpp"
#include "state.hpp"
#include "in_game_state.hpp"

int main() 
{
	sf::RenderWindow win(sf::VideoMode(900,640),"How long u can stay alive?");

	Game game(win);
	game.PushState(&InGameState(game,game.animationList));
	game.GameLoop();
}