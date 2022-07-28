#include "ButtonCmd.h"



ButtonCmd::ButtonCmd(const unsigned& id, sf::Vector2f pos, AnimationVec vec, ActivationFunc cmd, const string& name)
	:Button(id,pos,vec,name), m_cmd(cmd)
{
}

void ButtonCmd::activate()
{
	m_cmd(m_id);
}
