/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 03:16:22 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine		&GameEngine::operator=(GameEngine const &rhs)
{
	return *this = rhs;
}

GameEngine::GameEngine(Player *p1, Enemy *e1): _p1(p1), _e1(e1)
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
	box(localWin, 0 , 1);
	wrefresh(localWin);
	_win = localWin;
	wmove(_win, _p1->getX(), _p1->getY());
	wrefresh(_win);
}

void		GameEngine::fresh(void)
{
	box(_win, 0 , 1);
	wrefresh(_win);
}

void		GameEngine::move(int *ch)
{

	int x = _p1->getX();
	int y = _p1->getY();
	printw("x = %d",(*ch));
	switch(*ch)
		{
			case 260:
				wclear(_win);
				wmove(_win, x, y--);
				wrefresh(_win);
				_p1->setY(y);
				GameEngine::fresh();
				if (_p1->impact(_e1) == 1)
					_p1->die();
				break;
			case 261:
				wclear(_win);
				wmove(_win, x, y++);
				wrefresh(_win);
				_p1->setY(y);
				GameEngine::fresh();
				if (_p1->impact(_e1) == 1)
					_p1->die();
				break;
			case 259:
				wclear(_win);
				wmove(_win, x--, y);
				wrefresh(_win);
				_p1->setX(x);
				GameEngine::fresh();
				if (_p1->impact(_e1) == 1)
					_p1->die();
				break;
			case 258:
				wclear(_win);
				wmove(_win, x++, y);
				wrefresh(_win);
				_p1->setX(x);
				GameEngine::fresh();
				if (_p1->impact(_e1) == 1)
					_p1->die();
				break;	
		}
	printw("x = %d, y = %d",x, y );
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

WINDOW		*GameEngine::getWindow(void)
{
	return _win;
}
