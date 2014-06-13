/*
 * =====================================================================================
 *
 *       Filename:  MenuActivity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/03/2014 18:23:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

MenuActivity::MenuActivity(Activity *parent) : Activity(parent) {
	m_type = Type::Menu;
	
	loadCommandWindow();
	
	m_actorChoicewin = new ActorChoiceWindow(150, 0, GameWindow::main->width() - 150, GameWindow::main->height());
	
	m_actorChoiceMode = false;
}

MenuActivity::~MenuActivity() {
	delete m_actorChoicewin;
	
	delete m_cmdwin;
}

void MenuActivity::loadCommandWindow() {
	m_cmdwin = new CommandWindow(150);
	
	m_cmdwin->addCommand("Items");
	m_cmdwin->addCommand("Skills", true);
	m_cmdwin->addCommand("Equip");
	m_cmdwin->addCommand("State", true);
	m_cmdwin->addCommand("Save", true);
	m_cmdwin->addCommand("Settings");
	m_cmdwin->addCommand("Quit");
}

void MenuActivity::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::GameAttack)) {
		if(m_cmdwin->disabled(m_cmdwin->pos())) {
			Sound::Effect::play(Sound::Effect::blocked);
		} else {
			Sound::Effect::play(Sound::Effect::confirm);
			
			if(m_actorChoiceMode) {
				m_actorChoiceMode = false;
				
				switch(m_cmdwin->pos()) {
					case 1: break;
					case 2:
						ActivityManager::push(new EquipActivity(m_actorChoicewin->pos(), this));
						break;
					case 3: break;
					default: break;
				}
			} else {
				switch(m_cmdwin->pos()) {
					case 0:
						ActivityManager::push(new ItemActivity(this));
						break;
					case 4: break;
					case 5:
						ActivityManager::push(new SettingsActivity(this));
						break;
					case 6:
						ActivityManager::push(new EndActivity);
						break;
					default:
						m_actorChoiceMode = true;
						break;
				}
			}
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::GameBack)) {
		Sound::Effect::play(Sound::Effect::back);
		if(!m_actorChoiceMode) ActivityManager::pop();
		else {
			m_actorChoiceMode = false;
			m_actorChoicewin->pos(0);
		}
	}
	
	if(!m_actorChoiceMode) m_cmdwin->update();
	else m_actorChoicewin->update();
}

void MenuActivity::render() {
	SDL_RenderCopy(GameWindow::main->renderer(), m_background, NULL, NULL);
	
	m_cmdwin->draw(ActivityManager::top() == this && !m_actorChoiceMode);
	
	if(m_actorChoiceMode) {
		m_actorChoicewin->draw();
	}
}

