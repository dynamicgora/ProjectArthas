#include "pch.h"
#include "SoundManager.h"


Arthas::SoundManager::SoundManager()
{
}

Arthas::SoundManager::~SoundManager()
{
}

bool Arthas::SoundManager::init()
{
	FMOD_RESULT result;

	result = FMOD::System_Create(&m_Systems);
	errCheck(result);

	//ä�� ����, �̴� ���, �Ƹ� �׳� 0�ϵ� (�߰� ����̺굥���� �����Ͷ�µ� ������)
	result = m_Systems->init(2, FMOD_INIT_NORMAL, 0);
	errCheck(result);
	return true;
}

void Arthas::SoundManager::errCheck(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		char str[256] = { 0, };
		sprintf_s(str, "FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		MessageBoxA(NULL, str, NULL, MB_OK);
		//messageBox�� ��������� �ѹ� �غ��� �����ؾ��� 
	}
}
