/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 15:00:33 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntities.hpp"

AEntities::AEntities(WINDOW const * win, int x, int y, char caract):
_win(win), _x(x), _y(y), _char(caract), _missile(0)
{
	getmaxyx(_win, _winheight, _winwidth);
	mvaddch(_y, _x, _char);
	refresh();
	move(0, 0);
}

AEntities::~AEntities(void)
{
	mvdelch(_y, _x);
}

AEntities::AEntities(AEntities const & src) :
_win(src._win), _x(src._x), _y(src._y), _char(src._char), _missile(0)
{
}

AEntities		&AEntities::operator=(AEntities const & src)
{
	if (this != &src)
	{
		_x = src._x;
		_y = src._y;
		_char = src._char;
	}
	return (*this);
}

int				AEntities::getX(void) const
{
	return (_x);
}

int				AEntities::getY(void) const
{
	return (_y);
}

char			AEntities::getChar(void) const
{
	return (_char);
}

bool			AEntities::impact(AEntities const * e1) const
{
	if ((_x == e1->_x) && (_y == e1->_y))
		return (true);
	return (false);
}

AEntities *			AEntities::getMissile(void) const
{
	return (_missile);
}
