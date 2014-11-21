/************************************************************************/
/*
	CLASS			: SpriteComponent
	Author			: �迬��
	����				: Sprite BaseComponent�� Ŭ����
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: Create�ؼ� ��������� setSprite�ؼ� �ش� ��������Ʈ �߰����־���Ѵ�.
*/
/************************************************************************/

#pragma once
#include "BaseComponent.h"
#include "cocos2d.h"



class StateComponent;
class SpriteComponent : public BaseComponent
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						initSprite( ResourceType resourceType, BaseComponent* parent , 
											cocos2d::Point position = cocos2d::Point(0.f, 0.f), 
											cocos2d::Point anchorPoint = cocos2d::Point(0.5f, 0.5f));
	cocos2d::Sprite*			getSprite();

	void						addTransition(Transition addTransition);
	void						removeTransition(Transition remTranstion);
	SpriteComponent*			getNextSprite(Trigger* trigger);

	void						setSpriteVisible(bool visible);

	CREATE_FUNC(SpriteComponent);

protected:
	std::vector<Transition>		m_Transitions;
	cocos2d::Sprite*			m_Sprite;
	BaseComponent*				m_RenderTarget;
};

