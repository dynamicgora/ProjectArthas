/************************************************************************/
/*
CLASS			: RenderMissilePlayerMelee
Author			: �輺��
����				: Player Melee Missile �׷���
���� ��������		: 2014-11-12
���� ������		:
���� ��������		:
Comment			: PlayerRender�� � ����� ���� ���ؾ� �˴ϴ�.
*/
/************************************************************************/

#pragma once
#include "RenderComponent.h"

BEGIN_NS_AT

class RenderMissilePlayerMelee : public RenderComponent
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initRender();

	CREATE_FUNC(RenderMissilePlayerMelee);
private:

};

END_NS_AT

