//
//  GameScene.cpp
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#include "GameScene.h"
#include "DefaultSettings.h"
#include "BackgroudManager.h"
USING_NS_CC;


Scene* GameScene::createScene() {
    
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init() {
    
    if (!Layer::init()) {
        return false;
    }
    BackgroundManager::getInstance()->addGameEntity(this);
    schedule([this](float delay){
        BackgroundManager::getInstance()->update(delay,this);
    }, "gameRun");
    
    return true;
}