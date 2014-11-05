/************************************************************************/
/*
CLASS			: SimpleRoaming
Author			: �迬��
����			: ������ ��ġ���� �·� ��� �̵��ϴ� ������ Roaming
���� ��������	: 2014-11-05
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/
#pragma once
#include "Util.h"
#include "FSMComponent.h"

BEGIN_NS_AT

class SimpleRoamingFSM : public FSMComponent
{
public:
	OVERRIDE bool				init();
	void						initRoaming(const cocos2d::Point& leftPoint, const cocos2d::Point& rightPoint, float speed);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC(SimpleRoamingFSM);
private:
	cocos2d::Point				m_LeftPoint;
	cocos2d::Point				m_RightPoint;
	float						m_Speed;
};

END_NS_AT