/************************************************************************/
/*
CLASS			: RobotAssemblyLayer
Author			: �����
����			: GameScene ���� �� �κ� ����â�� ������
���� ��������	: 2014-11-23
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"

class RobotAssemblyLayer : public GameSceneUILayer
{
public:
	RobotAssemblyLayer();
	~RobotAssemblyLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(RobotAssemblyLayer);
private:

};