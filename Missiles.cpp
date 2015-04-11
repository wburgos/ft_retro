/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 20:11:54 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missiles.hpp"

Missiles		&Missiles::operator=(Missiles const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Missiles::Missiles(void): AEntities(10, 10, '*')
{

}

Missiles::~Missiles(void)
{

}

Missiles::Missiles(Missiles const &src): AEntities(src)
{

}
