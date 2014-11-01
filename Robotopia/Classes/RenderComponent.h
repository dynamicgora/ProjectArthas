/************************************************************************/
/*
CLASS				: RenderComponent
Author				: �����
����				: Render���� �߻� Ŭ����
���� ��������		: 2014-10-31
���� ������			: �����
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
class StateChangeTrigger;

class RenderComponent : public Component
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE void				update(int dTime);

	Arthas::Transition			createTransition(Arthas::StateChangeTrigger* stateChageTrigger, 
												 Arthas::StateComponent* stateComponent);
	void						addTransition(Arthas::Transition addTransition);
	void						addTransition(Arthas::Trigger* trigger, Arthas::Component* component);
	void						removeTransition(Arthas::Transition remTranstion);

protected:
	Arthas::Transition*			m_CurrentTransition;
	std::vector<Trigger*>		m_Triggers;
	std::vector<Transition>		m_Transitions;
};

END_NS_AT