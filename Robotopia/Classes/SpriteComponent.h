/************************************************************************/
/*
	CLASS			: SpriteComponent
	Author			: �迬��
	����				: Sprite Component�� Ŭ����
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: Create�ؼ� ��������� setSprite�ؼ� �ش� ��������Ʈ �߰����־���Ѵ�.
*/
/************************************************************************/

#pragma once
#include "Component.h"
#include "cocos2d.h"

BEGIN_NS_AT

class StateComponent;
class SpriteComponent : public Component
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						initSprite( ResourceType resourceType, Component* parent , 
											cocos2d::Point position = cocos2d::Point(0.f, 0.f), 
											cocos2d::Point anchorPoint = cocos2d::Point(0.5f, 0.5f));
	cocos2d::Sprite*			getSprite();

	void						addTransition(Transition addTransition);
	void						removeTransition(Transition remTranstion);
	SpriteComponent*			getNextSprite(Trigger* trigger);

	CREATE_FUNC(SpriteComponent);

protected:
	std::vector<Transition>		m_Transitions;
	cocos2d::Sprite*			m_Sprite;
	Component*					m_RenderTarget;
};

END_NS_AT