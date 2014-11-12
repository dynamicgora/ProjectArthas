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
#include <vector>

BEGIN_NS_AT

class Missile;
class MissileManager
{
public:
	MissileManager();
	~MissileManager();

	bool					init();
	Missile*				getMissile(ComponentType missileType, cocos2d::Point pos, Direction attackDir,
									   float damage, cocos2d::Vec2 velocity);

private:
	std::vector<Missile*>   m_Missiles;

};

END_NS_AT