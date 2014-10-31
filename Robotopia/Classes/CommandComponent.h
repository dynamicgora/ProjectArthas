/************************************************************************/
/*
CLASS			: PhysicsComponent
Author			: �迬��
����				: ��������Ǵ� ������Ʈ
���� ��������	: 2014-10-31
���� ������		:
���� ��������	:
Comment			: Body�� tag�� �θ��� Ÿ��
*/
/************************************************************************/

#pragma once
#include "Component.h"
#include "cocos2d.h"

BEGIN_NS_AT

class ObserverComponent;
class CommandComponent : public Component
{
public:


	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	ABSTRACT ObserverComponent*	getObserverComponent();

	CREATE_FUNC( CommandComponent );

protected:

};

END_NS_AT