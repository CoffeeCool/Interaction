//
//  MapEntity.cpp
//  Interaction
//
//  Created by Coffee on 15/8/4.
//
//

#include "MapEntity.h"
#include "DefaultSettings.h"
USING_NS_CC;
MapEntity* MapEntity::create(int color, int width)
{
    MapEntity* sprite = new (std::nothrow) MapEntity();
    if (sprite && sprite->init(color, width)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

MapEntity::MapEntity():
m_boardSpeed(0),
m_boardWidth(0),
m_isLastOne(0)
{
    
}

MapEntity::~MapEntity()
{
}

bool MapEntity::init(int color, int width) {
    m_boardColor = color;
    m_boardWidth = width;
    m_boardSpeed = 5;
    switch (color) {
        case green: {
            this->initWithFile("texture/green.png");
            Texture2D* tex = Director::getInstance()->getTextureCache()->addImage("texture/green.png");
            Texture2D::TexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT,GL_REPEAT};
            tex->setTexParameters(tp);
            setTexture(tex);
            setTextureRect(Rect(0,0,width, 50));
        }
            
            break;
        case stone:
            this->initWithFile("texture/stone.png");
            break;
        case purple:
            this->initWithFile("texture/purple.png");
            break;
        case yellow:
            this->initWithFile("texture/yellow.png");
            break;
        default:
            break;
    }
    this->scheduleUpdate();
    return true;
}


void MapEntity::update(float delay) {
    setPosition(this->getPositionX(), this->getPositionY() - m_boardSpeed);
    if (getPositionY() <= 0) {
        this->removeFromParent();
    }
}
