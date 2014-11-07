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
	setPosition(cocos2d::Point(roomData.x, roomData.y));
	makeTiles(roomData);

	//test
	auto movingBlock = Arthas::MovingBlock::create();
	movingBlock->initTile(roomData.width / 3, roomData.height / 3, roomData.width / 3, m_TileSize.height);
	addChild(movingBlock);
}

void Arthas::RoomLayer::makeTiles(const RoomData& roomData)
{
	int maxXIdx = roomData.width / m_TileSize.width;
	int maxYIdx = roomData.height / m_TileSize.height;
	//sentinel ����
	for(int yIdx = 1; yIdx < maxYIdx - 1; ++yIdx)
	{
		makeTilesHorizontal(roomData, yIdx, maxXIdx, maxYIdx);
	}

	for(int xIdx = 1; xIdx < maxXIdx - 1; ++xIdx)
	{
		makeTilesVertical(roomData, xIdx, maxXIdx, maxYIdx);
	}
}


//���η� ����� Ÿ�� ����
void Arthas::RoomLayer::makeTilesHorizontal(const RoomData& roomData, int yIdx, int maxXIdx, int maxYIdx)
{
	//rect�� ����ڿ� �� rect�� �´� Ÿ���� ����� ���·� ����
	cocos2d::Rect rect(0, yIdx*m_TileSize.height, 0, m_TileSize.height);
	bool isNewTile = true; //���ӵ� Ÿ���� ���⶧ ���� Ÿ���� �����ϴ� �÷��׷� �ؾ��� ���� �����Ѵ�.
	for(int xIdx = 0; xIdx < maxXIdx; ++xIdx)
	{
		//�ϴ� ���� Ÿ���� ������ Ÿ���̶��
		if(isHorizontalTile(roomData, xIdx, yIdx, maxXIdx, maxYIdx))
		{
			//���� ���鶧 ���� ��ġ, rect�� origin���� �������ش�.
			if(isNewTile)
			{
				isNewTile = false;
				rect.origin.x = xIdx*m_TileSize.width;
			}
			//���� ����� �ƴϴ� rect�� ����� Ÿ�� �Ѱ� �����ŭ �÷��ش�.
			rect.size.width += m_TileSize.width;
		}
		//�츮�� ���� Ÿ���� �ƴϸ�
		else
		{
			//Ÿ�� ����� �ִ� ���°� �ƴ϶��
			if(isNewTile)
			{
				//rect ��� �ʱ�ȭ
				rect.size.width = 0;
				rect.origin.x = 0;
			}
			//Ÿ���� ����� �־��ٸ�
			else
			{
				//���ݱ��� ���� Rect�� Ÿ�� �߰�
				isNewTile = true;
				addTile(rect);
			}
		}
	}
}

//���η� ����� Ÿ�� ������ ���ϵ���
void Arthas::RoomLayer::makeTilesVertical(const RoomData& roomData, int xIdx, int maxXIdx, int maxYIdx)
{
	cocos2d::Rect rect(xIdx*m_TileSize.width, 0, m_TileSize.width, 0);
	bool isNewTile = true;
	for(int yIdx = 0; yIdx < maxYIdx; ++yIdx)
	{
		if(isVerticalTile(roomData, xIdx, yIdx, maxXIdx, maxYIdx))
		{
			if(isNewTile)
			{
				isNewTile = false;
				rect.origin.y = yIdx*m_TileSize.height;
			}
			rect.size.height += m_TileSize.height;
		}
		else
		{
			if(isNewTile)
			{
				rect.size.height = 0;
				rect.origin.y = 0;
			}
			else
			{
				isNewTile = true;
				addTile(rect);
			}
		}
	}
}

void Arthas::RoomLayer::setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld)
{
	m_PhysicsWorld = physicsWorld;
}

bool Arthas::RoomLayer::isHorizontalTile(const RoomData& roomData, int xIdx, int yIdx, int maxXIdx, int maxYIdx)
{
	bool ret = false;
	int maxContainerIdx = (signed) roomData.data.size() - 1;
	if(yIdx * maxXIdx + xIdx < maxContainerIdx && //boundary check
	   roomData.data[yIdx * maxXIdx + xIdx] > 0) //���� �����Ͱ� Ÿ��
	{
		if(( yIdx - 1 ) * maxXIdx + xIdx < maxContainerIdx && //boundary check
		   ( yIdx + 1 ) * maxXIdx + xIdx < maxContainerIdx && //boundary check
		   ( roomData.data[( yIdx + 1 )*maxXIdx + xIdx] == 0 || //��ĭ �����Ͱ� ��ĭ
		   roomData.data[( yIdx - 1 )*maxXIdx + xIdx] == 0 )) //�Ʒ�ĭ �����Ͱ� ��ĭ
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
	if(yIdx * maxXIdx + xIdx < maxContainerIdx && //boundary check
	   roomData.data[yIdx * maxXIdx + xIdx] > 0) //���� �����Ͱ� Ÿ��
	{ 
		if(!isHorizontalTile(roomData, xIdx, yIdx, maxXIdx, maxYIdx) && //Horizontal�� ��ġġ ���� ��
		   yIdx * maxXIdx + xIdx + 1 < maxContainerIdx && //boundary check
		   yIdx * maxXIdx + xIdx - 1 < maxContainerIdx && //boundary check
		   ( roomData.data[yIdx * maxXIdx + xIdx + 1] == 0 || //������ ĭ �����Ͱ� ��ĭ
		   roomData.data[( yIdx - 1 )*maxXIdx + xIdx] == 0 )) //���� ĭ �����Ͱ� ��ĭ
		{
			ret = true;
		}
	}
	return ret;
}

void Arthas::RoomLayer::addTile(const cocos2d::Rect& rect)
{
	auto newTile = GET_COMPONENT_MANAGER()->createComponent<Block>();
	addChild(newTile);
	newTile->initTile(rect);
}

