﻿#include "pch.h"
#include "ExplosionEffect.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "StageManager.h"
#include "Player.h"

bool ExplosionEffect::init()
{
	if (!Effect::init())
	{
		return false;
	}

	m_Sprite = cocos2d::Sprite::create();
	auto animation = GET_RESOURCE_MANAGER()->createAnimation(AT_GRENADEEXPLOSION);
	auto animate = cocos2d::Animate::create(animation);
	auto callfunc = cocos2d::CallFuncN::create(CC_CALLBACK_1(ExplosionEffect::endAnimation, this));


	m_Sprite->runAction(cocos2d::Sequence::create(animate, callfunc, NULL));
	m_Sprite->setScale(6);
	addChild(m_Sprite);

	setVisible(false);

	return true;
}

void ExplosionEffect::enter()
{
	setVisible(true);
}

void ExplosionEffect::exit()
{
	m_IsDead = true;
}

void ExplosionEffect::update(float dTime)
{
	Effect::update(dTime);
}

void ExplosionEffect::dead()
{
	removeFromParent();
}

void ExplosionEffect::endAnimation(cocos2d::Ref* sender)
{
	m_IsDead = true;
}
