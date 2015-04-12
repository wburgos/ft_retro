/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 20:19:44 by wburgos           #+#    #+#             */
/*   Updated: 2015/04/12 21:10:47 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroids.hpp"

Asteroids		&Asteroids::operator=(Asteroids const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Asteroids::Asteroids(WINDOW const * win, int x, int y): AEntities(win, x, y, 'O')
{
}

Asteroids::~Asteroids(void)
{
}

Asteroids::Asteroids(Asteroids const &src): AEntities(src)
{
}

void				Asteroids::movement(void)
{
	mvaddch(_y, _x, ' ');
	_x -= 1;
	mvaddch(_y, _x, _char);
	move(0, 0);
}

void				Asteroids::update(void)
{
	if (AEntities::loopCount == 1)
		movement();
}
