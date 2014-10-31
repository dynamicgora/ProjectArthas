/************************************************************************/
/*
CLASS				: RenderComponent
Author				: �����
����				: Render���� �߻� Ŭ����
���� ��������		: 2014-10-31
���� ������			:
���� ��������		:
Comment				:
*/
/************************************************************************/

#pragma once
#include "Component.h"
#include "cocos2d.h"


BEGIN_NS_AT

class Trigger;
class StateComponent;

class RenderComponent : public Component
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();
	OVERRIDE void update(int dTime);

	void addTransition(Transition addTransition);
	void removeTransition(Transition remTranstion);

protected:
	std::vector<Transition> m_Transitions;
};

END_NS_AT