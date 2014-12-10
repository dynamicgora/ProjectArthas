/************************************************************************/
/*
CLASS			: MonsterDevil
Author			: �輺��
����				: DevilMonster class
���� ��������		: 2014-12-09
���� ������		:
���� ��������		:
Comment			: DevilMonster ���� ����.
*/
/************************************************************************/
#pragma once
#include "Creature.h"
#include "Util.h"

class MonsterDevil : public Creature
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
	virtual void					updateFSM(float dTime);
	virtual void					updateRender(float dTime);
	virtual void					enter();
	virtual void					exit();

	void							move();
	void							attack();

	void							idleTransition();
	void							moveTransition();
	void							attackTransition();



private:

};