/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 23:40:56 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine		&GameEngine::operator=(GameEngine const &rhs)
{
	return *this = rhs;
}

GameEngine::GameEngine(int hei, int wid, int x, int y): _height(hei), _width(wid), _startX(x), _startY(y)
{

}

GameEngine::~GameEngine(void)
{

}

GameEngine::GameEngine(GameEngine const &src)
{
	*this = src;
}

void		GameEngine::createNewWin(void)
{
	WINDOW	*localWin;

	localWin = newwin(this->_height, this->_width, this->_startY, this->_startX);
	box(localWin, 0 , 0);		/* 0, 0 gives default characters for the vertical and horizontal lines*/
	wborder(this->_win, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	wrefresh(localWin);

	this->_win = localWin;
}

void		GameEngine::destroyWin(void)
{
	// wborder(this->_win, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
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
	// wrefresh(this->_win);
	delwin(this->_win);
}

WINDOW		*GameEngine::getWindow(void)
{
	return this->_win;
}