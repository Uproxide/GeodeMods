#include <Geode/Geode.hpp>
#include <geode.custom-keybinds/include/Keybinds.hpp>
#include <Geode/cocos/CCDirector.h>

using namespace geode::prelude;
using namespace keybinds;


$execute {
    BindManager::get()->registerBindable({
        "QQ"_spr,
        "Quit Da Gam",
        "Quit Ples",
        { Keybind::create(KEY_Q, Modifier::None) },
        "Quit"
    });

	 new EventListener([=](InvokeBindEvent* event) {
		auto active = Mod::get()->getSettingValue<bool>("active");
		if (active)
		{
			CCDirector::sharedDirector()->end();
		}
	return ListenerResult::Propagate;
    }, InvokeBindFilter(nullptr, "QQ"_spr));
}
