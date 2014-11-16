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
#include "BaseComponent.h"
#include "cocos2d.h"



class Trigger;
class StateComponent;
class SpriteComponent;

class RenderComponent : public BaseComponent
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	OVERRIDE void				update(float dTime);
	ABSTRACT void				initRender();

	void						addTransition(Transition addTransition);
	//�ٲ�� �� ���� ���� ����
	void						removeTransition(Transition remTranstion);

protected:
	SpriteComponent*    m_CurrentSprite;
	std::vector<Trigger*>		m_Triggers;
	std::vector<Transition>		m_Transitions;
};

