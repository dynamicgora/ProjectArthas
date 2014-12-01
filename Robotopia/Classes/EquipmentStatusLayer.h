/************************************************************************/
/*
CLASS			: EquipmentStatusLayer
Author			: �輺��
����				: Equipment�� status�� �����ִ� ���̾�
���� ��������		: 2014-12-01
���� ������		: �輺��
���� ��������		: �ű�
Comment			: 
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"


class ButtonLayer;

class EquipmentStatusLayer : public UILayer
{
public:
	EquipmentStatusLayer();
	~EquipmentStatusLayer();

	struct Equipmentes
	{
		HeadList		   m_CurChosenHead = HL_START;
		ArmorList		   m_CurChosenArmor = AL_START;
		EngineList		   m_CurChosenEngine = EL_START;
		LegList			   m_CurChosenLeg = LL_START;
		MeleeList		   m_CurChosenMelee = ML_START;
		RangeList		   m_CurChosenRangeList = RL_START;
		SteamContainerList m_CurChosenSteamContainerList = SCL_START;

	};

	/*struct CurEquipmentesInfo
	{
	HeadInfo		   m_HeadInfo;
	LegInfo			   m_LegInfo;
	ArmorInfo		   m_ArmorInfo;
	SteamContainerInfo m_SteamContainerInfo;
	MeleeInfo		   m_MeleeInfo;
	RangeInfo		   m_RangeInfo;
	EngineInfo		   m_EngineInfo;
	};*/

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(EquipmentStatusLayer);

	void					setStartEquipmentType(Equipmentes equipmentList);					

private:
	//ComponentType		   
	//curEquipmentesInfo     m_CurEquipmentInfo;
	Equipmentes				    m_CurBeInstalledEquipmentes;
	Equipmentes					m_CurBeChosenEquipmentDetail;
	EquipmentType				m_CurBeChosenEquipType;
	ButtonLayer*				m_UpgradeButton;
	ButtonLayer*				m_EquipButton;
	std::string			   	    m_StautsString[20];
	cocos2d::Label				m_CurBeChosenEquipmentDiscription;
	cocos2d::Label				m_CurBeInstalledEquipment[20];


};