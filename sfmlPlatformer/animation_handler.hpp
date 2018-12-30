#pragma once

#include <SFMl/Graphics.hpp>
#include <vector>
#include <map>
#include <iostream>
#include <conio.h>

class Animation{
public :

	float delayForAnimationTick;
	float currentAnimationTime;

	sf::Texture tileAtlas;
	//std::map<std::string, std::vector<sf::IntRect>> animationsList;
	int currentFrame;
	std::string currentAnimation;
	int countOfFramesInAnimation;
	std::map<std::string, std::vector<sf::Sprite>> animationsSpriteList;

	sf::View gameView; //!!!!!!!
	sf::View guiView; //!!!!!!!


	sf::IntRect frameSize;

	Animation(sf::Texture tileAtlas, std::map<std::string, std::vector<sf::IntRect>> animationsList,float delay):tileAtlas(tileAtlas){			
		currentAnimation="runLeft";
		this->delayForAnimationTick = delay;		
		this->tileAtlas=tileAtlas;
		currentFrame = 0;		
		
		for (auto a : animationsList)
			for (int i = 0; i < a.second.size(); i++)
			{		
				animationsSpriteList[a.first].push_back(sf::Sprite(this->tileAtlas,a.second[i]));
			}
	}

	virtual void Update(const float time);
	virtual void ChangeCurrentAnimation(std::string animationName);
	virtual sf::Sprite& GetRefToCurrentSprite();
};