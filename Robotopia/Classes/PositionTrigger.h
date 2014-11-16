/************************************************************************/
/*
CLASS			: PositionTrigger
Author			: �迬��
����			: Ư�� ��ġ�� ���������� �߻��ϴ� Ʈ���� Ŭ��
���� ��������	: 2014-11-05
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/
#pragma once
#include "Trigger.h"



class PositionTrigger : public Trigger
{
public:
	void					initPositionTrigger(cocos2d::Point point);
	virtual bool			operator ==( const Trigger& trigger );
	const cocos2d::Point	getTriggerPoint();
	PositionTrigger();
	~PositionTrigger();

private:
	cocos2d::Point m_TriggerPoint;
};

