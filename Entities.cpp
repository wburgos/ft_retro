/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 03:06:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entities.hpp"

AEntities::AEntities(int x, int y, char caract): _x(x), _y(y), _char(caract)
{
	std::cout << caract << " is called " << _x << "/" << _y << " position" << std::endl;
}

AEntities::~AEntities(void)
{

}

AEntities::AEntities(AEntities const &src) : _x(src._x), _y(src._y), _char(src._char)
{

}

AEntities		&AEntities::operator=(AEntities const &rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_char = rhs._char;
	return *this;
}

void				AEntities::setX(int nb)
{
	this->_x += nb;
}

void				AEntities::setY(int nb)
{
	this->_y += nb;
}

int				AEntities::getX(void) const
{
	return this->_x;
}

int				AEntities::getY(void) const
{
	return this->_y;
}

char			AEntities::getChar(void) const
{
	return this->_char;
}

bool			AEntities::impact(AEntities const *e1) const
{
	if ((this->_x == e1->_x) && (this->_y == e1->_y))
		return true;
	return false;
}