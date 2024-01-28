#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/binding/LevelInfoLayer.hpp>
using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
        if (!LevelInfoLayer::init(level, challenge)) return false;

		// get the background and other shit and make it EEVILLLLLLLLLLLLLLLLLLLL
		auto difficultySprite = dynamic_cast<GJDifficultySprite*>(this->getChildByID("difficulty-sprite"));
		difficultySprite->setColor(ccc3(255, 0, 0));

		auto grandpaDemonDifficultySprite = dynamic_cast<cocos2d::CCSprite*>(this->getChildByID("grd-difficulty"));
		
		if (grandpaDemonDifficultySprite)
		{
			grandpaDemonDifficultySprite->setColor(ccc3(255, 0, 0));
		}
		else 
		{
			// balls
		}

		auto title = dynamic_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("title-label"));
		title->setColor(ccc3(255, 76, 76));

		auto user = dynamic_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("creator-info-menu")->getChildByID("creator-name")->getChildren()->objectAtIndex(0));
		user->setColor(ccc3(205, 0, 0));

		auto background = dynamic_cast<cocos2d::CCSprite*>(this->getChildByID("background"));
		background->setColor(ccc3(106, 0, 0));

		auto highObjects = dynamic_cast<cocos2d::CCSprite*>(this->getChildByID("high-object-indicator"));
		if (highObjects)
		{
			highObjects->setVisible(false);
		}
		else
		{
			// balls
		}

		auto copy = dynamic_cast<cocos2d::CCSprite*>(this->getChildByID("copy-indicator"));
		if (copy)
		{
			copy->setVisible(false);
		}
		else
		{
			// balls
		}

		auto daily = dynamic_cast<cocos2d::CCLabelBMFont*>(this->getChildByID("daily-label"));
		if (daily)
		{
			std::string dailyString = daily->getString();
			if (dailyString == "(Daily)")
			{
				daily->setString("(Devil Daily)");
				daily->setColor(ccc3(165, 0, 0));
				daily->setPosition(238, 259.500);
			}
			else if (dailyString == "(Weekly)")
			{
				daily->setString("(Evil Weekly)");
				daily->setColor(ccc3(165, 0, 0));
				daily->setPosition(238, 259.500);
			}
		}
		else
		{
			// balls
		}

		// set the names and shit
		std::string levelName = title->getString();
		title->setString(("Evil " + levelName).c_str());

		std::string levelUsername = user->getString();
		levelUsername = levelUsername.substr(3);

		user->setString(("By Evil " + levelUsername).c_str());

		return true;
	}
};
