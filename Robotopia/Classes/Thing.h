﻿/************************************************************************/
/*
CLASS			: Thing
Author			: 남현욱
역할				: Thing class
최종 수정일자	: 
최종 수정자		:
최종 수정사유	:
Comment			: FSM을 갖고 있는 객체들의 최상위 클래스.
*/
/************************************************************************/
#pragma once
#include "BaseComponent.h"
#include "Util.h"

class Thing;
typedef void(*FSMFunction)(Thing* target, double dTime, int idx);
typedef std::vector<FSMFunction> FSMFunctions;

class Thing : public BaseComponent
{
public:
	ABSTRACT bool			init() = 0;
	OVERRIDE void			update(float dTime);
	ABSTRACT void			enter() = 0;
	ABSTRACT void			exit() = 0;
	int						getState(int idx);
	void					setState(int idx, int state);
	void					initFSM(int FSMNum);

protected:
	std::vector<int>			m_States;
	std::vector<FSMFunctions>	m_FSMs;
	std::vector<FSMFunctions>	m_Transitions;
};
