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
#include "AssemblyUILayer.h"


class ButtonLayer;

class EquipmentStatusLayer : public AssemblyUILayer
{
public:


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

	enum BasicStatus
	{
		BASISSTAUTSSTART = -1,
		LEVEL = 0,
		KWATT,
		UPGRADEPRICE,
		BASISSTATUSEND,
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
	void					setBasicLabels();
	void					setButtons();
	void					setAllStatusDescLabels();
	void					setAllStatusValueLabels();


	//�� ��ġ
	void					setPosBasicDescLabel();
	void					setPosBasicValueLabel();
	void					setPosAllStatusDescLabel();
	void					setPosAllStatusValueLabel();

	//�׿�
	void					setCurClickedItem(ClickedItem clickedItem);


private:
	//ComponentType		   
	//curEquipmentesInfo     m_CurEquipmentInfo;
	Equipmentes							m_CurBeInstalledEquipmentes;
	Equipmentes							m_CurBeChosenEquipmentDetail;
	EquipmentType						m_CurBeChosenEquipType = EMT_START;
	ButtonLayer*						m_UpgradeButton = nullptr;
	ButtonLayer*						m_EquipButton = nullptr;
	ClickedItem							m_PrevClickedItem;
	ClickedItem							m_CurClickedItem;

	std::string			   				m_StautsString[20];
	std::vector<cocos2d::Label*>		m_BasicStatusDesc;
	std::vector<cocos2d::Label*>		m_BasicStatusValue;
	std::vector<cocos2d::Label*>		m_AllStatusDesc;
	std::vector<cocos2d::Label*>		m_AllStatusValue;

};