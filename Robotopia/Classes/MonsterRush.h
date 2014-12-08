/************************************************************************/
/*
CLASS			: RushMonster
Author			: �迬��
����				: RushMonster class
���� ��������	: 2014-11-22
���� ������		:
���� ��������	:
Comment			: RushMonster ���� ����.
*/
/************************************************************************/
#pragma once
#include "Creature.h"
#include "Util.h"

#define RUSH_WIDTH 60
#define RUSH_HEIGHT 50

class CommonInfo;
class MonsterRush : public Creature
{
public:
	enum State
	{
		STAT_IDLE,
		STAT_MOVE,
		STAT_NUM,
	};

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC(MonsterRush);

	virtual bool				onContactBegin(cocos2d::PhysicsContact& contact);
	virtual void				onContactSeparate(cocos2d::PhysicsContact& contact);
	cocos2d::PhysicsBody*		getBody();

	//FSM
	static void					move(Creature* target, double dTime, int idx);
	static void					rush(Creature* target, double dTime, int idx);

	static void					enterMove(Creature* target, double dTime, Direction dir);
	static void					exitMove(Creature* target, double dTime);

	static void					idleTransition(Creature* target, double dTime, int idx);
	static void					moveTransition(Creature* target, double dTime, int idx);

	virtual const AllStatus&	getInfo() const;
	void						setDirection(Direction dir);
	bool						isStepForwardable();

protected:
	AllStatus				m_Info;
};
