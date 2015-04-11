/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 20:02:56 by lrenoud-         ###   ########.fr       */
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

bool			AEntities::impact(AEntities const &src) const
{
	if ((this->_x == src._x) && (this->_y == src._y))
		return true;
	return false;
}