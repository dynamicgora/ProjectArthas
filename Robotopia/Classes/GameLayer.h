/************************************************************************/
/*
	CLASS			: GameLayer
	Author			: �迬��
	����				: ���ӿ� ���Ǵ� ��� ������Ʈ���� �ִ� ���̾�
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: �׳� Ŭ������ ������
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"

class GameLayer : public cocos2d::Layer
{
public:
	static cocos2d::Scene*			createScene();

	OVERRIDE bool					init();
	OVERRIDE void					update( float dTime );

	CREATE_FUNC( GameLayer );

private:

	enum ZOrder
	{
		BACKGROUND ,
		LAND_OBJECT ,
		GAME_OBJECT ,
		EFFECT ,
	};

};

