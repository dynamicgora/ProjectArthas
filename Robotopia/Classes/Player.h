	/************************************************************************/
/*
CLASS			: Player
Author			: �迬��
����				: Player class
���� ��������	: 2014-10-29
���� ������		:
���� ��������	:
Comment			: ��� ������Ʈ�� BaseComponent�� ����ϴ�.
*/
/************************************************************************/
#pragma once
#include "BaseComponent.h"
#include "Util.h"


class CommonInfo;
class Player : public BaseComponent
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);
	OVERRIDE void			enter();
	OVERRIDE void			exit();

	CREATE_FUNC( Player );
protected:

};

