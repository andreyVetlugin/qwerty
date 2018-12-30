#pragma once
#include "animation_handler.hpp"



void Animation::Update(float time) {
	std::cout << time;
	std::cout << "  ";
	this->currentAnimationTime += time;
	std::cout << currentAnimationTime;
	std::cout << std::endl;
	if (this->currentAnimationTime < delayForAnimationTick)
		return;
	if (currentFrame >= countOfFramesInAnimation - 1)
		this->currentFrame = 0;
	else
		currentFrame++;
	currentAnimationTime = 0;
}

void Animation::ChangeCurrentAnimation(std::string animationName) {
	currentAnimation = animationName;
	currentFrame = 0;
	countOfFramesInAnimation = animationsSpriteList[currentAnimation].size();
}

sf::Sprite& Animation::GetRefToCurrentSprite() {
	return animationsSpriteList[currentAnimation][currentFrame];
}
