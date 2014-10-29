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
class GameScene : public cocos2d::Scene
{
public:
	static GameScene*			createScene();
	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	void						onEnter();

	GameLayer*					getGameLayer(){return m_GameLayer;}
	UILayer*					getUILayer(){return m_UILayer;}

	CREATE_FUNC( GameScene );

private:
	enum ZOrder
	{
		BACKGROUND ,
		GAMELAYER ,
		UILAYER ,
	};

	GameLayer*			m_GameLayer;
	UILayer*			m_UILayer;
};

END_NS_AT