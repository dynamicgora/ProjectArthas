/************************************************************************/
/*
CLASS			: MonsterStandShot
Author			: �輺��
����				: ���ڸ����� �����ϴ� ����
���� ��������		: 2014-11-15
���� ������		:
���� ��������		:
Comment			: �߰��� �� initMonster �ʼ� 
*/
/************************************************************************/
#pragma once
#include "Util.h"
#include "Monster.h"

#define MISSILECOUNT 3
BEGIN_NS_AT

class MonsterStandShot : public Monster
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);
	OVERRIDE void			enter();
	OVERRIDE void			exit();
	OVERRIDE bool			initMosnter();
	OVERRIDE void			setMonster(Direction dir, float damage, float speed, 
									   float jumpSpeed, int missileCount = MISSILECOUNT);

	CREATE_FUNC(MonsterStandShot);
private:
	int			m_TotalCoolTime;
	float       m_AttackCoolTime;
	bool		m_IsAttacking;
	int			m_MissileCount;


};

END_NS_AT