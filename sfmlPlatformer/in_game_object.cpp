#pragma once
#include "in_game_object.hpp"

void GameObject::Update(const float time)
{
}

bool GameObject::Intersection(GameObject& obj)
{
	for (auto line1 : this->hitBoxLines)
		for (auto line2 : obj.hitBoxLines)
			if (line1.intersection(line2))
				return true;
	return false;
}