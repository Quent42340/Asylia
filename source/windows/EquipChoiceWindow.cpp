/*
 * =====================================================================================
 *
 *       Filename:  EquipChoiceWindow.cpp
 *
 *    Description:
 *
 *        Created:  17/04/2014 20:45:29
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Color.hpp"
#include "Config.hpp"
#include "EquipChoiceWindow.hpp"
#include "ResourceHelper.hpp"

EquipChoiceWindow::EquipChoiceWindow(Equipment *equipment) : SelectableWindow(150 + (SCREEN_WIDTH - 150) / 2, 52, (SCREEN_WIDTH - 150) / 2, (SCREEN_HEIGHT - 52) / 2) {
	m_itemMax = 4;
	m_columnMax = 1;

	m_pos = 0;

	m_equipment = equipment;
}

// void EquipChoiceWindow::draw(bool drawCursor) {
void EquipChoiceWindow::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	Window::draw(target, states);

	states.transform *= getTransform();

	if(!m_equipment->weapon()) {
		// FIXME
		// ResourceHelper::getWeapon(0)->thumbnail().render(m_x + 20, m_y + 20);

		// FIXME
		gk::Text text{_t("Empty"), "font-default", 18};
		text.setColor(Color::System);
		text.setStyle(gk::Text::Italic);
		text.setPosition(48, 20);
		target.draw(text, states);

		// ResourceHelper::getFont("default").setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
		// ResourceHelper::getFont("default").printScaled(_t("Empty").c_str(), m_x + 48, m_y + 20, m_width - 40, 32, FONT_LARGE, Color::System);
		// ResourceHelper::getFont("default").setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
	} else {
		// m_equipment->weapon()->thumbnail().render(m_x + 20, m_y + 20);

		// FIXME
		gk::Text text{m_equipment->weapon()->name(), "font-default", 18};
		text.setPosition(48, 20);
		target.draw(text, states);

		// ResourceHelper::getFont("default").printScaled(m_equipment->weapon()->name().c_str(), m_x + 48, m_y + 20, m_width - 40, 32, FONT_LARGE);
	}

	for(u8 slot = 0 ; slot < 3 ; slot++) {
		Armor *armor = m_equipment->armor(slot);
		if(!armor) {
			// for(auto &it : ResourceHelper::getInstance().armors()) {
			// 	if(it->slot() == slot) {
			// 		it->thumbnail().render(m_x + 20, m_y + 52 + slot * 32);
			// 		break;
			// 	}
			// }

			// FIXME
			gk::Text text{_t("Empty"), "font-default", 18};
			text.setColor(Color::System);
			text.setStyle(gk::Text::Italic);
			text.setPosition(48, 52 + slot * 32);
			target.draw(text, states);

			// ResourceHelper::getFont("default").setStyle(FONT_LARGE, TTF_STYLE_ITALIC);
			// ResourceHelper::getFont("default").printScaled(_t("Empty").c_str(), m_x + 48, m_y + 52 + slot * 32, m_width - 40, 32, FONT_LARGE, Color::System);
			// ResourceHelper::getFont("default").setStyle(FONT_LARGE, TTF_STYLE_NORMAL);
		} else {
			// armor->thumbnail().render(m_x + 20, m_y + 52 + slot * 32);

			// FIXME
			gk::Text text{armor->name(), "font-default", 18};
			text.setPosition(48, 52 + slot * 32);
			target.draw(text, states);

			// ResourceHelper::getFont("default").printScaled(armor->name().c_str(), m_x + 48, m_y + 52 + slot * 32, m_width - 40, 32, FONT_LARGE);
		}
	}
}

