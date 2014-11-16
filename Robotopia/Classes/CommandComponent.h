/************************************************************************/
/*
	CLASS			: CommandComponent
	Author			: �迬��
	����				: Ŀ�ǵ��� �߻� ������Ʈ
	���� ��������	: 2014-10-31
	���� ������		:
	���� ��������	:
	Comment			:
*/
/************************************************************************/

#pragma once
#include "BaseComponent.h"
#include "cocos2d.h"



class ObserverComponent;
class CommandComponent : public BaseComponent
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

