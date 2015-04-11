/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 21:08:21 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player		&Player::operator=(Player const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Player::Player(void): AEntities(40, 0, '@'), _life(3)
{

}

Player::~Player(void)
{

}

Player::Player(Player const &src): AEntities(src), _life(3)
{

}

int				Player::getLife(void) const
{
	return this->_life;
}
