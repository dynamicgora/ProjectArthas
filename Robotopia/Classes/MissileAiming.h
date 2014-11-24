/************************************************************************/
/*
CLASS			: MissileAiming
Author			: �輺��
����				: Player�� ��� ���� ���� �Ǵ� �̻���
���� ��������		: 2014-11-24
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once

#include "Missile.h"
#include "Util.h"



class MissileAiming : public Missile
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
											 cocos2d::Vec2 velocity = cocos2d::Point::ZERO,
											 cocos2d::Point targetPos = cocos2d::Point::ZERO);


	CREATE_FUNC(MissileAiming);

private:
	int				m_MovedDistance;
	cocos2d::Point  m_StartPos;
	cocos2d::Point  m_CurPos;
	bool			m_IsStartPosCheck;


};

