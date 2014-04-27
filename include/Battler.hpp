/*
 * =====================================================================================
 *
 *       Filename:  Battler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/04/2014 19:29:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLER_HPP_
#define BATTLER_HPP_

class Battler {
	public:
		Battler(std::string name, std::string appearance, u8 level, s16 hp, s16 sp, u16 atk, u16 def);
		~Battler();
		
		void linkInventory(Inventory *inventory) { m_inventory = inventory; }
		
		std::string name() const { return m_name; }
		
		Image *image() const { return m_image; }
		
		u8 level() const { return m_level; }
		
		s16 hp() const { return m_hp; }
		s16 sp() const { return m_sp; }
		
		u16 atk() const { return m_atk; }
		u16 def() const { return m_def; }
		
		u16 totalAtk();
		u16 totalDef();
		
	protected:
		std::string m_name;
		
		Image *m_image;
		
		Inventory *m_inventory;
		
		u8 m_level;
		
		s16 m_hp;
		s16 m_sp;
		
		u16 m_atk;
		u16 m_def;
};

#endif // BATTLER_HPP_