/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntities.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:47:21 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AEntities.hpp"

AEntities::AEntities(WINDOW const * win, int x, int y, char caract): _win(win), _x(x), _y(y), _char(caract)
{
	std::cout << caract << " is called " << _x << "/" << _y << " position" << std::endl;
}

AEntities::~AEntities(void)
{

}

AEntities::AEntities(AEntities const & src) : _win(src._win), _x(src._x), _y(src._y), _char(src._char)
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

void				AEntities::setX(int nb)
{
	_x += nb;
}

void				AEntities::setY(int nb)
{
	_y += nb;
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

bool			AEntities::impact(AEntities const & e1) const
{
	if ((_x == e1._x) && (_y == e1._y))
		return (true);
	return (false);
}
