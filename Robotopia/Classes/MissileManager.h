/************************************************************************/
/*
CLASS			: MissileManager
Author			: �輺��
����				: ���� �̻��� �̸� ���� �� �Ҵ�
���� ��������		: 2014-11-12
���� ������		:
���� ��������	    :
Comment			:
*/
/************************************************************************/

#pragma once

#include "Util.h"

BEGIN_NS_AT

class Missile;
class MissileManager
{
public:
	MissileManager();
	~MissileManager();

	bool					init();
	Missile*				launchMissile(ComponentType missileType, cocos2d::Point pos, 
									   Direction attackDir = DIR_NONE,
									   cocos2d::Size contentsSize = cocos2d::Size::ZERO,
									   float damage = 0,
									   cocos2d::Vec2 velocity = cocos2d::Vec2::ZERO, 
									   cocos2d::Point targetPos = cocos2d::Point::ZERO);

private:
	Missile*				createMissile(ComponentType missileType);
	std::vector<Missile*>   m_Missiles;

};

END_NS_AT