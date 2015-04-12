/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 12:11:14 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy		&Enemy::operator=(Enemy const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Enemy::Enemy(WINDOW * win): AEntities(win, 10, 10, '<')
{

}

Enemy::~Enemy(void)
{

}

Enemy::Enemy(Enemy const &src): AEntities(src)
{

}

void	Enemy::update(void)
{

}
