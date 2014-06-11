/*
 * =====================================================================================
 *
 *       Filename:  BattleAction.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/05/2014 13:57:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef BATTLEACTION_HPP_
#define BATTLEACTION_HPP_

class BattleAction {
	public:
		BattleAction(Battler *actor, Battler *receiver, Item *item);
		~BattleAction();
		
		void process();
		
		void updateDamages();
		bool drawDamages();
		
		Battler *actor() const { return m_actor; }
		Battler *receiver() const { return m_receiver; }
		
		bool animationAtEnd() const { return m_animationAtEnd; }
		
		void setReceiver(Battler *receiver) { m_receiver = receiver; }
		
	private:
		Battler *m_actor;
		Battler *m_receiver;
		
		Item *m_item;
		
		s32 m_damages;
		
		double m_variance;
		
		bool m_animationAtEnd;
		
		u16 m_dmgy;
		s8 m_dmgvy;
		u16 m_dmgmvcount;
};

#endif // BATTLEACTION_HPP_
