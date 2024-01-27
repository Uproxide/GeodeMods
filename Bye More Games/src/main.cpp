#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

class $modify(MenuLayer) {
	bool init() {
		if(!MenuLayer::init())
			return false;
		auto moreGames = this->getChildByID("more-games-menu");
		moreGames->setVisible(false);
		return true;
	}
};
