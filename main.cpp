/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 23:58:48 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include <ncurses.h>
#include <iostream>

int	main(int, char **)
{
	int ch = 0;
	Player *p1 = new Player;
	GameEngine win;
	// win.createNewWin();
	// win.destroyWin();
	for (;;)
	{
		if((ch = getch()) == KEY_DOWN)
		{
			break ;
		}
	}
	// clear();

	delete p1;
	return 0;
}
