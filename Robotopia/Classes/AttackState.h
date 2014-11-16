/************************************************************************/
/*
CLASS			: AttackState
Author			: �輺��
����				: ���� ���¿� �ش��ϴ� Ŭ����.
���� ��������	: 2014-11-07
���� ������		:
���� ��������	:
Comment			: ��� �θ�Ŭ������ �� �긦 ��ӹ޴� �ڽ� Ŭ�������� melee��簡
				  ���Ÿ���簡 �����ߵ�
*/
/************************************************************************/
#pragma once
#include "StateComponent.h"
#include "cocos2d.h"



class AttackState : public StateComponent
{
public:
	OVERRIDE bool	init();
	OVERRIDE void	enter();
	OVERRIDE void	exit();
	OVERRIDE void	update(float dTime);

	void			setAttribute(BaseComponent* ref, float preDelay, float afterDelay, 
								 ComponentType missleType, int attackPoint);
	CREATE_FUNC(AttackState);

private:
	ComponentType	m_MissileType;
	timeval			m_InitTime;
	float			m_PreDelay;
	float			m_AfterDelay;
	int				m_AttackPoint;
	bool			m_IsAttacked;
};

