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
	OVERRIDE void				setAttribute(cocos2d::Point pos, Direction attackDir, 
											 float damage, cocos2d::Vec2 velocity);


	CREATE_FUNC(MissilePlayerMelee);

protected:
	PhysicsTrigger* m_PhysicsTirgger;

};

END_NS_AT