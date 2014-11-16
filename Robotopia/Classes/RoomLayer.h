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



class Block;
class RoomLayer : public cocos2d::Layer
{
public:
	OVERRIDE bool					init();
	OVERRIDE void					update(float dTime);
	void							initRoom(const RoomData& mData);
	bool							addObject(BaseComponent* object, cocos2d::Point position, RoomZOrder zOrder);
	void							setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld);
	cocos2d::Rect					getRoomRect();
	RoomData						getRoomData();
	bool							isOutOfRoom(cocos2d::Point pos);
	void							roomSwitch(bool isON);

	CREATE_FUNC(RoomLayer);

private:
	void							makeUnionBodies();
	void							makeTiles();
	void							makeSprites();
	void							makeTilesHorizontal(int yIdx);
	void							makeTilesVertical(int xIdx);
	bool							isHorizontalTile(int xIdx, int yIdx);
	bool							isVerticalTile(int xIdx, int yIdx);
	bool							isAvailableIndex(int xIdx, int yIdx);
	ComponentType			getTypeByIndex(int xIdx, int yIdx);
	void							addTile(cocos2d::Rect tileRect, ComponentType type);
	void							addSprite(ResourceType type, cocos2d::Point position);

	cocos2d::Size					m_TileSize;
	cocos2d::Rect					m_RoomRect;
	cocos2d::PhysicsWorld*			m_PhysicsWorld;
	RoomData						m_RoomData;
	std::vector<BaseComponent*>			m_Objects;
	Block*							m_Block;
};

