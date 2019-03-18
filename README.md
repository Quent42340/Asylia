# Asylia

[![Build Status](https://travis-ci.com/Quent42340/Asylia.svg?branch=master)](https://travis-ci.com/Quent42340/Asylia)
[![Documentation](https://codedocs.xyz/Quent42340/Asylia.svg)](https://codedocs.xyz/Quent42340/Asylia/)
[![License](https://img.shields.io/badge/license-LGPLv2.1%2B-blue.svg)](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html)

- Asylia is a classic RPG game engine made with SDL 2.0 and written in C++.
- It uses XML for configuration scripts, and Lua for modding/event management.

**Note:** I originally made this project in 2014. It's old, there's probably a lot of design issues, but I decided to migrate it to GameKit in order to keep consistency between my old projects.

- [Screenshots](#screenshots)
- [Keys](#keys)
- [How to compile](#how-to-compile)

## Screenshots

![](screenshot1.png?raw=true)
![](screenshot2.png?raw=true)
![](screenshot3.png?raw=true)

## Keys

- Movement: <kbd>&larr;</kbd> <kbd>&uarr;</kbd> <kbd>&darr;</kbd> <kbd>&rarr;</kbd>
- Start: <kbd>Esc</kbd>
- A: <kbd>Enter</kbd>
- B: <kbd>Backspace</kbd>

## How to compile

- Dependencies:
    - [CMake](http://www.cmake.org/download/)
    - [GameKit](http://github.com/Quent42340/GameKit) (requires `SDL2` + `tinyxml2`, will switch to `SFML` starting from 2.6)
    - [Lua](http://www.lua.org)
    - _Linux users: Check your distribution repositories for packages._
- Run `cmake . && make -j8`
- Run the game, enjoy!

