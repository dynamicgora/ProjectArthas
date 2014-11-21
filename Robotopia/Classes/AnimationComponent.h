/************************************************************************/
/*
CLASS			: AnimationComponent
Author			: �輺��
����				: �� BaseComponent�� ���� �Ǹ� Animation�� �׸� �� �ִ�. 
���� ��������		: 2014-10-29
���� ������		:
���� ��������		:
Comment			: Create�ؼ� ���� ������ setAnimation�ؼ� �ش� �ִϸ��̼��� �߰����־���Ѵ�.
*/
/************************************************************************/

#pragma once
#include "SpriteComponent.h"




class AnimationComponent : public SpriteComponent
{

public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						setAnimation(ResourceType animationType, BaseComponent* renderTarget, 
											 int playNum = 0, bool isEndAni = false);
	void						endAni();
	CREATE_FUNC(AnimationComponent);

private:
	ResourceType		m_AnimationType;
	int					m_PlayNum;
	bool				m_IsEndAni;
};

