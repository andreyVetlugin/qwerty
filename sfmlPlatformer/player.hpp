#pragma once 
#include <SFML/graphics.hpp>
#include "animation_handler.hpp"
#include "game.hpp"
#include "in_game_object.hpp"

enum class Rotation { UP, DOWN, RIGHT,LEFT};
class Game;
class Player:public GameObject
{
public:
	Game game;
	//sf::FloatRect body;
	Animation* playerAnimationList;
	float moveSpeed;
	Rotation rotation;
	

	Player(Game game,Animation* animation):game(game)
	{		
		playerAnimationList = animation;
		body = sf::RectangleShape({32,32});
		keyIsPressed = false;
	}

	//void Draw() override ;
	//void HandleInput();
	void Update(const float time);
	virtual void Draw();

private:

	bool keyIsPressed;

};