#include "Role.h"
#include "Dlog.h"
USING_NS_CC;

Role::Role():xSpeed(5),ySpeed(15),constxSpeed(xSpeed),constySpeed(ySpeed)
{
}

Role::~Role()
{
}

bool Role::init()
{
	return true;
}

void Role::extraInit()
{
	mSprite = Sprite::create("CloseNormal.png");
	auto objectGroup = getGameMap()->getObjectGroup("Role");//找对象组
	ValueMap dict = objectGroup->getObject("player");//对象组中的对象

	float x = dict["x"].asFloat();
	float y = dict["y"].asFloat();

	
	mSprite->setPosition(x,y);
	mSprite->setAnchorPoint(Vec2(0,0));

	//必须添加在地图中，因为以后的setMapPointByRole()中的行为在地图中判断
	getGameMap()->addChild(	mSprite, ROLE_ZORDER );

	this->setCurrentRoleState(ROLE_STATE::ROLE_RUN_STATE);

	this->schedule( schedule_selector( Role::role_update ),0.016f );
	
	setMapPointByRole();
	this->schedule( schedule_selector( Role::camera_update ),0.016f );
}

Role*Role::createWithTMX(cocos2d::TMXTiledMap* _map)
{
	Role* role = new Role;
	if (role && role->init())
	{
		role->setGameMap(_map);
		
		role->extraInit();
		role->autorelease();

		return role;
	}
	CC_SAFE_DELETE(role);
	return NULL;
}

void Role::setCurrentRolePoint(Vec2 point)
{
	mSprite->setPosition(point);
}

Vec2 Role::getCurrentRolePoint()
{
	return mSprite->getPosition();
}

void Role::role_update(float dt)
{
	role_logic();
}

void Role::runLogic()
{
	/*
	
		1.获取人物的位置点
		2.结合速度去修改位置点
		3.传给新的人物位置

	*/

	Vec2 pos = getCurrentRolePoint();
	Vec2 curPos = pos + Vec2(xSpeed,0);
	setCurrentRolePoint(curPos);
}

void Role::jumpUpLogic()
{

}

void Role::jumpDownLogic()
{

}



void Role::role_logic()
{
	switch (getCurrentRoleState())
	{
	case ROLE_STATE::ROLE_INVALID_STATE:
		
		break;
	case ROLE_STATE::ROLE_STAND_BY:
		Dlog::showLog("stand by");
		break;
	case ROLE_STATE::ROLE_JUMP_DOWN_STATE:
		jumpDownLogic();
		break;
	case ROLE_STATE::ROLE_JUMP_UP_STATE:
		jumpUpLogic();
		break;
	case ROLE_STATE::ROLE_RUN_STATE:
		runLogic();
		break;
	default:
		
		break;
	}
}

void Role::setMapPointByRole()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto mapTileNum = getGameMap()->getMapSize();
	auto tiledSize = getGameMap()->getTileSize();

	auto mapSize = Size(mapTileNum.width*tiledSize.width, mapTileNum.height*tiledSize.height);

	auto rolePoint = mSprite->getPosition();

	/////////////////////////////////////////////////////////////////////////
	float x = rolePoint.x > visibleSize.width/4 ? rolePoint.x : visibleSize.width/4;

	x = x < (mapSize.width - visibleSize.width*.8) ?x:(mapSize.width - visibleSize.width*.8);

	float y =rolePoint.y >visibleSize.height/3? rolePoint.y:visibleSize.height/3;

	y = y < mapSize.height/2 ? y:mapSize.height/2;
	///////////////////////////////////////////////////////////////////////

	Vec2 desPoint = Vec2(x,y);//目标点
	Vec2 centerPoint = Vec2(visibleSize.width/5,visibleSize.height/3);//????????????

	auto rltPoint = centerPoint - desPoint ;

	getGameMap()->setPosition(rltPoint);
}

void Role::camera_update(float delta)
{
	setMapPointByRole();
}