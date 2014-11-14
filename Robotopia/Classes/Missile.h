/************************************************************************/
/*
CLASS			: Missile
Author			: �輺��
����				: ���� �̻����� �ֻ��� �θ� Ŭ����
���� ��������		: 2014-11-12
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once

#include "Component.h"
#include "Util.h"

BEGIN_NS_AT

class Missile : public Arthas::Component
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	ABSTRACT void			    initMissile() = 0;
	ABSTRACT void				setAttribute(cocos2d::Point pos, Direction attackDir, 
											 float damage,  
											 cocos2d::Size contentsSize, cocos2d::Vec2 velocity,
											 cocos2d::Point targetPos) = 0;
	bool						isUsable() const ;


protected:
	bool						m_IsPlayerMissile;
	bool						m_IsUsable;
	float						m_Damage;
	cocos2d::Vec2				m_Velocity;
	Direction					m_AttackDir;
	cocos2d::Point				m_TargetPos;
	std::vector<Trigger*>		m_Triggers;


};

END_NS_AT