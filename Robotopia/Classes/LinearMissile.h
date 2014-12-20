
/************************************************************************/
/*
CLASS			: LinearMissile
Author			: �迬��
����				: ������ �ٰ��� �̻���
���� ��������	: 2014-12-20
���� ������		:
���� ��������	: 
Comment			: ��, �� ���� ���� ����
*/
/************************************************************************/
#pragma once


#include "Missile.h"
#include "Util.h"
class AnimationComponent;
class LinearMissile : public Missile
{
public:
	virtual bool			init();
	virtual void			update(float dTime);
	virtual void			enter();
	virtual void			exit();

	virtual void			initMissile();
	virtual void			setAttribute(cocos2d::Point pos, Direction attackDir = DIR_NONE, float damage = 0,
										 cocos2d::Size contentsSize = cocos2d::Size::ZERO,
										 cocos2d::Vec2 velocity = cocos2d::Point::ZERO,
										 cocos2d::Point targetPos = cocos2d::Point::ZERO);

	virtual bool			onContactBegin(cocos2d::PhysicsContact& contact);
	virtual void			setEnabled(bool enable);

	CREATE_FUNC(LinearMissile);

private:
	cocos2d::Point			m_Pos;
	AnimationComponent*		m_Ani;
};