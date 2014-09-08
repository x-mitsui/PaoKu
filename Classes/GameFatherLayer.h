#ifndef GameFatherLayer_h__
#define GameFatherLayer_h__

#include "cocos2d.h"
#include "Role.h"
#include "mHeaders.h"
const int mROLE_TAG = 2;


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

	void initComponents();
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(GameFatherLayer);

	//-->´¥Ãþ
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event*unused_event);

	virtual void onEnter()override;
	virtual void onExit()override;

	void WhenRunTurnJump();
	//<--
private:
	cocos2d::TMXTiledMap* m_TileMap;
	Role* mRole;
};


#endif // GameFatherLayer_h__
