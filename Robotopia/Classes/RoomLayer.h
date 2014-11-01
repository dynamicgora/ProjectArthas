/************************************************************************/
/*
	CLASS			: RoomLayer
	Author			: �迬��
	����				: �ѹ濡 �ִ� ��� ������Ʈ���� �ִ� ���̾�
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: �׳� Ŭ������ ������
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"

BEGIN_NS_AT

class RoomLayer : public cocos2d::Layer
{
public:
	OVERRIDE bool					init();
	OVERRIDE void					update( float dTime );
	void							initRoom( const RoomData& mData );
	void							makeTilesHorizontal( const RoomData& mData, int yIdx );
	void							makeTilesVertical( const RoomData& mData, int xIdx );
	void							setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);

	CREATE_FUNC( RoomLayer );

private:

	enum ZOrder
	{
		BACKGROUND ,
		LAND_OBJECT ,
		GAME_OBJECT ,
		EFFECT ,
	};
	cocos2d::Size					m_TileSize;
	cocos2d::PhysicsWorld*			m_PhysicsWorld;

};

END_NS_AT