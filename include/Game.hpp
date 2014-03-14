/*
 * =====================================================================================
 *
 *       Filename:  Game.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/03/2014 21:27:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef GAME_HPP_
#define GAME_HPP_

class Game {
	public:
		Game();
		~Game();
		
		void SDLinit();
		void SDLquit();
		
		static void mainLoop(void (*processInputs_)(void) = &processInputs,
							 void (*update_)(void) = &update,
							 void (*render_)(void) = &render);
		
		static void processInputs();
		static void update();
		static void render();
		
		static void pollEvents(bool *quit = NULL);
		
		static bool quit;
};

#endif // GAME_HPP_