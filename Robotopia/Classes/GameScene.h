/************************************************************************/
/*
	CLASS			: GameScene
	Author			: �迬��
	����				: �� ������ ��� ���̾���� ��� ��
	���� ��������	: 2014-10-29
	���� ������		: 
	���� ��������	:
	Comment			:
*/
/************************************************************************/


#pragma once
#include "cocos2d.h"
#include "Util.h"

BEGIN_NS_AT

class GameLayer;
class UILayer;
class GameScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene*	createScene();
	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );

	GameLayer*					getGameLayer();
	UILayer*					getUILayer();

	CREATE_FUNC( GameScene );

private:
	enum ZOrder
	{
		BACKGROUND,
		GAMELAYER,
		UILAYER,
	};

	void						setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);

	cocos2d::Scene*				m_Scene;
	cocos2d::PhysicsWorld*		m_PhysicsWorld;
	GameLayer*					m_GameLayer;
	UILayer*					m_UILayer;
};

END_NS_AT