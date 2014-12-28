/************************************************************************/
/*
CLASS			: BossFirst
Author			: �迬��
����				: ù��° ���� class
���� ��������		: 2014-12-19
���� ������		:
���� ��������		:
Comment			: ���ۺ��� ���ư��� ������ô�.
*/
/************************************************************************/
#pragma once
#include "BaseComponent.h"
#include "Util.h"
#define RAIL_RADIUS 360
#define ROTATE_ANGLE 10.f
#define ROTATE_DURATION 0.25f
#define MAX_ROTATE_NUM 20
#define MIN_ROTATE_NUM 5

class BossHead;
class SpriteComponent;
class BossFirst : public BaseComponent
{
public:

	virtual bool					init();
	virtual void					update(float dTime);
	virtual void					enter();
	virtual void					exit();
	virtual void					dead();

	void							enterMove();
	void							exitMove(cocos2d::Node* ref);
	CREATE_FUNC(BossFirst);

private:
	SpriteComponent*			m_Rail = nullptr;
	int							m_RotateNum = -1;
	cocos2d::RotateBy*			m_RotateModule = nullptr;
	BossHead*					m_Head = nullptr;
	bool						m_IsEntranceBGMEnd = false;
};