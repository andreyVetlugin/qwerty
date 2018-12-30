#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
#include "line.hpp"
class GameObject
{	public: 
	//virtual void Draw();
	virtual void Update(const float time)=0;
	GameObject()
	{
		
	}
	sf::Vector2f center;
	sf::ConvexShape hitBox;
	std::vector<Line> hitBoxLines;
	sf::RectangleShape body;
	bool Intersection(GameObject&);
};
