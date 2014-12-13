/************************************************************************/
/*
CLASS			: MissileThunder
Author			: �輺��
����				: Devil�� ��� �� ���� �̻���
���� ��������		: 2014-12-12
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once

#include "Missile.h"
#include "Util.h"

class AnimationComponent;
class MissileThunder : public Missile
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
	void						setEnable(bool enable);


	CREATE_FUNC(MissileThunder);

private:
	cocos2d::Sprite*			m_ThunderSprite = nullptr;
	cocos2d::Point				m_TargetPos;
	AnimationComponent*			m_ThunderAniComponent = nullptr;
	bool						m_ThunderTurn = false;

};

