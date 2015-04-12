/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 13:58:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Missiles.hpp"

Player		&Player::operator=(Player const &rhs)
{
	AEntities::operator=(rhs);
	return (*this);
}

Player::Player(WINDOW const * win, int x, int y) : AEntities(win, x, y, '>'), _life(3)
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
	return (_life);
}

bool			Player::die(void)
{
	if (_life > 0)
		_life--;
	if (_life == 0)
		return (true);
	return (false);
}

void			Player::movement(void)
{
	mvaddch(_y, _x, ' ');
	if (_input == KEY_UP && _y > 0)
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

AEntities *		Player::shoot(void)
{
	AEntities * missile = new Missiles(_win, _x + 2, _y, 1);
	return (missile);
}

void			Player::update(void)
{
	if (_input == KEY_DOWN || _input == KEY_UP || _input == KEY_LEFT || _input == KEY_RIGHT)
		movement();
}

void			Player::setInput(int input)
{
	_input = input;
}

int				Player::getInput(void) const
{
	return (_input);
}
