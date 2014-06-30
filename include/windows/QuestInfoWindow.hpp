/*
 * =====================================================================================
 *
 *       Filename:  QuestInfoWindow.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  30/06/2014 18:50:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef QUESTINFOWINDOW_HPP_
#define QUESTINFOWINDOW_HPP_

class QuestInfoWindow : public Window {
	public:
		QuestInfoWindow();
		~QuestInfoWindow();
		
		void draw(Quest *quest);
};

#endif // QUESTINFOWINDOW_HPP_
