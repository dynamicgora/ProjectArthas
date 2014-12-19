/************************************************************************/
/*
CLASS			: BossFirst
Author			: �迬��
����				: ù��° ���� class
���� ��������		: 2014-12-19
���� ������		:
���� ��������		:
Comment			: ���ۺ��� ���ư��� ������ô�.
*/
/************************************************************************/
#pragma once
#include "Creature.h"
#include "Util.h"
#define HEAD_RADIUS 64
class AnimationComponent;
class BossFirst : public Creature
{
public:
	enum State
	{
		STAT_IDLE,
		STAT_MOVE,
		STAT_ATTACK,
		STAT_NUM,
	};

	virtual bool					init();
	virtual void					update(float dTime);
	virtual void					enter();
	virtual void					exit();
	virtual void					dead();

	virtual const AllStatus&		getInfo() const;

	void							move(Creature* target, double dTime, int idx);
	void							enterMove();
	void							exitMove();

	void							attack(Creature* target, double dTime, int idx);
	void							enterAttack();
	void							exitAttack();

	void							idleTransition(Creature* target, double dTime, int idx);
	void							moveTransition(Creature* target, double dTime, int idx);
	void							attackTransition(Creature* target, double dTime, int idx);

	virtual bool					onContactBegin(cocos2d::PhysicsContact& contact);
	virtual void					onContactSeparate(cocos2d::PhysicsContact& contact);

	CREATE_FUNC(BossFirst);

private:
	int							m_Mode;
	AllStatus					m_Info;
	bool						m_IsArrived = false;
	BaseComponent*				m_Head;
};