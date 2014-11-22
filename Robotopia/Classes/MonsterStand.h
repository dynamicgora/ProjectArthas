/************************************************************************/
/*
CLASS			: MonsterStand
Author			: �輺��
����				: ���� �����ϴ� ���� Ŭ���� 
���� ��������		: 2014-11-22
���� ������		:
���� ��������		:
Comment			: 
*/
/************************************************************************/
#pragma once
#include "Thing.h"
#include "Util.h"

class MonsterStand : public Thing
{
public:
	enum State
	{
		STAT_IDLE,
		STAT_ATTACK,
		STAT_NUM,
	};

	struct MonsterStandInfo
	{
		float				coolTime;
		int					repeatAttackNum;
		Direction			dir;
		int					damage;
		int					maxHp;
		int					curHp;
		ComponentType		missileType;
	};

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);
	OVERRIDE void			enter();
	OVERRIDE void			exit();

	CREATE_FUNC(MonsterStand);

	bool						onContactBegin(cocos2d::PhysicsContact& contact);
	void						onContactSeparate(cocos2d::PhysicsContact& contact);
	cocos2d::PhysicsBody*		getBody();

	//FSM
	static void				attack(Thing* target, double dTime, int idx);
	static void				enterAttack(Thing* target, double dTime, int idx);
	static void				exitAttack(Thing* target, double dTime, int idx);

	static void				idleTransition(Thing* target, double dTime, int idx);
	static void				attackTransition(Thing* target, double dTime, int idx);
	MonsterStandInfo&		getInfo();
	void					setInfo(float coolTime = 5, int repeatAttackNum = 2, Direction dir = DIR_RIGHT,
									int damage = 20, int maxHp = 100, int curHp = 100, 
									ComponentType missileType = OT_MISSILE_PLAYER_LINEAR );

private:
	cocos2d::PhysicsBody*		m_Body = nullptr;
	MonsterStandInfo			m_Info;
	int							m_CurAttackNum;
};