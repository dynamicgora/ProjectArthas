/************************************************************************/
/*
CLASS			: MovingBlock
Author			: �迬��
����			: �����̴� Ÿ�� MovingBlock
���� ��������	: 2014-11-05
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/

#pragma once
#include "Block.h"
#include "Util.h"

BEGIN_NS_AT

class MovingBlock : public Block
{
public:
	OVERRIDE bool init();
	OVERRIDE void update(float dTime);
	OVERRIDE void enter();
	OVERRIDE void exit();

	CREATE_FUNC(MovingBlock);

private:

};

END_NS_AT