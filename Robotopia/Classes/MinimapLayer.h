/************************************************************************/
/*
CLASS			: GameLayer
Author			: �迬��
����				: ���ӿ� ���Ǵ� ��� ������Ʈ���� �ִ� ���̾�
���� ��������	: 2014-10-29
���� ������		:
���� ��������	:
Comment			: �׳� Ŭ������ ������, ������ �޾Ƽ� �뷹�̾�� ����� �ֵ����ϵ����, �÷��̾� ��ġ ������
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"
#include "GameSceneUILayer.h"

BEGIN_NS_AT

class MinimapLayer : public GameSceneUILayer
{
public:
	MinimapLayer();
	~MinimapLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MinimapLayer);

private:


};

END_NS_AT