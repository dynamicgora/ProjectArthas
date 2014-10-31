/************************************************************************/
/*
CLASS			: StateComponent
Author			: �輺��
����				: State���� �߻� Ŭ����
���� ��������		: 2014-10-29
���� ������		:
���� ��������		:
Comment			: 
*/
/************************************************************************/

#pragma once
#include "Component.h"
#include "cocos2d.h"


BEGIN_NS_AT

class Trigger;
class StateComponent;



class StateComponent : public Component
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();
	OVERRIDE void update(int dTime);

	void	   addTransition(Transition addTransition);
	void	   removeTransition(Transition remTranstion);
	Component* getNextState(Trigger* trigger);

protected:
	std::vector<Transition> m_Transitions;
};

END_NS_AT