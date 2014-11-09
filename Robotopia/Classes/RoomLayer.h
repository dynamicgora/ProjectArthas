/************************************************************************/
/*
	CLASS			: RoomLayer
	Author			: �迬��
	����				: �ѹ濡 �ִ� ��� ������Ʈ���� �ִ� ���̾�
	���� ��������	: 2014-11-08
	���� ������		: ������
	���� ��������	: sentinel �����ϴ� �κ��� �ٲ�� �� �˰��� ���� �� �־ �� �κ� ����.
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
	OVERRIDE void					update(float dTime);
	void							initRoom(const RoomData& mData);
	void							makeTiles(const RoomData& roomData);
	void							makeTilesHorizontal(const RoomData& roomData, int yIdx, int maxXIdx, int maxYIdx);
	void							makeTilesVertical(const RoomData& roomData, int xIdx, int maxXIdx, int maxYIdx);
	bool							isHorizontalTile(const RoomData& roomData, int xIdx, int yIdx, int maxXIdx, int maxYIdx);
	bool							isVerticalTile(const RoomData& roomData, int xIdx, int yIdx, int maxXIdx, int maxYIdx);

	void							addTile(cocos2d::Point origin, cocos2d::Size physicalSize, 
											cocos2d::Size spriteSize, ComponentType type);
	void							setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);
	cocos2d::Rect					getRoomRect();
	CREATE_FUNC(RoomLayer);

private:

	enum ZOrder
	{
		BACKGROUND ,
		LAND_OBJECT ,
		GAME_OBJECT ,
		EFFECT ,
	};
	cocos2d::Size					m_TileSize;
	cocos2d::Rect					m_RoomRect;
	cocos2d::PhysicsWorld*			m_PhysicsWorld;


	bool							isAvailableIndex(int xIdx,int yIdx,int maxXIdx,int maxYIdx);
	Arthas::ComponentType			getTypeByIndex(const RoomData& roomData, int xIdx, int yIdx, int maxXIdx, int maxYIdx);
};

END_NS_AT