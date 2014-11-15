	/************************************************************************/
/*
CLASS			: Player
Author			: �迬��
����				: Player class
���� ��������	: 2014-10-29
���� ������		:
���� ��������	:
Comment			: ��� ������Ʈ�� Component�� ����ϴ�.
*/
/************************************************************************/
#pragma once
#include "Component.h"
#include "Util.h"

BEGIN_NS_AT
class CommonInfo;
class Player : public Component
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);
	OVERRIDE void			enter();
	OVERRIDE void			exit();


	CREATE_FUNC( Player );
protected:

};

END_NS_AT