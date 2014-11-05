#include "SpriteTool/ToolScene.h"
#include "SpriteTool/ToolLayer.h"



bool Arthas::ToolScene::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	m_ToolLayer = Arthas::ToolLayer::create();
	m_ToolLayer->setAnchorPoint(cocos2d::Point::ZERO);

	this->addChild(m_ToolLayer, Arthas::ToolScene::ZOrder::TOOLLAYER);

	scheduleUpdate();
	return true;
}

void Arthas::ToolScene::update(float dTime)
{
	m_ToolLayer->update(dTime);
}

cocos2d::Scene* Arthas::ToolScene::createScene()
{
	cocos2d::Scene* scene = cocos2d::Scene::createWithPhysics();
	cocos2d::Vect gravity = cocos2d::Vect(0.0f, -980.0f);
	scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(gravity);

	Arthas::ToolScene* layer = Arthas::ToolScene::create();
	layer->setPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer, NULL, GAME_SCENE_TAG);

	return scene;
}

void Arthas::ToolScene::setPhysicsWorld(cocos2d::PhysicsWorld* physicsWorld)
{
	m_PhysicsWorld = physicsWorld;
}