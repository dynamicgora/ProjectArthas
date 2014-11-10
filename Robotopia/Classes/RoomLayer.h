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
	void							makeTiles();
	void							setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);
	cocos2d::Rect					getRoomRect();
	RoomData						getRoomData();
	bool							isOutOfRoom(cocos2d::Point pos);
	void							setRoomPhysics(bool enable);
	void							roomSwitch(bool isON);
	CREATE_FUNC(RoomLayer);

private:

	void							makeTilesHorizontal(int yIdx);
	void							makeTilesVertical(int xIdx);
	bool							isHorizontalTile(int xIdx, int yIdx);
	bool							isVerticalTile(int xIdx, int yIdx);
	bool							isAvailableIndex(int xIdx, int yIdx);
	Arthas::ComponentType			getTypeByIndex(int xIdx, int yIdx);
	void							addTile(cocos2d::Point origin, cocos2d::Size physicalSize,
											cocos2d::Size spriteSize, ComponentType type);

	cocos2d::Size					m_TileSize;
	cocos2d::Rect					m_RoomRect;
	cocos2d::PhysicsWorld*			m_PhysicsWorld;
	RoomData						m_RoomData;
	std::vector<Component*>			m_Objects;

	enum ZOrder
	{
		BACKGROUND,
		LAND_OBJECT,
		GAME_OBJECT,
		EFFECT,
	};
};

END_NS_AT