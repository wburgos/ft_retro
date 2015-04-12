/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 21:04:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Missiles.hpp"
#include "GameEngine.hpp"

Player		&Player::operator=(Player const &rhs)
{
	AEntities::operator=(rhs);
	return (*this);
}

Player::Player(WINDOW const * win, int x, int y) : AEntities(win, x, y, '>')
{
}

Player::~Player(void)
{

}

Player::Player(Player const &src): AEntities(src)
{

}

void			Player::movement(void)
{
	mvaddch(_y, _x, ' ');
	if (_input == KEY_UP && _y > 1)
		_y--;
	else if (_input == KEY_DOWN && _y < _winheight - 1)
		_y++;
	else if (_input == KEY_LEFT && _x > 0)
		_x--;
	else if (_input == KEY_RIGHT && _x < _winwidth - 2)
		_x++;
	mvaddch(_y, _x, _char);
	move(0, 0);
}

void			Player::shoot(void)
{
	_missile = new Missiles(_win, _x + 2, _y, 1);
}

void			Player::update(void)
{
	_input = getch();
	_missile = 0;

	if (_input == KEY_DOWN || _input == KEY_UP || _input == KEY_LEFT || _input == KEY_RIGHT)
		movement();
	if ((_input == ' ' && GameEngine::i != 3) || GameEngine::i == 1 )
		shoot();
}
