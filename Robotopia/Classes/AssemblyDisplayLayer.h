/************************************************************************/
/*
CLASS			: AssemblyDisplayLayer
Author			: �����
����			: ���õ� ��� �����ش�.
���� ��������	: 2014-12-02
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "AssemblyUILayer.h"

class AssemblyDisplayLayer : public AssemblyUILayer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(AssemblyDisplayLayer);
private:
	cocos2d::Sprite*		m_DisplayScanBar = nullptr;

	void					moveScanBar();
};