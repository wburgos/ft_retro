/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:49:46 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine::GameEngine(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, _height, _width);
	_p1 = new Player(stdscr);
	_win = stdscr;
}

GameEngine::~GameEngine(void)
{
	endwin();
}

GameEngine::GameEngine(GameEngine const &src) :
_win(src._win), _height(src._height), _width(src._width)
{
}

GameEngine		&GameEngine::operator=(GameEngine const &src)
{
	if (this != &src)
		_win = src._win;
	return (*this);
}

void				GameEngine::render(void)
{
	mvaddch(_height / 2, 0, _p1->getChar());
	move(0, 0);
	refresh();
}

void				GameEngine::acquireInput(void)
{
	_input = getch();
}

int					GameEngine::getInput(void) const
{
	return (_input);
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
