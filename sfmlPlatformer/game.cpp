#pragma once
#include "game.hpp"
#include "state.hpp"

void Game::GameLoop()
{
	State* state = gameStates.top();
	while (window.isOpen())
	{
		//sf::Event event;
		sf::Clock timer;
		auto time = timer.restart();
		state->Update(time.asMilliseconds());
		state->Draw();
	}	
}

void Game::LoadAnimations(){
	using namespace std;
	sf::Texture textureForPlayer;
	textureForPlayer.loadFromFile("resources/player_sprite.png");
	map<string, vector<sf::IntRect>> animForPlayer = { { "runDown",{ std::vector<sf::IntRect>{ sf::IntRect(1,1,32,32), sf::IntRect(34,1,32,32) ,
		sf::IntRect(68,1,32,32),sf::IntRect(100,1,32,32),sf::IntRect(134,1,32,32)} } } };

	animForPlayer["runUp"] = std::vector<sf::IntRect>{ sf::IntRect(1,34,32,32), sf::IntRect(34,34,32,32) ,
		sf::IntRect(68,34,32,32),sf::IntRect(100,34,32,32),sf::IntRect(134,34,32,32) };

	animForPlayer["runRight"] = std::vector<sf::IntRect>{ sf::IntRect(1,68,32,32), sf::IntRect(34,68,32,32) ,
		sf::IntRect(68,68,32,32),sf::IntRect(100,68,32,32),sf::IntRect(134,68,32,32) };

	animForPlayer["runLeft"] = std::vector<sf::IntRect>{ sf::IntRect(1,100,32,32), sf::IntRect(34,100,32,32) ,
		sf::IntRect(68,100,32,32),sf::IntRect(100,100,32,32),sf::IntRect(134,100,32,32) };
}

void Game::PushState(State* state)
{
	gameStates.push(state);
}