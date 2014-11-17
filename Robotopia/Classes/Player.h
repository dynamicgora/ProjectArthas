	/************************************************************************/
/*
CLASS			: Player
Author			: �迬��
����				: Player class
���� ��������	: 2014-10-29
���� ������		:
���� ��������	:
Comment			: 
*/
/************************************************************************/
#pragma once
#include "Thing.h"
#include "Util.h"


class CommonInfo;
class Player : public Thing
{
public:
	enum MoveStates
	{
		MS_IDLE = 0,
		MS_MOVE = 1,
		MS_JUMP = 2,
	};

	OVERRIDE bool			init();
	OVERRIDE void			enter();
	OVERRIDE void			exit();

	CREATE_FUNC( Player );
protected:
	
	static void					move(Thing* target, double dTime, int idx);
	static void					jump(Thing* target, double dTime, int idx);
	static void					attack(Thing* target, double dTime, int idx);
	static void					idleTransition(Thing* target, double dTime, int idx);
	static void					moveTransition(Thing* target, double dTime, int idx);
	static void					jumpTransition(Thing* target, double dTime, int idx);
};

