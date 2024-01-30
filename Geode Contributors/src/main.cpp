#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/binding/ProfilePage.hpp>
#include <Geode/Bindings.hpp>
#include <Geode/loader/Loader.hpp>
#include <algorithm>
#include <cctype>

using namespace geode::prelude;

// sorry for the mess, im not the c++ coder lmfao

class MyLayer : public CCLayer {
	public:
	void onButtonClick(CCObject* sender) {
		FLAlertLayer::create(
			"About",
			"This badge is given to <cp>Geode Contributors</c>. If you have contributed to geode in anyway (Bindings, Main Geode Loader/Mod, Etc...), You will obtain this badge. (Don't have the Badge? Read the about.md!)",
			"OK"
		)->show();
	}
};

class $modify(ProfilePage) {
	bool m_hasBeenOpened = false;

	bool init(int p0, bool p1) {
		if (!ProfilePage::init(p0, p1)) return false;

		std::set<int> geodeContributors = {25397826, 5568872, 3516725, 11535118, 761691, 104257, 807756, 16778880};
																									

		m_mainLayer->removeChildByID("my-stuff-hint");
		auto mainMenu = static_cast<cocos2d::CCLayer*>(this->getChildByIDRecursive("main-menu"));
		auto spr = CCSprite::create("geode.png"_spr);
		auto btn = CCMenuItemSpriteExtra::create(
       		spr, this, menu_selector(MyLayer::onButtonClick)
    	);
		auto contentSize = mainMenu->getContentSize();


		btn->setPosition(375.500, -11);
		btn->setZOrder(26);
		btn->setID("geode-badge");
		mainMenu->addChild(btn);
		btn->setVisible(false);

		std::string username = m_usernameLabel->getString();

		if (geodeContributors.count(p0) > 0) 
		{
			btn->setVisible(true);
        }
		else
		{
			// how many times do we have to tell you this old man
		}

		auto posX = m_usernameLabel->getPositionX();
		auto posY = m_usernameLabel->getPositionY();


		return true;
	}

	void loadPageFromUserInfo(GJUserScore* score)
	{
		ProfilePage::loadPageFromUserInfo(score);
		

		auto infoButton = static_cast<CCMenuItemSpriteExtra*>(this->getChildByIDRecursive("main-menu")->getChildByID("info-button"));
		infoButton->setPosition(205.412, -129.013);
	}
};
