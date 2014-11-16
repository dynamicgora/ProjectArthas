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



class BaseComponent;
class MonsterStandShotAI : public AICommand
{
public:

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	
	void						initAI(BaseComponent* ref, float coolTime = 5, int attackNum = 2);

	CREATE_FUNC(MonsterStandShotAI);

private:
	BaseComponent*		m_Ref;
	float			m_CoolTime;
	int				m_AttackNum;
	bool			m_IsAttackState;
};

