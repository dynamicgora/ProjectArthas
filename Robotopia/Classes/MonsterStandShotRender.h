/************************************************************************/
/*
CLASS			: MonsgerStandShotRender
Author			: �輺��
����				: 
���� ��������		: 2014-11-15
���� ������		:
���� ��������		:
Comment			: 
*/
/************************************************************************/

#pragma once
#include "RenderComponent.h"
#include "cocos2d.h"

BEGIN_NS_AT

class MonsterStandShotRender : public RenderComponent
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initRender();

	CREATE_FUNC(MonsterStandShotRender);
private:

};

END_NS_AT