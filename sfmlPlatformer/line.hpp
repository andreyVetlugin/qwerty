#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Line 
{public:
	

	//std::vector<sf::Vector2f> points;
	Line(float x1, float y1, float x2, float y2)
	{
		A = { x1,y1 };
		B = { x2,y2 };
	}

	Line(sf::Vector2f a, sf::Vector2f b)
	{
		this->A = a;
		this->B = b;
	}


	sf::Vector2f A;
	sf::Vector2f B;	
	bool intersection(Line line)
	{
		if (this->getVectorDirectionAfterVectorMultiplication(Line(this->A, line.A)) !=
			this->getVectorDirectionAfterVectorMultiplication(Line(this->A, line.B)))
			if (this->getVectorDirectionAfterVectorMultiplication(Line(line.B, this->A)) !=
				this->getVectorDirectionAfterVectorMultiplication(Line(line.B, this->B)))
				return true;
		return false;
	}

private :
	int getVectorDirectionAfterVectorMultiplication(Line line) 
	{
		sf::Vector2f first = this->B -this->A;
		sf::Vector2f second = line.B - line.A;
		
		if((first.x*second.y - first.y*second.x )> 0)
			return 1;
		return 0;
	}
};