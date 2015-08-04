//
//  BackgroudManager.cpp
//  Interaction
//
//  Created by Coffee on 15/7/31.
//
//

#include "BackgroudManager.h"
#include "DefaultSettings.h"
#include "HeroDisplay.h"
#include "GameScene.h"
BackgroudManager* BackgroudManager::sm_instance;

void BackgroudManager::addStartEntity(cocos2d::Layer *layer){
    addBackground(layer);
    addHouse(layer);
    addFunctionButton(layer);
    addTitle(layer);
    addDisplayHeros(layer);
    addStartButton(layer);
}

void BackgroudManager::addGameEntity(cocos2d::Layer *layer) {
    addBackground(layer);
    addHouse(layer);
}


BackgroudManager* BackgroudManager::getInstance() {
    
    if (sm_instance == NULL) {
        sm_instance = new BackgroudManager();
    }
    return sm_instance;
}

BackgroudManager::BackgroudManager() {
}

void BackgroudManager::addHouse(cocos2d::Layer* layer) {
    m_house = Sprite::create("background/house.png");
    m_house->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_house->setAnchorPoint(Vec2::ZERO);
    layer->addChild(m_house);
}

void BackgroudManager::addBackground(cocos2d::Layer *layer) {
    
    m_background_1 = Sprite::create("background/background.png");
    m_background_2 = Sprite::create("background/background.png");
    m_background_1->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_background_2->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_background_1->setAnchorPoint(Vec2::ZERO);
    m_background_2->setAnchorPoint(Vec2::ZERO);
    m_background_1->setPosition(0, 0);
    m_background_2->setPosition(0, VISIBLE_SIZE_HEIGHT);
    layer->addChild(m_background_1);
    layer->addChild(m_background_2);
}

void BackgroudManager::addStartButton(cocos2d::Layer *layer) {

    m_startCloud = Sprite::create("background/startCloud.png");
    m_startTriangle = Sprite::create("background/startTriangle.png");
    //        m_startCloud->setScale(m_visibaleSize.width/1080);
    //        m_startTriangle->setScale(m_visibaleSize.width/1080);
    m_startCloud->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/2);
    m_startTriangle->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT/2);
    m_startCloud->runAction(RepeatForever::create(RotateBy::create(10, 360)));
    layer->addChild(m_startCloud);
    layer->addChild(m_startTriangle);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch* t, Event* e){
        auto position = t->getLocation();
        if (this->m_startTriangle->getBoundingBox().containsPoint(position)) {

            CCLOG("getTouch!!!");
        }
        else {
            CCLOG("MISS!");
        }
        return true;
    };
    listener->onTouchEnded = [this](Touch* t, Event* e){
        auto position = t->getLocation();
        if (this->m_startTriangle->getBoundingBox().containsPoint(position)) {
            

            auto sceneWillDisplay = TransitionCrossFade::create(1, GameScene::createScene());
            Director::getInstance()->replaceScene(sceneWillDisplay);
        }
        CCLOG("END!");
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
    
    
}

void BackgroudManager::addFunctionButton(cocos2d::Layer *layer) {
    m_rank = Sprite::create("background/rank.png");
    m_music = Sprite::create("background/music.png");
    m_rank->setPosition(VISIBLE_SIZE_WIDTH*33/36,VISIBLE_SIZE_HEIGHT - m_rank->getContentSize().height/2);
    m_music->setPosition(VISIBLE_SIZE_WIDTH*27/36,VISIBLE_SIZE_HEIGHT - m_rank->getContentSize().height/2);
    m_rank->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    m_music->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    layer->addChild(m_rank);
    layer->addChild(m_music);
}

void BackgroudManager::addTitle(cocos2d::Layer *layer)  {
    m_title = Sprite::create("background/title.png");
    m_title->setPosition(VISIBLE_SIZE_WIDTH/2, VISIBLE_SIZE_HEIGHT*3/4);
    m_title->setScale(VISIBLE_SIZE_WIDTH/DEFAULT_MAX_SCREEN_WIDTH);
    layer->addChild(m_title);
}


void BackgroudManager::addDisplayHeros(cocos2d::Layer *layer) {
    auto heroDisplay1 = HeroDisplay::create(HeroDisplayType::green);
    auto heroDisplay2 = HeroDisplay::create(HeroDisplayType::stone);
    auto heroDisplay3 = HeroDisplay::create(HeroDisplayType::purple);
    auto heroDisplay4 = HeroDisplay::create(HeroDisplayType::yellow);
    layer->addChild(heroDisplay1);
    layer->addChild(heroDisplay2);
    layer->addChild(heroDisplay3);
    layer->addChild(heroDisplay4);
}
