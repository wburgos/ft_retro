/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 00:16:09 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine		&GameEngine::operator=(GameEngine const &rhs)
{
	return *this = rhs;
}

GameEngine::GameEngine(void)
{
	_height = 0;
	_width = 0;
	_startX = (LINES - _height) / 2;
	_startY = (COLS - _width) / 2;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	printw("Press F5 to exit");
	refresh();
	noecho();

	WINDOW	*localWin;

	localWin = newwin(_height, _width, _startY, _startX);
	box(localWin, 0 , 0);		 //0, 0 gives default characters for the vertical and horizontal lines
	// wborder(_win, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	wrefresh(localWin);

	_win = localWin;
}

GameEngine::~GameEngine(void)
{
	delwin(_win);
	endwin();
}

GameEngine::GameEngine(GameEngine const &src)
{
	*this = src;
}

void		GameEngine::createNewWin(void)
{

}

void		GameEngine::destroyWin(void)
{
	wborder(_win, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(_win);
	delwin(_win);
}

WINDOW		*GameEngine::getWindow(void)
{
	return _win;
}
