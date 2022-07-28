#pragma once

#include<functional>
#include "Button.h"

using ActivationFunc = std::function<void(unsigned id)>;

class ButtonCmd : public Button
{

public:
	ButtonCmd(const unsigned& id, sf::Vector2f pos , AnimationVec vec, ActivationFunc cmd ,const string& name);
	virtual ~ButtonCmd() {};
private:
	ActivationFunc m_cmd;
	virtual void activate()override;
};