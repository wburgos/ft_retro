/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 09:09:10 by wburgos          ###   ########.fr       */
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
	_p1 = new Player(stdscr, 0, _height / 2);
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
	_p1->update();
	refresh();
}

int					GameEngine::getInput(void) const
{
	return (_input);
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
