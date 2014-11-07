/************************************************************************/
/*
CLASS			: SpriteToolScene
Author			: �輺��
����				: SpirteTool���� layer�� ��� scene
���� ��������		: 2014-11-03
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "cocos2d.h"
#include "Util.h"

BEGIN_NS_AT

class ToolScene : cocos2d::Scene
{
public:
	static cocos2d::Scene*	    createScene();
	OVERRIDE bool				init();

	CREATE_FUNC(ToolScene);

private:
	enum ZOrder
	{
		SPRITE_LIST_LAYER,
		SPRITE_EDIT_LAYER,
		
	};

};

END_NS_AT