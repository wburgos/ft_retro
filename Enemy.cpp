/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 02:56:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy		&Enemy::operator=(Enemy const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Enemy::Enemy(void): AEntities(10, 10, '#')
{

}

Enemy::~Enemy(void)
{

}

Enemy::Enemy(Enemy const &src): AEntities(src)
{

}

void	Enemy::die()
{

}
