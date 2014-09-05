#include "Role.h"
USING_NS_CC;

Role::Role()
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
	addChild(	mSprite,ROLE_ZORDER);//
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