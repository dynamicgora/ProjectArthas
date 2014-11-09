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
#define PLAYER_TAG 12

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
	void							shakeRooms( const StageData& data );
	void							setPhysicsWorld( cocos2d::PhysicsWorld* physicsWorld );

	const Player*					getPlayer();
	int								getCurrentRoomNum();
	RoomLayer*						getRoomLayer(int roomNum);
	void							ChangeRoom(int roomNum, cocos2d::Point pos);

	CREATE_FUNC( GameLayer );

private:
	cocos2d::PhysicsWorld*		m_PhysicsWorld;
	RoomLayer*					m_RoomLayers[MAX_ROOM_LAYER_NUM];
	Player*						m_Player;
	int							m_CurrentRoomNum;
	int							m_RoomCount;
};

END_NS_AT