#ifndef GameFatherLayer_h__
#define GameFatherLayer_h__

#include "cocos2d.h"
#include "Role.h"


class GameFatherLayer : cocos2d::Layer
{
public:
	GameFatherLayer();
	~GameFatherLayer();

public:

	static cocos2d::Scene* createScene();

	virtual bool init();  

	void initUI();
	void initMap();
	void initRole();

	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(GameFatherLayer);
private:
	cocos2d::TMXTiledMap* m_TileMap;
	Role* mRole;
};


#endif // GameFatherLayer_h__
