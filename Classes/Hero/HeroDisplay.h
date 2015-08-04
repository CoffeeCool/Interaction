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
USING_NS_CC;
enum HeroDisplayType{
    green = 0,
    stone = 1,
    purple = 2,
    yellow = 3
};

class HeroDisplay : public cocos2d::Sprite{
private:
    float m_scale;
    CC_SYNTHESIZE(HeroDisplayType, m_displayType, DisplayType);
    CC_SYNTHESIZE(int, m_speedX, SpeedX);
    CC_SYNTHESIZE(int, m_speedY, SpeedY);
    CC_SYNTHESIZE(int, m_angel, Angel);
    virtual bool init(HeroDisplayType displayType);
    virtual void update(float delay);
    
public:
    static HeroDisplay* create(HeroDisplayType displayType);
    
};

#endif /* defined(__Interaction__HeroDisplay__) */
