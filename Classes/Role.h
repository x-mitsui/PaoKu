#ifndef Role_h__
#define Role_h__

#include "cocos2d.h"

#define ROLE_ZORDER 10

enum class ROLE_STATE{
	ROLE_INVALID_STATE = 0,
	ROLE_RUN_STATE,
	ROLE_JUMP_UP_STATE,
	ROLE_JUMP_DOWN_STATE,
	ROLE_STAND_BY
};

//�����ж���ײ�����ö����
enum class COLL_STATE
{
	COLL_INVALID_STATE = 0,
	COLL_TOP,
	COLL_BOTTOM,
	COLL_LEFT,
	COLL_RIGHT
};

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
	CC_SYNTHESIZE(ROLE_STATE, currentRoleState,CurrentRoleState);
	CC_SYNTHESIZE(float, xSpeed, Xspeed);
	CC_SYNTHESIZE(float, ySpeed, Yspeed);
	CC_SYNTHESIZE(float, constxSpeed, ConstXspeed);//Ϊ�˻ָ�ԭ�ٶȶ���
	CC_SYNTHESIZE(float, constySpeed, ConstYspeed);
	void role_update(float dt);
	void role_logic();
private:
	void runLogic();
	void jumpUpLogic();
	void jumpDownLogic();
private:
	cocos2d::Sprite *mSprite;
private:
	//���������λ�õ����þ�ͷ
	void setMapPointByRole();
	void camera_update(float delta);
private:
	//��ײ����⺯��
	bool isCollWithCollArea(COLL_STATE collState);
	bool isCollisionWithLeft(cocos2d::Rect Box);
	bool isCollisionWithRight(cocos2d::Rect Box);
	bool isCollisionWithTop(cocos2d::Rect Box);
	bool isCollisionWithBottom(cocos2d::Rect Box);

	void fixColl(COLL_STATE collState ,cocos2d::Rect);
private:
	float acceleration;
};


#endif // Role_h__
