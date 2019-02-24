/*
 * =====================================================================================
 *
 *       Filename:  SkillLoader.cpp
 *
 *    Description:
 *
 *        Created:  17/02/2019 21:51:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "ResourceHelper.hpp"
#include "Skill.hpp"
#include "SkillLoader.hpp"

void SkillLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *skillElement = doc.FirstChildElement("skills").FirstChildElement("skill").ToElement();
	u16 id = 0;
	while(skillElement) {
		Skill &skill = handler.add<Skill>("skill-" + std::to_string(id),
			"Skill" + std::to_string(id),
			"Skill" + std::to_string(id) + "Desc",
			"texture-skill-" + std::to_string(id),
			skillElement->IntAttribute("damage"),
			skillElement->DoubleAttribute("hitRate")
		);

		skill.setID(id);

		skillElement = skillElement->NextSiblingElement("skill");
		id++;
	}
}

