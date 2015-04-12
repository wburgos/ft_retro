/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 02:56:11 by lrenoud-         ###   ########.fr       */
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

void			Player::die(void)
{
	if (_life > 0)
		this->_life--;
	if (this->_life == 0)
	{
		std::cout << " mort" <<std::endl;
	}
}