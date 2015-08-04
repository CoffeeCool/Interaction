//
//  MapEntity.h
//  Interaction
//
//  Created by Coffee on 15/8/4.
//
//

#ifndef __Interaction__MapEntity__
#define __Interaction__MapEntity__

#include "cocos2d.h"



class MapEntity : public cocos2d::Sprite {
public:
    static MapEntity* create(int color, int width);
private:
    virtual bool init(int color, int width);
    virtual void update(float delay);
    MapEntity();
    ~MapEntity();
    
    CC_SYNTHESIZE(int, m_boardColor, BoardColor);
    CC_SYNTHESIZE(float, m_boardWidth, BoardWidth);
    CC_SYNTHESIZE(float, m_boardSpeed, BoardSpeed);
    CC_SYNTHESIZE(bool, m_isLastOne, IsLastOne);
};


#endif /* defined(__Interaction__MapEntity__) */
