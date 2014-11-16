#include "pch.h"
#include "RoomLayer.h"
#include "GameManager.h"
#include "DataManager.h"
#include "ComponentManager.h"
#include "ResourceManager.h"
#include "Block.h"
#include "MovingBlock.h"
#include "TurretBlock.h"
#include "Floor.h"
#include "Portal.h"
#include "PhysicsComponent.h"

bool RoomLayer::init()
{
	m_TileSize = GET_DATA_MANAGER()->getTileSize();
	m_Block = nullptr;
	return true;
}

void RoomLayer::update(float dTime)
{
	for(auto object : m_Objects)
	{
		object->update(dTime);
	}
}

void RoomLayer::initRoom(const RoomData& roomData)
{
	m_RoomData = roomData;
	m_RoomRect = cocos2d::Rect(m_RoomData.x* m_TileSize.width, m_RoomData.y* m_TileSize.height, 
							   m_RoomData.width*m_TileSize.width, m_RoomData.height*m_TileSize.height);
	setPosition(m_RoomRect.origin);
	makeTiles();
	makeSprites();
}

bool RoomLayer::addObject(BaseComponent* object, cocos2d::Point position, RoomZOrder zOrder)
{
	if(object == nullptr || isOutOfRoom(position))
	{
		return false;
	}

	addChild(object, zOrder);
	object->setPosition(position);
	m_Objects.push_back(object);
	return true;
}

void RoomLayer::makeSprites()
{
	for(int yIdx = 0; yIdx < m_RoomData.height; ++yIdx)
	{
		for(int xIdx = 0; xIdx < m_RoomData.width; ++xIdx)
		{
			ComponentType cType = m_RoomData.data[xIdx + yIdx*m_RoomData.width];
			if(cType == OT_BLOCK || cType == OT_FLOOR)
			{
				ResourceType rType = ST_START;
				cocos2d::Point position;
				position.x = xIdx * m_TileSize.width;
				position.y = yIdx * m_TileSize.height;
				switch(cType)
				{
					case OT_BLOCK:
						rType = ST_BLOCK;
						break;
					case OT_FLOOR:
						rType = ST_FLOOR;
						break;
				}
				addSprite(rType, position);
			}
		}
	}
}

void RoomLayer::makeTiles()
{
	m_Block = Block::create();
	addChild(m_Block);
	m_Objects.push_back(m_Block);
	m_Block->initTile(cocos2d::Rect::ZERO);
	m_Block->retain();

	for(int yIdx = 0; yIdx < m_RoomData.height; ++yIdx)
	{
		makeTilesHorizontal(yIdx);
	}

	for(int xIdx = 0; xIdx < m_RoomData.width; ++xIdx)
	{
		makeTilesVertical(xIdx);
	}
}


//���η� ����� Ÿ�� ����
void RoomLayer::makeTilesHorizontal(int yIdx)
{
	bool			isMaking = false;
	ComponentType	prevCompType = CT_NONE, currentCompType = CT_NONE;
	cocos2d::Rect	tileRect(0, yIdx*m_TileSize.height, 0, m_TileSize.height);

	for(int xIdx = 0; xIdx <= m_RoomData.width; ++xIdx)
	{
		prevCompType = currentCompType;
		currentCompType = getTypeByIndex(xIdx, yIdx);
		if(isHorizontalTile(xIdx, yIdx))
		{
			if(!isMaking)
			{
				isMaking = true;
				tileRect.origin.x = xIdx*m_TileSize.width;
			}
			else if(prevCompType != currentCompType)
			{
				addTile(tileRect, prevCompType);
				tileRect.origin.x = xIdx*m_TileSize.width;
				tileRect.size.width = 0;
			}
			tileRect.size.width += m_TileSize.width;
		}
		else
		{
			if(isMaking)
			{
				isMaking = false;
				addTile(tileRect, prevCompType);
				tileRect.origin.x = 0;
				tileRect.size.width = 0;
			}
			else
			{
				tileRect.origin.x = 0;
				tileRect.size.width = 0;
			}
		}
	}
}

void RoomLayer::makeTilesVertical(int xIdx)
{
	bool			isMaking = false;
	ComponentType	prevCompType = CT_NONE, currentCompType = CT_NONE;
	cocos2d::Rect	tileRect(xIdx*m_TileSize.height, 0, m_TileSize.width, 0);

	for(int yIdx = 0; yIdx <= m_RoomData.height; ++yIdx)
	{
		prevCompType = currentCompType;
		currentCompType = getTypeByIndex(xIdx, yIdx);
		if(isVerticalTile(xIdx, yIdx))
		{
			if(!isMaking)
			{
				isMaking = true;
				tileRect.origin.y = yIdx*m_TileSize.height;
			}
			else if(prevCompType != currentCompType)
			{
				addTile(tileRect, prevCompType);
				tileRect.origin.y = yIdx*m_TileSize.height;
				tileRect.size.height = 0;
			}
			tileRect.size.height += m_TileSize.height;
		}
		else
		{
			if(isMaking)
			{
				isMaking = false;
				addTile(tileRect, prevCompType);
				tileRect.origin.y = 0;
				tileRect.size.height = 0;
			}
			else
			{
				tileRect.origin.y = 0;
				tileRect.size.height = 0;
			}
		}
	}
}

