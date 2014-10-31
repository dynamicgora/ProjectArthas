/************************************************************************/
/*
CLASS			: EffectManager
Author			: 김성연
역할				: Sound 요청시 생성후 전달
최종 수정일자		: 2014-10-31
최종 수정자		:
최종 수정사유		:
Comment			: 아직 Fmod를 사용한다 이외에 다른 기능 안정함
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "cocos2d.h"
#include <fmod.h>
#include <fmod.hpp>
#include <fmod_errors.h>

#pragma comment(lib, "fmodex_vc.lib")

BEGIN_NS_AT

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

END_NS_AT
