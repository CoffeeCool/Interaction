//
//  HeroDisplay.h
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#ifndef __Interaction__HeroDisplay__
#define __Interaction__HeroDisplay__

#include "cocos2d.h"
#include "DefaultSettings.h"
USING_NS_CC;


class HeroDisplay : public cocos2d::Sprite{
private:
    float m_scale;
    CC_SYNTHESIZE(int, m_displayType, DisplayType);
    CC_SYNTHESIZE(int, m_speedX, SpeedX);
    CC_SYNTHESIZE(int, m_speedY, SpeedY);
    CC_SYNTHESIZE(int, m_angel, Angel);
    virtual bool init(int displayType);
    virtual void update(float delay);
    
public:
    static HeroDisplay* create(int displayType);
    
};

#endif /* defined(__Interaction__HeroDisplay__) */
