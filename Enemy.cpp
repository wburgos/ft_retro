/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 16:30:38 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy		&Enemy::operator=(Enemy const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Enemy::Enemy(WINDOW const * win, int x, int y): AEntities(win, x, y, '<')
{
	(void)x;
	(void)y;
}

Enemy::~Enemy(void)
{

}

Enemy::Enemy(Enemy const &src): AEntities(src)
{

}

void				Enemy::shoot(void)
{
	_missile = new Missiles(_win, _x - 3, _y, -1);
}

void				Enemy::movement(void)
{
	mvaddch(_y, _x, ' ');
	_x -= 1;
	mvaddch(_y, _x, _char);
	move(0, 0);
}

void				Enemy::update(void)
{
	_missile = 0;
	if (rand() % 100 < 5)
		shoot();
	movement();
}
