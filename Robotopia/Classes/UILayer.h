/************************************************************************/
/*
	CLASS			: UILayer
	Author			: �迬��
	����				: UI���� ������Ʈ���� ��� ���̾�
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: �׳� Ŭ������ ������
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "GameManager.h"
#include "Util.h"

class UILayer : public cocos2d::Layer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void					update( float dTime );

	CREATE_FUNC( UILayer );
protected:

};
