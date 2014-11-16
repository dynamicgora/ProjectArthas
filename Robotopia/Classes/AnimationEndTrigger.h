/************************************************************************/
/*
CLASS			: AnimationEndTrigger
Author			: �迬��
����				: � �ִϸ��̼� ������ �������� �˷��ִ� Ʈ����
���� ��������		: 2014-11-16
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/

#pragma once
#include "Trigger.h"

BEGIN_NS_AT

class Component;

class AnimationEndTrigger : public Trigger
{
public:
	void			initTrigger(ResourceType animationType);
	ResourceType	getAnimationType() const ;
	virtual bool	operator ==(const Trigger& trigger);

	AnimationEndTrigger();
	~AnimationEndTrigger();

private:
	ResourceType m_AnimationType;

};

END_NS_AT