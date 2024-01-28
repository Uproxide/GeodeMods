#include <Geode/binding/InfoLayer.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class $modify(InfoLayer) {
    bool init(GJGameLevel* level, GJUserScore* score, GJLevelList* list) {
        if (!InfoLayer::init(level, score, list)) return false;

        auto title = static_cast<cocos2d::CCLabelBMFont*>(this->getChildByIDRecursive("title-label"));

        auto user = dynamic_cast<cocos2d::CCLabelBMFont*>(this->getChildByIDRecursive("main-menu")->getChildByIDRecursive("creator-button")->getChildren()->objectAtIndex(0));


        std::string levelName = title->getString();
		title->setString(("Evil " + levelName).c_str());

        std::string levelUsername = user->getString();
		levelUsername = levelUsername.substr(3);

		user->setString(("By Evil " + levelUsername).c_str());

        return true;
    }
};