/************************************************************************/
/*
	CLASS			: Tile
	Author			: �迬��
	����				: Tile���� �߻� class
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: ����� �ݵ�� setRect�� ��!
*/
/************************************************************************/
#pragma once
#include "BaseComponent.h"
#include "Util.h"



class Tile : public BaseComponent
{
public:
	OVERRIDE bool		init();
	OVERRIDE void		update(float dTime) = 0;
	OVERRIDE void		enter() = 0;
	OVERRIDE void		exit() = 0;

	ABSTRACT void		initTile(cocos2d::Rect tileRect) = 0;

protected:
	ABSTRACT void		initPhysicsBody(cocos2d::Rect physicalRect, PhysicsCategory categoryBitmask = PHYC_ALL);
	void				initSprite(cocos2d::Size spriteSize);

	ResourceType m_SpriteType;
};

