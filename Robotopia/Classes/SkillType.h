/************************************************************************/
/*
CLASS			: SkillType
Author			: �����
����			: Skill Type ����
���� ��������	: 2014-12-12
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once

enum BearSkill
{
	BEAR_NONE,
	BEAR_SUPER_ARMOR,
	BEAR_JONYA, //��������
	BEAR_SUPER_DASH,
	BEAR_CRICAL_PUNCH,
	BEAR_STUN,
	BEAR_EMOLATION,
	BEAR_ATTACK_REFLECT,
};

enum MonkeySkill
{
	MONKEY_NONE,
	MONKEY_BIND,
	MONKEY_GRENADE,
	MONKEY_MINE,
	MONKEY_KNOCK_BACK,
	MONKEY_SHIELD,
	MONKEY_DUMMY,
	MONKEY_ROLLING,
};

enum EagleSkill
{
	EAGLE_NONE,
	EAGLE_FLYING_ATTACK,
	EAGLE_MISSILE_RADIATION,
	EAGLE_BULLET_REMOVER,
	EAGLE_STEALTH,
	EAGLE_FLASH,
	EAGEL_NAPALM,
};

enum CommonSkill
{
	COMMON_NONE,
	COMMON_DOUBLE_JUMP,
	COMMON_DASH,
	COMMON_BACKSTEP,
	COMMON_NAP,
};

struct SkillType
{
	BearSkill bearSkill = BEAR_NONE;
	MonkeySkill monkeySkill = MONKEY_NONE;
	EagleSkill eagleSkill = EAGLE_NONE;
	CommonSkill commonSkill = COMMON_NONE;
};