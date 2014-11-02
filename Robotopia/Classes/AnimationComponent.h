/************************************************************************/
/*
CLASS			: AnimationComponent
Author			: �輺��
����				: �� Component�� ���� �Ǹ� Animation�� �׸� �� �ִ�. 
���� ��������		: 2014-10-29
���� ������		:
���� ��������		:
Comment			: Create�ؼ� ���� ������ setAnimation�ؼ� �ش� �ִϸ��̼��� �߰����־���Ѵ�.
*/
/************************************************************************/

#pragma once
#include "SpriteComponent.h"

BEGIN_NS_AT


class AnimationCompnent : public SpriteComponent
{

public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						setAnimation(ResourceType animationType);

	CREATE_FUNC(AnimationCompnent);

private:
	ResourceType		m_AnimationType;

};

END_NS_AT