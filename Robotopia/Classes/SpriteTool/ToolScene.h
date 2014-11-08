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

class ToolSpriteEditLayer;
class ToolAniPlayLayer;
class ToolScene : cocos2d::Scene
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);

	static cocos2d::Scene*	    createScene();
	CREATE_FUNC(ToolScene);

	enum LayerType
	{
		SPRITE_EDIT_LAYER,
		ANI_PLAY_LAYER,
	};

private:
	ToolSpriteEditLayer* m_EditLayer;
	ToolAniPlayLayer*	 m_AniLayer;

};

END_NS_AT