void RoomLayer::setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld)
{
	m_PhysicsWorld = physicsWorld;
}

bool RoomLayer::isHorizontalTile(int xIdx, int yIdx)
{
	bool ret = false;
	int maxContainerIdx = (signed) m_RoomData.data.size() - 1;
	int currentTile = getTypeByIndex(xIdx, yIdx);
	if(currentTile > 0) //���� �����Ͱ� Ÿ��
	{
		//���� �Ʒ� Ÿ���� ���� �ٱ� Ÿ���� ��� ������ �� Ÿ�Ϸ� ���
		int upTile = getTypeByIndex(xIdx, yIdx + 1);
		int downTile = getTypeByIndex(xIdx, yIdx - 1);

		if( upTile != currentTile || downTile != currentTile )
		{
			ret = true;
		}
	}
	return ret;
}

bool RoomLayer::isVerticalTile(int xIdx, int yIdx)
{
	bool ret = false;
	int maxContainerIdx = (signed) m_RoomData.data.size() - 1;
	int currentTile = getTypeByIndex(xIdx, yIdx);

	if(currentTile > 0 && !isHorizontalTile(xIdx, yIdx)) //���� �����Ͱ� Ÿ��
	{ 
		int leftTile = getTypeByIndex(xIdx - 1, yIdx);
		int rightTile = getTypeByIndex(xIdx + 1, yIdx);
		if(leftTile != currentTile || rightTile != currentTile)
		{
			ret = true;
		}
	}
	return ret;
}

void RoomLayer::addTile(cocos2d::Rect tileRect, ComponentType type)
{
	Tile* newTile = nullptr;
	switch(type)
	{
		case OT_BLOCK:
			m_Block->extendBlock(tileRect);
			return;
		case OT_BLOCK_MOVING:
			newTile = GET_COMPONENT_MANAGER()->createComponent<MovingBlock>();
			break;
		case OT_BLOCK_TURRET:
			newTile = GET_COMPONENT_MANAGER()->createComponent<TurretBlock>();
			break;
		case OT_FLOOR:
			newTile = GET_COMPONENT_MANAGER()->createComponent<Floor>();
			break;
		case OT_PORTAL_CLOSED:
		case OT_PORTAL_OPEN:
			newTile = GET_COMPONENT_MANAGER()->createComponent<Portal>();
			((Portal*) newTile)->setRoom(this);
			break;
		default:
			return;
	}
	addChild(newTile);
	newTile->initTile(tileRect);
	m_Objects.push_back(newTile);
}

bool RoomLayer::isAvailableIndex(int xIdx, int yIdx)
{
	return xIdx >=0 && xIdx < m_RoomData.width &&
			yIdx >= 0 && yIdx < m_RoomData.height;
}

ComponentType RoomLayer::getTypeByIndex(int xIdx, int yIdx)
{
	return isAvailableIndex(xIdx, yIdx) ?
			m_RoomData.data[yIdx * m_RoomData.width + xIdx] : CT_NONE;
}

cocos2d::Rect RoomLayer::getRoomRect()
{
	return m_RoomRect;
}

bool RoomLayer::isOutOfRoom(cocos2d::Point pos)
{
	if(pos.x < 0 || pos.x > m_RoomRect.size.width ||
	   pos.y < 0 || pos.y > m_RoomRect.size.height)
	{
		return true;
	}
	cocos2d::Size moduleSize = GET_DATA_MANAGER()->getModuleSize();
	int moduleXIdx = pos.x / ( m_TileSize.width * moduleSize.width );
	int moduleYIdx = pos.y / ( m_TileSize.height * moduleSize.height );
	int index = moduleYIdx*( m_RoomData.width / moduleSize.width ) + moduleXIdx;
	bool isIn = m_RoomData.modulePlaceData[index];
	return !isIn;
}

RoomData RoomLayer::getRoomData()
{
	return m_RoomData;
}

void RoomLayer::roomSwitch(bool isON)
{
	for(auto object : m_Objects)
	{
		if(isON)
		{
			object->pause();
		}
		else
		{
			object->resume();
		}
		((PhysicsComponent*)object->getComponent(CT_PHYSICS))->setEnabled(isON);
	}
}

void RoomLayer::addSprite(ResourceType type, cocos2d::Point position)
{
	if(type != ST_START)
	{
		auto sprite = GET_RESOURCE_MANAGER()->createSprite(type);
		sprite->setPosition(position);
		sprite->setAnchorPoint(cocos2d::Point::ZERO);
		addChild(sprite, BACKGROUND);
	}
}

