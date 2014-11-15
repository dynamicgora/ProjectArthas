/************************************************************************/
/*
CLASS			: MonsterStandShot
Author			: 김성연
역할				: 제자리서서 공격하는 몬스터
최종 수정일자		: 2014-11-15
최종 수정자		:
최종 수정사유		:
Comment			: 추가할 때 initMonster 필수 
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