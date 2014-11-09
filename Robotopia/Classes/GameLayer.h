/************************************************************************/
/*
	CLASS			: GameLayer
	Author			: �迬��
	����				: ���ӿ� ���Ǵ� ��� ������Ʈ���� �ִ� ���̾�
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: �׳� Ŭ������ ������, ������ �޾Ƽ� �뷹�̾�� ����� �ֵ����ϵ����, �÷��̾� ��ġ ������
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"
#define MAX_ROOM_LAYER_NUM 100

BEGIN_NS_AT

class Player;
class RoomLayer;
class View;
class GameLayer : public cocos2d::Layer
{
public:
	OVERRIDE bool					init();
	OVERRIDE void					update( float dTime );
	void							initGameLayer( const StageData& data );
	void							setPhysicsWorld( cocos2d::PhysicsWorld* physicsWorld );
	const Player*					getPlayer();
	CREATE_FUNC( GameLayer );

private:
	cocos2d::PhysicsWorld*		m_PhysicsWorld;
	RoomLayer*					m_RoomLayers[MAX_ROOM_LAYER_NUM];
	Player*						m_Player;
	View*						m_View;
};

END_NS_AT