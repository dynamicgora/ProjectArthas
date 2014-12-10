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
	virtual bool					init();
	virtual void					update(float dTime);
	virtual void					updateFSM(float dTime);
	virtual void					updateRender(float dTime);
	virtual void					enter();
	virtual void					exit();


private:

};