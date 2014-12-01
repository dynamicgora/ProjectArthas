/************************************************************************/
/*
CLASS			: RenderPart
Author			: �迬��
����				: Player ������ �κ� ������ ����
���� ��������	: 2014-11-29
���� ������		:
���� ��������	:
Comment			: �κ� ������ FSM���� enter exit�����۾� �ʿ�
*/
/************************************************************************/
#pragma once
#include "cocos2d.h"
#include "Player.h"

class AnimationComponent;
class RenderPart : public cocos2d::Node
{
public:
	RenderPart();
	virtual ~RenderPart();

	virtual bool				init();

	void						changeState(Player::State state);
	void						addAnimation(BaseComponent* target, AnimationType type, Player::State state);

	CREATE_FUNC(RenderPart);
protected:
	std::vector<AnimationComponent*>	m_Animations;
	Player::State						m_CurrentState;
};