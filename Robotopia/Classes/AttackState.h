/************************************************************************/
/*
CLASS			: AttackState
Author			: �輺��
����				: ���� ���¿� �ش��ϴ� Ŭ����.
���� ��������		: 2014-11-07
���� ������		:
���� ��������		:
Comment			: ��� �θ�Ŭ������ �� �긦 ��ӹ޴� �ڽ� Ŭ�������� melee��簡
				  ���Ÿ���簡 �����ߵ�
*/
/************************************************************************/
#pragma once
#include "StateComponent.h"
#include "cocos2d.h"

BEGIN_NS_AT

class AttackState : public StateComponent
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();
	OVERRIDE void update(float dTime);

	void		  setAttribute(Component* ref, float preDelay, float afterDelay);

private:
	float		m_PreDelay;
	float		m_AfterDelay;
	bool		m_IsAttacked;
	timeval		m_InitTime;
};

END_NS_AT