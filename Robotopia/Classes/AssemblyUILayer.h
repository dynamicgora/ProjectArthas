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
#include "EquipmentAbstract.h"

class ButtonLayer;
class IconLayer;
class EquipmentHead;
class EquipmentEngine;
class EquipmentArmor;
class EquipmentMelee;
class EquipmentRange;
class EquipmentSteamContainer;
class EquipmentLeg;

class AssemblyUILayer : public UILayer
{
public:
	AssemblyUILayer();
	~AssemblyUILayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(AssemblyUILayer);

private:
	bool					m_IsStarted = false;

	cocos2d::Sprite*		m_AssemblyBackground = nullptr;
	cocos2d::Sprite*		m_AssemblyFrame = nullptr;
	cocos2d::Sprite*		m_ViewChangeArrow = nullptr;
	cocos2d::Sprite*		m_DisplayScanBar = nullptr;
	cocos2d::Rect			m_viewChangeRect;

	ButtonLayer*			m_ButtonConfirm = nullptr;
	ButtonLayer*			m_ButtonCancel = nullptr;

	cocos2d::Node*			m_HeadContainer = nullptr;
	cocos2d::Node*			m_EngineContainer = nullptr;
	cocos2d::Node*			m_ArmorContainer = nullptr;
	cocos2d::Node*			m_MeleeContainer = nullptr;
	cocos2d::Node*			m_RangeContainer = nullptr;
	cocos2d::Node*			m_SteamContainer = nullptr;
	cocos2d::Node*			m_LegContainer = nullptr;

	cocos2d::Node*			m_BearSkillContainer = nullptr;
	cocos2d::Node*			m_MonkeySkillContainer = nullptr;
	cocos2d::Node*			m_EagleSkillContainer = nullptr;
	cocos2d::Node*			m_CommonSkillContainer = nullptr;

	cocos2d::Rect			m_EquipmentRect = cocos2d::Rect();
	cocos2d::Rect			m_HeadRect = cocos2d::Rect();
	cocos2d::Rect			m_EngineRect = cocos2d::Rect();
	cocos2d::Rect			m_ArmorRect = cocos2d::Rect();
	cocos2d::Rect			m_MeleeRect = cocos2d::Rect();
	cocos2d::Rect			m_RangeRect = cocos2d::Rect();
	cocos2d::Rect			m_SteamRect = cocos2d::Rect();
	cocos2d::Rect			m_LegRect = cocos2d::Rect();

	cocos2d::Rect			m_BearSkillRect = cocos2d::Rect();
	cocos2d::Rect			m_MonkeySkillRect = cocos2d::Rect();
	cocos2d::Rect			m_EagleSkillRect = cocos2d::Rect();
	cocos2d::Rect			m_CommonSkillRect = cocos2d::Rect();

	std::vector<EquipmentHead*>				m_HeadList;
	std::vector<EquipmentEngine*>			m_EngineList;
	std::vector<EquipmentArmor*>			m_ArmorList;
	std::vector<EquipmentMelee*>			m_MeleeList;
	std::vector<EquipmentRange*>			m_RangeList;
	std::vector<EquipmentSteamContainer*>	m_SteamList;
	std::vector<EquipmentLeg*>				m_LegList;

	struct ConfirmSet
	{
		HeadList							m_Head = HL_END;
		EngineList							m_Engine = EL_END;
		ArmorList							m_Armor = AL_END;
		MeleeList							m_Melee = ML_END;
		RangeList							m_Range = RL_END;
		SteamContainerList					m_Steam = SCL_END;
		LegList								m_Leg = LL_END;
	};
	ConfirmSet								m_ConfirmSet;
	
	AssemblyLayerType		m_CurrentAssembly = NO_ASSEMBLY_LAYER;

	void					equipmentContainerInit();
	void					assemblyLayerButtonInit();

	void					displayEquipments();
	void					updateEquipments(float dTime);
	void					updateDoubleClickIcon(cocos2d::Point clickPoint);
	void					setConfirmSet();
	
	void					viewChange(AssemblyLayerType moveViewTo);
	void					equipmentContainerVisible(bool visible);
	void					moveScanBar();
	void					moveContainer(bool moveLeft, cocos2d::Node* container, cocos2d::Rect containerRect);
	void					confirmAssembly();
	void					toTitleScene();

};

//Equipment Create with template (����)
/*
template <typename T>
void					listUpEquipment(int listStart, int listEnd, cocos2d::Node* container, std::vector<T*>* listPointer);

template <typename T>
void AssemblyUILayer::listUpEquipment(int listStart, int listEnd, cocos2d::Node* container, std::vector<T*>* listPointer)
{
	auto testSp = GET_RESOURCE_MANAGER()->createSprite(ST_ASSEMBLY_ICON_DEFAULT);
	for (int i = listStart; i < listEnd; ++i)
	{
		T* equipment = T::create();
		(*listPointer).push_back(equipment);
		(*listPointer)[i]->setEquipmentIcon(ASSEMBLY_ICON, testSp);
		(*listPointer)[i]->getEquipmentIcon()->setIconRect(cocos2d::Point(container->getBoundingBox().getMinX() * RESOLUTION, container->getBoundingBox().getMinY() * RESOLUTION), cocos2d::Point(40 + 70 * i, 35));
		container->addChild((*listPointer)[i]);
	}
}

listUpEquipment(static_cast<int>(HL_START), static_cast<int>(HL_END), m_HeadContainer, &m_HeadList);
listUpEquipment(static_cast<int>(EL_START), static_cast<int>(EL_END), m_EngineContainer, &m_EngineList);
listUpEquipment(static_cast<int>(AL_START), static_cast<int>(AL_END), m_ArmorContainer, &m_ArmorList);
listUpEquipment(static_cast<int>(ML_START), static_cast<int>(ML_END), m_MeleeContainer, &m_MeleeList);
listUpEquipment(static_cast<int>(RL_START), static_cast<int>(RL_END), m_RangeContainer, &m_RangeList);
listUpEquipment(static_cast<int>(SCL_START), static_cast<int>(SCL_END), m_SteamContainer, &m_SteamList);
listUpEquipment(static_cast<int>(LL_START), static_cast<int>(LL_END), m_LegContainer, &m_LegList);
*/
