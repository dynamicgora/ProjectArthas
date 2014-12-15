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

	virtual bool						init();
	void								changeState(int fsmIdx, Player::State state);
	void								addAnimation(BaseComponent* target, AnimationType type, int fsmIdx, Player::State state);
	void								setFlip(bool isLeft);

	CREATE_FUNC(RenderPart);
protected:
	int									idxize(int fsmIdx, Player::State state);
	std::vector<AnimationComponent*>	m_Animations;
	int									m_CurrentStateIdx;
};