/*
 * =====================================================================================
 *
 *       Filename:  SettingsState.cpp
 *
 *    Description:
 *
 *        Created:  03/05/2014 16:53:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "GameKey.hpp"
#include "SettingsState.hpp"

SettingsState::SettingsState(gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_settings.addCommand("Sound");
	m_settings.addCommand("Language");

	m_sound.addCommand("ON");
	m_sound.addCommand("OFF");

	m_language.addCommand("Français");
	m_language.addCommand("English");

	m_mode = Mode::Settings;
}

void SettingsState::update() {
	if(m_mode == Mode::Settings) {
		m_settings.update();

		if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			gk::AudioPlayer::playSound("sound-confirm");
			switch(m_settings.pos()) {
				case 0:
					m_mode = Mode::Sound;
					break;
				case 1:
					m_mode = Mode::Language;
					break;
				default: break;
			}
		}

		if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
			gk::AudioPlayer::playSound("sound-back");
			gk::ApplicationStateStack::getInstance().pop();
		}
	}
	else if(m_mode == Mode::Sound) {
		m_sound.update();

		if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			switch(m_sound.pos()) {
				case 0:
					gk::AudioPlayer::setMuteState(false);
					gk::AudioPlayer::playMusic("music-theme");
					gk::AudioPlayer::playSound("sound-confirm");
					break;
				case 1:
					gk::AudioPlayer::setMuteState(true);
					gk::AudioPlayer::pauseMusic();
					break;
				default: break;
			}
		}

		if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Settings;
		}
	}
	else if(m_mode == Mode::Language) {
		m_language.update();

		if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			gk::AudioPlayer::playSound("sound-confirm");
			switch(m_language.pos()) {
				case 0:
					LanguageManager::getInstance().init("fr-fr");
					break;
				case 1:
					LanguageManager::getInstance().init("en-us");
					break;
				default: break;
			}
		}

		if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
			gk::AudioPlayer::playSound("sound-back");
			m_mode = Mode::Settings;
			m_settings.pos(1);
		}
	}
}

void SettingsState::render() {
	if (m_parent)
		m_parent->render();

	if(m_mode == Mode::Settings) {
		m_settings.draw();
	}
	else if(m_mode == Mode::Sound) {
		m_settings.draw(false);

		m_sound.draw();
	}
	else if(m_mode == Mode::Language) {
		m_settings.draw(false);

		m_language.draw();
	}
}

