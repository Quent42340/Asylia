/*
 * =====================================================================================
 *
 *       Filename:  LanguageManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/2014 13:51:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Asylia.hpp"

std::map<std::string, std::string> LanguageManager::text;
std::string LanguageManager::currentLanguage;

void LanguageManager::init(std::string language) {
	if(text.size() > 0) text.clear();
	
	currentLanguage = language;
	
	XMLDocument xml;
	int code = xml.LoadFile(std::string(std::string("data/locale/") + language + std::string(".xml")).c_str());
	if(code == XML_ERROR_FILE_NOT_FOUND) {
		warning("Locale \"%s\" not supported. Using \"en-us\" by default.", language.c_str());
		init("en-us");
		return;
	}
	else if(code != XML_NO_ERROR) {
		error("Failed to load locale data: %s (CODE: %d)", language.c_str(), code);
		exit(EXIT_FAILURE);
	}
	
	XMLHandle doc(&xml);
	
	/* INTERFACE */
	XMLElement *textElement = doc.FirstChildElement("language").FirstChildElement("text").ToElement();
	while(textElement) {
		text[textElement->Attribute("id")] = textElement->Attribute("text");
		textElement = textElement->NextSiblingElement("text");
	}
	
	/* EVENTS */
	XMLElement *eventElement = doc.FirstChildElement("language").FirstChildElement("event").ToElement();
	std::string name;
	u8 counter = 0;
	while(eventElement) {
		name = eventElement->Attribute("name");
		XMLElement *eventMessageElement = eventElement->FirstChildElement("message");
		while(eventMessageElement) {
			text[name + "-" + to_string(counter)] = eventMessageElement->Attribute("text");
			eventMessageElement = eventMessageElement->NextSiblingElement("message");
			counter++;
		}
		counter = 0;
		eventElement = eventElement->NextSiblingElement("event");
	}
	
	/* ITEMS */
	XMLElement *itemElement = doc.FirstChildElement("language").FirstChildElement("item").ToElement();
	counter = 0;
	while(itemElement) {
		text[std::string("Item") + to_string(counter)] = itemElement->Attribute("name");
		text[std::string("Item") + to_string(counter) + "Desc"] = itemElement->Attribute("description");
		
		itemElement = itemElement->NextSiblingElement("item");
		counter++;
	}
	
	/* ARMORS */
	XMLElement *armorElement = doc.FirstChildElement("language").FirstChildElement("armor").ToElement();
	counter = 0;
	while(armorElement) {
		text[std::string("Armor") + to_string(counter)] = armorElement->Attribute("name");
		text[std::string("Armor") + to_string(counter) + "Desc"] = armorElement->Attribute("description");
		
		armorElement = armorElement->NextSiblingElement("armor");
		counter++;
	}
	
	/* WEAPONS */
	XMLElement *weaponElement = doc.FirstChildElement("language").FirstChildElement("weapon").ToElement();
	counter = 0;
	while(weaponElement) {
		text[std::string("Weapon") + to_string(counter)] = weaponElement->Attribute("name");
		text[std::string("Weapon") + to_string(counter) + "Desc"] = weaponElement->Attribute("description");
		
		weaponElement = weaponElement->NextSiblingElement("weapon");
		counter++;
	}
	
	/* SKILLS */
	XMLElement *skillElement = doc.FirstChildElement("language").FirstChildElement("skill").ToElement();
	counter = 0;
	while(skillElement) {
		text[std::string("Skill") + to_string(counter)] = skillElement->Attribute("name");
		text[std::string("Skill") + to_string(counter) + "Desc"] = skillElement->Attribute("description");
		
		skillElement = skillElement->NextSiblingElement("skill");
		counter++;
	}
}

std::string LanguageManager::translate(std::string str) {
	std::string translated = LanguageManager::text[str];
	if(translated == "") translated = "???";
	return translated;
}

std::string _t(std::string str) {
	return LanguageManager::translate(str);
}

