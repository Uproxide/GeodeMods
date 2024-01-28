#include <Geode/binding/MenuLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

		auto posX = winSize.width / 2 + 60.f;
		auto posY = winSize.height / 2 + 71.f;

        auto evilLabel1 = CCLabelBMFont::create("Evil", "goldFont.fnt");

		evilLabel1->setScale(1.0f);
        evilLabel1->setID("evil-label");
		evilLabel1->setPosition(107.500, 307);
		evilLabel1->setColor(ccc3(106, 0, 0));

        this->addChild(evilLabel1);

        auto evilLabel2 = CCLabelBMFont::create("Evil", "goldFont.fnt");

		evilLabel2->setScale(0.7f);
        evilLabel2->setID("evil-label-2");
		evilLabel2->setPosition(46.500, 154);
		evilLabel2->setColor(ccc3(197, 0, 0));

        this->addChild(evilLabel2);

        auto mainTitle = dynamic_cast<cocos2d::CCSprite*>(this->getChildByID("main-title"));
		mainTitle->setColor(ccc3(255, 0, 0));

        auto userText = dynamic_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("player-username"));
        userText->setColor(ccc3(197, 0, 0));

        return true;
    }
};
