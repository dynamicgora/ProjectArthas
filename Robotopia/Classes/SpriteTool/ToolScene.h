/************************************************************************/
/*
CLASS			: SpriteToolScene
Author			: �輺��
����				: Sprite�� ������ �� �� �ִ� Scene
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

class ToolLayer;
class ToolScene : cocos2d::Layer
{
public:
	static cocos2d::Scene*	    createScene();
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);

	CREATE_FUNC(ToolScene);

private:
	enum ZOrder
	{
		BACKGROUND,
		TOOLLAYER,
		UILAYER,
	};
	void						setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);
	cocos2d::PhysicsWorld*		m_PhysicsWorld;
	ToolLayer*					m_ToolLayer;

};

END_NS_AT