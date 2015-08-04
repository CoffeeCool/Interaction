//
//  BackgroudManager.h
//  Interaction
//
//  Created by Coffee on 15/7/31.
//
//

#ifndef __Interaction__BackgroudManager__
#define __Interaction__BackgroudManager__

#include "cocos2d.h"
#include "DefaultSettings.h"
#include "HeroDisplay.h"
#include "GameScene.h"
#include "MapEntity.h"
USING_NS_CC;
class BackgroundManager {
private:
    
    BackgroundManager();
    static BackgroundManager* sm_instance;
    CC_SYNTHESIZE(Sprite*, m_title, Title);
    CC_SYNTHESIZE(Sprite*, m_background_1, Background_1);
    CC_SYNTHESIZE(Sprite*, m_background_2, Background_2);
    CC_SYNTHESIZE(Sprite*, m_startCloud, StartCloud);
    CC_SYNTHESIZE(Sprite*, m_startTriangle,StartTriangle);
    CC_SYNTHESIZE(Sprite*, m_house, House);
    CC_SYNTHESIZE(Sprite*, m_rank, Rank);
    CC_SYNTHESIZE(Sprite*, m_music, Music);
    CC_SYNTHESIZE(int, m_speed, Speed);
    Vector<MapEntity*> m_mapEntities;
    int m_heightForNewBoard;
    void addHouse(Layer* layer);
    void addBackground(Layer* layer);
    void addStartButton(Layer* layer);//开始游戏
    void addFunctionButton(Layer* layer);
    void addDisplayHeros(Layer* layer);
    void addTitle(Layer* layer);
public:
    
    static BackgroundManager* getInstance();
    void addStartEntity(Layer* layer);//添加开始界面实体
    void addGameEntity(Layer* layer);//添加游戏界面实体
    void addBoard(Layer* layer);
    void update(float delay, Layer* layer);
};

#endif /* defined(__Interaction__BackgroudManager__) */
