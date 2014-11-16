/************************************************************************/
/*
CLASS			: MonsterStandShotAI
Author			: �輺��
����				: �׸��� �����ٲ��� ������ �������� �����ϴ� AI
���� ��������		: 2014-11-16
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "AICommand.h"

BEGIN_NS_AT

class Component;
class MonsterStandShotAI : public AICommand
{
public:

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	
	void						initAI(Component* ref, float coolTime = 5, int attackNum = 2);

	CREATE_FUNC(MonsterStandShotAI);

private:
	Component*		m_Ref;
	float			m_CoolTime;
	int				m_AttackNum;
	bool			m_IsAttackState;
};

END_NS_AT