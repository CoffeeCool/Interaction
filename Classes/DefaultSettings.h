//
//  DefaultSettings.h
//  Interaction
//
//  Created by Coffee on 15/8/3.
//
//

#ifndef Interaction_DefaultSettings_h
#define Interaction_DefaultSettings_h
#define DEFAULT_MAX_SCREEN_WIDTH 1080
#define DEFAULT_MAX_SCREEN_HEIGHT 1920
#define DEFAULT_MIN_SCREEN_WIDTH 640
#define DEFAULT_MIN_SCREEN_HEIGHT 1136
#define DEFAULT_IPHONE4S_SCREEN_HEIGHT 960
#define DEFAULT_IPHONE6_SCREEN_WIDTH 750
#define DEFAULT_IPHONE6_SCREEN_HEIGHT 1334
#define VISIBLE_SIZE_WIDTH Director::getInstance()->getVisibleSize().width
#define VISIBLE_SIZE_HEIGHT Director::getInstance()->getVisibleSize().height
#define ENTITY_SPACE 100*Director::getInstance()->getVisibleSize().width/750
#define BOARD_MIN_WIDTH 200*Director::getInstance()->getVisibleSize().width/750
#define BOARD_MAX_WIDTH 350*Director::getInstance()->getVisibleSize().width/750
enum ColorType{
    green = 0,
    stone = 1,
    purple = 2,
    yellow = 3
};
#endif
