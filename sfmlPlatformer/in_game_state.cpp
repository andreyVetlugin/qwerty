#pragma once
#include "state.hpp"
#include  "in_game_state.hpp"


void InGameState::Update(const float time)
{
	//this->HandleInput();
	player.Update(time);
	//for (auto object : objects)
	//{
	//	object.Update(time);
	//	if (object.Intersection(player))
	//		//player getDamage
	//		//player.die// endgame
	//		game.window.close();
	//}
}

void InGameState::HandleInput()
{
	//player.HandleInput();
}

void InGameState::Draw()
{
	player.Draw();
	/*for (auto object : objects)
	{
		game.window.draw(object.body);
	}*/
}