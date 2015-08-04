//
//  GameScene.h
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#ifndef __Interaction__GameScene__
#define __Interaction__GameScene__
#include "cocos2d.h"

class GameScene: public cocos2d::Layer {
    
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameScene);
};

#endif /* defined(__Interaction__GameScene__) */
