#include "pch.h"
#include "View.h"


bool View::init()
{
	if (!cocos2d::extension::ScrollView::init())
	{
		return false;
	}

	return true;
}

void View::initScroll(cocos2d::Layer* scrollingLayer)
{
	m_Scroll = cocos2d::extension::ScrollView::create(cocos2d::Director::getInstance()->getWinSize(),
													  scrollingLayer);
	m_Scroll->setDirection(cocos2d::extension::ScrollView::Direction::BOTH);
	m_Scroll->setBounceable(false);
	this->addChild(m_Scroll);

}

void View::setViewPort(cocos2d::Point pivotPoint)
{
	m_Scroll->setContentOffset(pivotPoint);
}

