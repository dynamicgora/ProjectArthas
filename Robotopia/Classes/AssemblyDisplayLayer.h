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
	
	void					moveScanBar();
	bool					getPowerOver();
	bool					getMomoryOver();
	void					setConfirmSet(ConfirmSet confirmSet);
	void					assembleRobot();

private:
	cocos2d::Sprite*		m_Head = nullptr;
	cocos2d::Sprite*		m_Engine = nullptr;
	cocos2d::Sprite*		m_Armor = nullptr;
	cocos2d::Sprite*		m_Melee = nullptr;
	cocos2d::Sprite*		m_Range = nullptr;
	cocos2d::Sprite*		m_Steam = nullptr;
	cocos2d::Sprite*		m_Leg = nullptr;
	cocos2d::Sprite*		m_DisplayScanBar = nullptr;
	cocos2d::Sprite*		m_PowerGauge = nullptr;
	cocos2d::Sprite*		m_MemoryGauge =  nullptr;

	ConfirmSet				m_ConfirmSet = ConfirmSet();
	ConfirmSet				m_PrevConfirmSet = ConfirmSet();

	int						m_MaxPower = 0;
	int						m_MaxMemory = 0;

	bool					m_PowerOver;
	bool					m_MemoryOver;

	void					powerOverCheck();
	void					memoryOverCheck();
};