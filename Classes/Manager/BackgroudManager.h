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
USING_NS_CC;
class BackgroudManager {
private:
    
    BackgroudManager();
    static BackgroudManager* sm_instance;
    CC_SYNTHESIZE(Sprite*, m_title, Title);
    CC_SYNTHESIZE(Sprite*, m_background_1, Background_1);
    CC_SYNTHESIZE(Sprite*, m_background_2, Background_2);
    CC_SYNTHESIZE(Sprite*, m_startCloud, StartCloud);
    CC_SYNTHESIZE(Sprite*, m_startTriangle,StartTriangle);
    CC_SYNTHESIZE(Sprite*, m_house, House);
    CC_SYNTHESIZE(Sprite*, m_rank, Rank);
    CC_SYNTHESIZE(Sprite*, m_music, Music);
    
    void addHouse(Layer* layer);
    void addBackground(Layer* layer);
    void addStartButton(Layer* layer);
    void addFunctionButton(Layer* layer);
    void addDisplayHeros(Layer* layer);
    void addTitle(Layer* layer);
public:
    
    static BackgroudManager* getInstance();
    void addStartEntity(Layer* layer);
    void addGameEntity(Layer* layer);
};

#endif /* defined(__Interaction__BackgroudManager__) */
