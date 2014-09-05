#ifndef Role_h__
#define Role_h__

#include "cocos2d.h"

#define ROLE_ZORDER 10

class Role :public cocos2d::Node
{
public:
	Role();
	~Role();
	virtual bool init();  
	void extraInit();
	static Role*createWithTMX(cocos2d::TMXTiledMap* _map);

	CC_SYNTHESIZE(cocos2d::TMXTiledMap*, gameMap ,GameMap);
	CC_PROPERTY(cocos2d::Vec2, currentRolePoint, CurrentRolePoint);
private:
	cocos2d::Sprite *mSprite;
};


#endif // Role_h__
