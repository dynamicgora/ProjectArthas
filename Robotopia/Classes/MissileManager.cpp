#include "pch.h"
#include "Missile.h"
#include "MissileManager.h"
#include "MissilePlayerMelee.h"
#include "GameManager.h"
#include "ComponentManager.h"
#include "StageManager.h"

bool Arthas::MissileManager::init()
{

	//�����ѹ����� �ٲ���
	m_Missiles.reserve(50);

	for (int i = 0; i < 20; ++i)
	{
		Missile* PlayerMeleeMissile = GET_COMPONENT_MANAGER()->createComponent<MissilePlayerMelee>();
		PlayerMeleeMissile->initMissile();
		m_Missiles.push_back(PlayerMeleeMissile);
	
	}

	return true;
}


Arthas::Missile* Arthas::MissileManager::getMissile(Arthas::ComponentType missileType, cocos2d::Point pos,
													Arthas::Direction attackDir, 
													float damage, cocos2d::Vec2 velocity)
{
	for (auto pMissile : m_Missiles)
	{
		if (pMissile->getType() == missileType && pMissile->isUsable())
		{
			pMissile->setAttribute(pos, attackDir, damage, velocity);
			
			GET_STAGE_MANAGER()->addObject(pMissile, GET_STAGE_MANAGER()->getRoomNum(), pos, GAME_OBJECT);
			return pMissile;
		}
	}

	//������� �Դٸ� �տ��� ���ǿ� �´� �̻����� �����ٴ� ���̰�
	//�̻����� ���� �����ؼ� �־���� �Ѵ�. 
	//�ٸ� ���� �̻����� ��� �־�����
	Missile* playerMeleeMissile = GET_COMPONENT_MANAGER()->createComponent<MissilePlayerMelee>();
	m_Missiles.push_back(playerMeleeMissile);


	//��� �̷��� �ȵ����� �ϴ���
	return playerMeleeMissile;
}


