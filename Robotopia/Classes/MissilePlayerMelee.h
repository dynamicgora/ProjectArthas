/************************************************************************/
/*
CLASS			: MissilePlayerMelee
Author			: �輺��
����				: Player�� Melee Missile�� ���� ���� ������ ����
���� ��������		: 2014-11-12
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once

#include "Missile.h"
#include "Util.h"

BEGIN_NS_AT

class PhysicsTrigger;
class MissilePlayerMelee : public Arthas::Missile
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	OVERRIDE void			    initMissile();
	OVERRIDE void				setAttribute(cocos2d::Point pos, Direction attackDir = DIR_NONE,
											 float damage = 0,
											 cocos2d::Size contentsSize = cocos2d::Size::ZERO,
											 cocos2d::Vec2 velocity = cocos2d::Point::ZERO ,
											 cocos2d::Point targetPos = cocos2d::Point::ZERO);


	CREATE_FUNC(MissilePlayerMelee);

private:
	float	m_Duration;
	bool	m_IsPrevTimeCheck;
	float	m_PrevTime;
	float 	m_CurTime;

};

END_NS_AT