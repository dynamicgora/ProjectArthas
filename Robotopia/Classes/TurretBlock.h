/************************************************************************/
/*
CLASS			: TurretBlock
Author			: �輺��
����				: �ֱ������� �����ϴ� ��
���� ��������		: 2014-11-07
���� ������		:
���� ��������		:
Comment			: ����� �ݵ�� setRect�� ��!
*/
/************************************************************************/

#pragma once
#include <Tile.h>
#include "cocos2d.h"

//
//public:
//	OVERRIDE bool init();
//	OVERRIDE void update(float dTime) = 0;
//	OVERRIDE void enter() = 0;
//	OVERRIDE void exit() = 0;
//
//	ABSTRACT void initTile(float x, float y, float width, float height);
//	ABSTRACT void initTile(cocos2d::Rect rect);
//
//protected:
//	void		initPhysicsBody(cocos2d::Rect rect);
//	void		initSprite(cocos2d::Point position = cocos2d::Point::ZERO, cocos2d::Point anchor = cocos2d::Point::ZERO);
//
//	cocos2d::Rect m_BoxRect;
//	ResourceType m_SpriteType;



class TurretBlock : public Tile
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime);
	OVERRIDE void enter();
	OVERRIDE void exit();

	OVERRIDE void initTile(cocos2d::Rect tileRect);

	CREATE_FUNC(TurretBlock);
private:

	

};

