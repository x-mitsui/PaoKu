#include "GameFatherLayer.h"

USING_NS_CC;

GameFatherLayer::GameFatherLayer()
{
}

GameFatherLayer::~GameFatherLayer()
{
}

Scene* GameFatherLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameFatherLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameFatherLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	initMap();
	
	initUI();
	
	initRole();
	return true;
}


void GameFatherLayer::initUI()
{


}

void GameFatherLayer::initMap()
{

	m_TileMap = TMXTiledMap::create("maps/PaoKu_Background2.tmx");

	this->addChild(m_TileMap,1);
}

void GameFatherLayer::initRole()
{

	mRole = Role::createWithTMX(m_TileMap);
	
	addChild(mRole,2);
}

void GameFatherLayer::menuCloseCallback(Ref* pSender)
{

}