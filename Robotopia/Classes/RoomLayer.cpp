#include "pch.h"
#include "RoomLayer.h"
#include "GameManager.h"
#include "DataManager.h"
#include "ComponentManager.h"
#include "Block.h"
#include "MovingBlock.h"

bool Arthas::RoomLayer::init()
{
	m_TileSize = GET_DATA_MANAGER()->getTileSize();
	return true;
}

void Arthas::RoomLayer::update(float dTime)
{

}

void Arthas::RoomLayer::initRoom(const RoomData& roomData)
{
	setPosition(cocos2d::Point(roomData.x*m_TileSize.width, roomData.y*m_TileSize.height));
	makeTiles(roomData);

	//test
	auto movingBlock = Arthas::MovingBlock::create();
	movingBlock->initTile(cocos2d::Point(roomData.width / 3, roomData.height / 3), m_TileSize , 
						  cocos2d::Size(roomData.width / 3, m_TileSize.height));

	addChild(movingBlock);
}

void Arthas::RoomLayer::makeTiles(const RoomData& roomData)
{
	int maxXIdx = roomData.width;
	int maxYIdx = roomData.height;
	//sentinel ����
	for(int yIdx = 0; yIdx < maxYIdx; ++yIdx)
	{
		makeTilesHorizontal(roomData, yIdx, maxXIdx, maxYIdx);
	}

	for(int xIdx = 0; xIdx < maxXIdx; ++xIdx)
	{
		makeTilesVertical(roomData, xIdx, maxXIdx, maxYIdx);
	}
}


//���η� ����� Ÿ�� ����
void Arthas::RoomLayer::makeTilesHorizontal(const RoomData& roomData, int yIdx, int maxXIdx, int maxYIdx)
{
	
}

//���η� ����� Ÿ�� ������ ���ϵ���
void Arthas::RoomLayer::makeTilesVertical(const RoomData& roomData, int xIdx, int maxXIdx, int maxYIdx)
{

}

void Arthas::RoomLayer::setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld)
{
	m_PhysicsWorld = physicsWorld;
}

bool Arthas::RoomLayer::isHorizontalTile(const RoomData& roomData, int xIdx, int yIdx, int maxXIdx, int maxYIdx)
{
	bool ret = false;
	int maxContainerIdx = (signed) roomData.data.size() - 1;
	if (boundaryCheck(xIdx,yIdx,maxXIdx, maxYIdx) && //boundary check
	   roomData.data[yIdx * maxXIdx + xIdx] > 0) //���� �����Ͱ� Ÿ��
	{
		//���� �Ʒ� Ÿ���� ���� �ٱ� Ÿ���� ��� ������ �� Ÿ�Ϸ� ���
		int upTile = boundaryCheck(xIdx, yIdx + 1, maxXIdx, maxYIdx) ?
						roomData.data[(yIdx + 1)*maxXIdx + xIdx] : 0;
		int downTile = boundaryCheck(xIdx, yIdx - 1, maxXIdx, maxYIdx) ?
			roomData.data[(yIdx - 1)*maxXIdx + xIdx] : 0;

		if ( upTile == 0 || //��ĭ �����Ͱ� ��ĭ
		   downTile == 0 ) //�Ʒ�ĭ �����Ͱ� ��ĭ
		{
			ret = true;
		}
	}
	return ret;
}

bool Arthas::RoomLayer::isVerticalTile(const RoomData& roomData, int xIdx, int yIdx, int maxXIdx, int maxYIdx)
{
	bool ret = false;
	int maxContainerIdx = (signed) roomData.data.size() - 1;
	if (boundaryCheck(xIdx, yIdx, maxXIdx, maxYIdx) && //boundary check
	   roomData.data[yIdx * maxXIdx + xIdx] > 0) //���� �����Ͱ� Ÿ��
	{ 
		//�����̳� ������ Ÿ���� ���� �ٱ� Ÿ���� ��� ������ �� Ÿ�Ϸ� ���
		int leftTile = boundaryCheck(xIdx - 1, yIdx, maxXIdx,maxYIdx) ?
			roomData.data[yIdx * maxXIdx + xIdx - 1] : 0;
		int rightTile = boundaryCheck(xIdx + 1, yIdx, maxXIdx,maxYIdx) ?
			roomData.data[yIdx * maxXIdx + xIdx + 1] : 0;

		if(!isHorizontalTile(roomData, xIdx, yIdx, maxXIdx, maxYIdx) && //Horizontal�� ��ġġ ���� ��
		   ( leftTile == 0 || //������ ĭ �����Ͱ� ��ĭ
		   rightTile == 0 )) //���� ĭ �����Ͱ� ��ĭ
		{
			ret = true;
		}
	}
	return ret;
}

void Arthas::RoomLayer::addTile(cocos2d::Point origin, cocos2d::Size physicalSize, cocos2d::Size spriteSize)
{
	auto newTile = GET_COMPONENT_MANAGER()->createComponent<Block>();
	addChild(newTile);
	newTile->initTile(origin, physicalSize, spriteSize);
}

bool Arthas::RoomLayer::boundaryCheck(int xIdx, int yIdx, int maxXIdx,int maxYIdx)
{
	return xIdx >=0 && xIdx < maxXIdx &&
			yIdx >= 0 && yIdx < maxYIdx;
}

