/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:42:58 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missiles.hpp"

Missiles::Missiles(WINDOW * win): AEntities(win, 10, 10, '*')
{

}

Missiles::~Missiles(void)
{

}

Missiles::Missiles(Missiles const &src): AEntities(src)
{

}

Missiles		&Missiles::operator=(Missiles const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}
