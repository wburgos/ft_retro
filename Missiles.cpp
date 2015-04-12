/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 12:14:22 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missiles.hpp"

Missiles::Missiles(WINDOW * win, int x, int y, int direction):
AEntities(win, x, y, '*'), _direction(direction)
{
}

Missiles::~Missiles(void)
{
}

Missiles::Missiles(Missiles const &src): AEntities(src)
{

}

Missiles &			Missiles::operator=(Missiles const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

void				Missiles::movement(void)
{
	mvaddch(_y, _x, ' ');
	_x += _direction;
	mvaddch(_y, _x, _char);
	move(0, 0);
}

void				Missiles::update(void)
{
	movement();
}
