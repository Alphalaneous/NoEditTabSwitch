#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(EditorUI) {
	
	struct Fields {
		bool ignoreEditButton = false;
	};

	void onPlaytest(cocos2d::CCObject* sender){
		if(m_playtestStopBtn->isVisible() && !m_positionSlider->isVisible()){
			EditorUI::onPlaytest(sender);
			if(m_selectedMode == 2){
				m_tabsMenu->setVisible(true);
			}
		}
		else{
			m_fields->ignoreEditButton = true;
			EditorUI::onPlaytest(sender);
			m_tabsMenu->setVisible(false);
			m_fields->ignoreEditButton = false;
		}
	}

    void toggleMode(cocos2d::CCObject* sender){
		if(!m_fields->ignoreEditButton){
			EditorUI::toggleMode(sender);
		}
	}

	void onStopPlaytest(cocos2d::CCObject* sender){
		EditorUI::onStopPlaytest(sender);
		if(m_selectedMode == 2){
			m_tabsMenu->setVisible(true);
		}
	}
};
