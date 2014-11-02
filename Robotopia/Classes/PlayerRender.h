/************************************************************************/
/*
CLASS			: PlayerRender
Author			: �輺��
����				: Player�� �׸� �� �ִ� Transition ��� ������ �ְ� �׷���
���� ��������		: 2014-10-31
���� ������		:
���� ��������		:
Comment			: PlayerRender�� � ����� ���� ���ؾ� �˴ϴ�. 
*/
/************************************************************************/

#pragma once
#include "RenderComponent.h"
#include "cocos2d.h"

BEGIN_NS_AT

class PlayerRender : public RenderComponent
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();
	
	OVERRIDE bool initRender();
	
	CREATE_FUNC(PlayerRender);
private:

};

END_NS_AT
