#include <Geode/binding/ProfilePage.hpp>
#include <Geode/modify/ProfilePage.hpp>
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

        std::string usernameString = m_usernameLabel->getString();
        m_usernameLabel->setString(("Evil " + usernameString).c_str());

        
        return true;
    }
};