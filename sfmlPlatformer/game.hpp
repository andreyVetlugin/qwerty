#pragma once
//#include "state.hpp"
#include <SFML/Graphics.hpp>
#include "animation_handler.hpp"
#include <map>
#include <stack>

//#include "player.hpp"
class State;
class Game {
public:	
	sf::RenderWindow& window;
	std::map<std::string, Animation> animationList;
	
	//State *currentState;
	//вектор объектов разного типа.. 

	Game(sf::RenderWindow& win):window(win)
	{
		//currentState = new State(*this);
		LoadAnimations();
	}
	std::stack<State*> gameStates;
	void PushState(State*);
	//State& PopState();
	
	void GameLoop();
	void LoadAnimations();

};
