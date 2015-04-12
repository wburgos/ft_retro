/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 14:17:31 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missiles.hpp"

Missiles::Missiles(WINDOW const * win, int x, int y, int direction):
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
