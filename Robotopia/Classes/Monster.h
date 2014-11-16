/************************************************************************/
/*
CLASS			: Monster
Author			: �輺��
����				: ������ü�� �߻�Ŭ����
���� ��������		: 2014-11-15
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "Util.h"
#include "BaseComponent.h"



class Monster : public BaseComponent
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);
	OVERRIDE void			enter();
	OVERRIDE void			exit();
	ABSTRACT bool			initMosnter() = 0;

protected:

};

