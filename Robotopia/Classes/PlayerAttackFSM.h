/************************************************************************/
/*
	CLASS			: PlayerAttackFSM
	Author			: �迬��
	����				: PlayerAttackFSM�� ������ Ŭ����.
	���� ��������	: 2014-11-12
	���� ������		: 
	���� ��������	: 
	Comment			: 
*/
/************************************************************************/
#pragma once
#include "Util.h"
#include "FSMComponent.h"

BEGIN_NS_AT
class PlayerAttackFSM : public FSMComponent
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC(PlayerAttackFSM);
private:
};

END_NS_AT