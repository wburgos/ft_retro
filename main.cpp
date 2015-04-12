/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 03:19:31 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <ncurses.h>
#include <iostream>

int	main(int, char **)
{
	int ch = 0;
	Player		*p1 = new Player;
	Enemy		*e1 = new Enemy;
	GameEngine	win(p1, e1);
	for (;;)
	{
		if((ch = getch()) == 27)
			break ;
		win.move(&ch);
	}
	// delete p1;
	// delete e1;
	return 0;
}
