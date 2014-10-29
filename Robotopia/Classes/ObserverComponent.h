/************************************************************************/
/*
CLASS			: ObserverComponent
Author			: �迬��
����				: Sprite Component�� Ŭ����
���� ��������	: 2014-10-29
���� ������		:
���� ��������	:
Comment			: Create�ؼ� ��������� setSprite�ؼ� �ش� ��������Ʈ �߰����־���Ѵ�.
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Component.h"
#include "Trigger.h"

BEGIN_NS_AT

class ObserverComponent : public Component
{
public:
	OVERRIDE ~ObserverComponent();

	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						addTrigger( Trigger* trigger );
	void						removeTrigger( Trigger* trigger );
	void						removeCurrentTrigger();
	std::vector<Trigger*>&		getTriggers();

	CREATE_FUNC( ObserverComponent );

protected:
	std::vector<Trigger*> m_Triggers;
	std::vector<Trigger*> m_NextTriggers;
};

END_NS_AT