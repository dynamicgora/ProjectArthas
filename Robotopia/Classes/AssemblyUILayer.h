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
#include "UILayer.h"

class AssemblyUILayer : public UILayer
{
public:
	AssemblyUILayer();
	~AssemblyUILayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(AssemblyUILayer);
private:

};