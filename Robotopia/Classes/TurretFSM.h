/************************************************************************/
/*
CLASS			: TurretFSM
Author			: �輺��
����				: �� �ڸ����� �����ϴ� Turret�� FSM
���� ��������		: 2014-11-07
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/

#pragma once
#include "FSMComponent.h"
#include "cocos2d.h"



class TurretFSM : public FSMComponent
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						initTurretFSM();


	CREATE_FUNC(TurretFSM);
private:
};


