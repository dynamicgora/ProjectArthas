﻿	/************************************************************************/
/*
CLASS			: Player
Author			: 김연우
역할				: Player class
최종 수정일자	: 2014-10-29
최종 수정자		:
최종 수정사유	:
Comment			: Player 동작 정의.
*/
/************************************************************************/
#pragma once
#include "Thing.h"
#include "Util.h"


class CommonInfo;
class Player : public Thing
{
public:
	enum State
	{
		STAT_IDLE,
		STAT_MOVE,
		STAT_JUMP,
		STAT_JUMP_DOWN,
		STAT_FLY,
		STAT_NUM,
	};

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC( Player );

	OVERRIDE bool				onContactBegin(cocos2d::PhysicsContact& contact);
	OVERRIDE void				onContactSeparate(cocos2d::PhysicsContact& contact);

	//FSM
	static void					move(Thing* target, double dTime, int idx);
	static void					jump(Thing* target, double dTime, int idx);
	static void					fly(Thing* target, double dTime, int idx);

	static void					enterMove(Thing* target, double dTime, Direction dir);
	static void					exitMove(Thing* target, double dTime);

	static void					enterJump(Thing* target, double dTime, bool isFall);
	static void					enterDownJump(Thing* target, double dTime);

	static void					idleTransition(Thing* target, double dTime, int idx);
	static void					idleTransitionInEagle(Thing* target, double dTime, int idx);
	static void					moveTransition(Thing* target, double dTime, int idx);
	static void					jumpTransition(Thing* target, double dTime, int idx);
	static void					downJumpTransition(Thing* target, double dTime, int idx);
	static void					flyTransition(Thing* target, double dTime, int idx);

	//get,set 함수
	const PlayerInfo&			getInfo() const;
	void						setDirection(Direction dir);

protected:
	PlayerInfo						m_Info;
	int								m_FSMNum;
};

