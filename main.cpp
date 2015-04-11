/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 23:41:04 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include <ncurses.h>
#include <iostream>

int	main(int, char **)
{
	int		_height = 0;
	int		_width = 0;
	int		_startX = (LINES - _height) / 2;
	int		_startY = (COLS - _width) / 2;
	int		ch = 0;
	Player *p1 = new Player;
	GameEngine win(_height, _width, _startX, _startY);
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	printw("Press F5 to exit");
	refresh();
	keypad(stdscr, TRUE);
	noecho();
	win.createNewWin();
	// win.destroyWin();
	if((ch = getch()) == KEY_DOWN)
	{
		// win.createNewWin();
	}
	clear();
	endwin();
	delete p1;
	return 0;
}
