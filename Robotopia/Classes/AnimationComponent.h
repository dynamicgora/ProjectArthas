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
#include "Component.h"

BEGIN_NS_AT


class AnimationCompnent : public Component
{

public:
	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	void						setAnimation(const char* AnimationName);


	CREATE_FUNC(AnimationCompnent);

private:
	cocos2d::Sprite* m_Sprite;
	int				 m_Type;

};

END_NS_AT