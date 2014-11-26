﻿/************************************************************************/
/*
CLASS			: RushMonster
Author			: 김연우
역할				: RushMonster class
최종 수정일자	: 2014-11-22
최종 수정자		:
최종 수정사유	:
Comment			: RushMonster 동작 정의.
*/
/************************************************************************/
#pragma once
#include "Thing.h"
#include "Util.h"

#define RUSH_WIDTH 60
#define RUSH_HEIGHT 50

class CommonInfo;
class MonsterRush : public Thing
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

	bool						onContactBegin(cocos2d::PhysicsContact& contact);
	void						onContactSeparate(cocos2d::PhysicsContact& contact);
	cocos2d::PhysicsBody*		getBody();

	//FSM
	static void					move(Thing* target, double dTime, int idx);
	static void					rush(Thing* target, double dTime, int idx);

	static void					enterMove(Thing* target, double dTime, Direction dir);
	static void					exitMove(Thing* target, double dTime);

	static void					idleTransition(Thing* target, double dTime, int idx);
	static void					moveTransition(Thing* target, double dTime, int idx);

	const PlayerInfo&			getInfo();
	void						setDirection(Direction dir);
	bool						isStepForwardable();
	
protected:
	PlayerInfo					m_Info;
};
