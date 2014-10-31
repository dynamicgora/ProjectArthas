#include "GameManager.h"
#include "StageManager.h"
#include "DataManager.h"
#include "GameLayer.h"
#include "UILayer.h"

Arthas::StageManager::StageManager()
	:m_StageData()
{
}

Arthas::StageManager::~StageManager()
{
}

bool Arthas::StageManager::init()
{
	return true;
}


void Arthas::StageManager::getStageData( int stageNum )
{
	//�ӽ� ������ �޴°���
	m_StageData = GET_DATA_MANAGER()->MapTestFunction();
}
