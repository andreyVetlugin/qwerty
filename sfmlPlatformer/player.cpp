#pragma once
#include "player.hpp"


 void Player::Update(const float time) 
 {
	sf::Event event;
	while (game.window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			sf::Vector2f oldPosition = sf::Vector2f(body.getPosition().x, body.getPosition().y);
			switch (event.key.code)
			{//проверять итеракцию в game брать типы обхектов
				
			case sf::Keyboard::Up:				
				if (keyIsPressed) playerAnimationList->ChangeCurrentAnimation("runUp");
				//body.top -= time * moveSpeed;
				body.setPosition(oldPosition.x, oldPosition.y - time * moveSpeed);
				break;
			case sf::Keyboard::Down:
				if (keyIsPressed) playerAnimationList->ChangeCurrentAnimation("runDown");
				body.setPosition(oldPosition.x, oldPosition.y + time * moveSpeed);
				break;
			case sf::Keyboard::Right:
				if (keyIsPressed) playerAnimationList->ChangeCurrentAnimation("runRight");
				body.setPosition(oldPosition.x+time*moveSpeed, oldPosition.y );
				break;
			case sf::Keyboard::Left:
				if (keyIsPressed) playerAnimationList->ChangeCurrentAnimation("runLeft");
				body.setPosition(oldPosition.x - time*moveSpeed, oldPosition.y);
				break;
			playerAnimationList->Update(time);
			}			
		}
		else if (event.type == sf::Event::KeyReleased)
		{	
			keyIsPressed = false;
			playerAnimationList->ChangeCurrentAnimation("runDown");			
			rotation = Rotation::DOWN;
		}
		return;
	}
	playerAnimationList->ChangeCurrentAnimation("runDown");
	//playerAnimationList.Update(time);
}
 void Player::Draw()
 {
	 //playerAnimationList.ChangeCurrentAnimation("runDown");
	 sf::Sprite playerSprite = playerAnimationList->GetRefToCurrentSprite();
	 playerSprite.setPosition(body.getPosition());
	 game.window.draw(playerSprite);
 }