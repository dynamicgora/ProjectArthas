/************************************************************************/
/*
CLASS			: MouseTrigger
Author			: �����
����			: Ư���� ���콺 �����ӿ� �°� �߻��ϴ� Ʈ���� Ŭ����.
���� ��������	: 2014-11-04
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/
#pragma once
#include "Trigger.h"

BEGIN_NS_AT

class Component;

class MouseTrigger : public Trigger
{
public:
	//void			initKeyCode(KeyCode keyCode, int keyState);
	//virtual bool	operator ==(Trigger& trigger);

	MouseTrigger();
	~MouseTrigger();

public:
// 	KeyCode			m_KeyCode;
// 	int				m_KeyState;
};

END_NS_AT