#include "GameFatherLayer.h"
#include "Dlog.h"
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

	initComponents();
	
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
	
	addChild(mRole,2,mROLE_TAG);
}

void GameFatherLayer::initComponents()
{
	std::vector<goldStruct> goldVector;

	auto goldGroup = m_TileMap->getObjectGroup("items");
	for (auto &obj : goldGroup->getObjects())
	{
		auto dict =  obj.asValueMap();//不要用“强制转换”来转换，要用这种形式转换
		float x = dict["x"].asFloat();
		float y = dict["y"].asFloat();
		auto gold = Sprite::create("images/gold.png");
		gold->setPosition(x,y);
		m_TileMap->addChild(gold,GOLD_TAG);//此处添加到地图中
		goldStruct _gs;
		_gs.goldSprite = gold;
		//以后根据配置文件或者plist文件来加载不同的金币数目
		_gs.goldValue = 100;
		goldVector.push_back(_gs);
	}
	mRole->setGoldVector(goldVector);
}

void GameFatherLayer::menuCloseCallback(Ref* pSender)
{

}

void GameFatherLayer::onEnter()
{
	Layer::onEnter();
	auto listener=EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan=CC_CALLBACK_2(GameFatherLayer::onTouchBegan,this);
	listener->onTouchMoved=CC_CALLBACK_2(GameFatherLayer::onTouchMoved,this);
	listener->onTouchEnded=CC_CALLBACK_2(GameFatherLayer::onTouchEnded,this);

	auto eventdispatcher=Director::getInstance()->getEventDispatcher();
	eventdispatcher->addEventListenerWithSceneGraphPriority(listener,getChildByTag(mROLE_TAG));

}

void GameFatherLayer::onExit()
{
	Layer::onExit();
	auto eventdispatcher=Director::getInstance()->getEventDispatcher();
	eventdispatcher->removeAllEventListeners();
}

bool GameFatherLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
	Dlog::showLog("onTouchBegan");
	WhenRunTurnJump();
	return true;
}

void GameFatherLayer::onTouchMoved(Touch *touch, Event *unused_event)
{
	Dlog::showLog("onTouchMoved");

}

void GameFatherLayer::onTouchEnded(Touch *touch, Event*unused_event)
{
	Dlog::showLog("onTouchEnded");

}

void GameFatherLayer::WhenRunTurnJump()
{
	if(mRole->getCurrentRoleState()==ROLE_STATE::ROLE_RUN_STATE)
	{
		Dlog::showLog("jump up");
		mRole->setCurrentRoleState(ROLE_STATE::ROLE_JUMP_UP_STATE);
	}
	else
	{
		Dlog::showLog("Not running");
		return;
	}
}