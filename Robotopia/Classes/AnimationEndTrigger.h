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



class BaseComponent;

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

