#include "pch.h"
#include "AttackState.h"
#include "GameManager.h"

bool Arthas::AttackState::init()
{
	if (!StateComponent::init())
	{
		return false;
	}
	m_IsAttacked = false;
	return true;
}

void Arthas::AttackState::enter()
{
	m_InitTime = GET_GAME_MANAGER()->getTime();
}

void Arthas::AttackState::exit()
{
}

void Arthas::AttackState::update(float dTime)
{
	long currentDelay = GET_GAME_MANAGER()->getTime().tv_sec - m_InitTime.tv_sec;
	if(currentDelay > m_PreDelay && m_IsAttacked == false)
	{
		m_IsAttacked = true;
		//�̻��� �߽�!!!!!!!!!!!!!!!
	}
	else if(currentDelay > m_AfterDelay)
	{

	}
}

void Arthas::AttackState::setAttribute(Component* ref, float preDelay, float afterDelay)
{
	m_PreDelay = preDelay;
	m_AfterDelay = afterDelay;
}
