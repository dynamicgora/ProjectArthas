/************************************************************************/
/*
CLASS			: MonsterStandAttackFSM
Author			: �輺��
����				: MonsterStandAttack�Դϴ�
���� ��������		: 2014-11-16
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "FSMComponent.h"



class MonsterStandAttackFSM : public FSMComponent
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE void				update(float dTime);
	void						initFSM();

	CREATE_FUNC(MonsterStandAttackFSM);
private:


};

