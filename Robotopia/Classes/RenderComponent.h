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
class SpriteComponent;

class RenderComponent : public Component
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE void				update(float dTime);

	void						addTransition(Arthas::Transition addTransition);
	//�ٲ�� �� ���� ���� ����
	void						removeTransition(Arthas::Transition remTranstion);

protected:
	Arthas::SpriteComponent*    m_CurrentSprite;
	std::vector<Trigger*>		m_Triggers;
	std::vector<Transition>		m_Transitions;
};

END_NS_AT