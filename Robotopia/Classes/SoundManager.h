/************************************************************************/
/*
CLASS			: EffectManager
Author			: �輺��
����				: Sound ��û�� ������ ����
���� ��������		: 2014-10-31
���� ������		:
���� ��������		:
Comment			: ���� Fmod�� ����Ѵ� �̿ܿ� �ٸ� ��� ������
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "cocos2d.h"
#include <fmod.h>
#include <fmod.hpp>
#include <fmod_errors.h>

#pragma comment(lib, "fmodex_vc.lib")



class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	bool	init();
	void    errCheck(FMOD_RESULT result);

	

private:
	FMOD::System*	m_Systems;
	FMOD::Sound*	m_Sound;
	FMOD::Channel*	m_Channel;


};


