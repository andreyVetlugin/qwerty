#pragma once
#include "state.hpp"
#include <SFML/Graphics.hpp>
#include <stack>

#include "player.hpp"
#include "in_game_object.hpp"

class InGameState :public State{
	
private:
	std::map<std::string, Animation> animationList;
	Player player;
	
public:
	std::vector<GameObject> objects;
	InGameState(Game game, std::map<std::string, Animation> animationList) :State(game), animationList(animationList),player(Player(game,(&animationList.at("player"))))
	{
		return;
	}

	void Update(const float time) override;
	void Draw() override;
	void HandleInput()override;
	//std::stack<gameStates>states;
	//sf::RenderWindow window;
	//std::map<std::string, Animation> Animations;//?/???
	
	/*void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);*/
};