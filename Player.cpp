/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 10:27:04 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Missiles.hpp"

Player		&Player::operator=(Player const &rhs)
{
	AEntities::operator=(rhs);
	return (*this);
}

Player::Player(WINDOW * win, int x, int y) : AEntities(win, x, y, '>'), _life(3)
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

void			Player::die(void)
{
	if (_life > 0)
		_life--;
	if (_life == 0)
	{
		std::cout << " mort" <<std::endl;
	}
}

void			Player::shoot(void) const
{
	Missiles *missile = new Missiles(_win, _x + 2, _y, 1);
	missile->movement();
}

void			Player::movement(int input)
{
	mvdelch(_y, _x);
	if (input == KEY_UP && _y > 0)
		_y--;
	else if (input == KEY_DOWN && _y < _winheight - 1)
		_y++;
	else if (input == KEY_LEFT && _x > 0)
		_x--;
	else if (input == KEY_RIGHT && _x < _winwidth - 2)
		_x++;
	mvaddch(_y, _x, _char);
	move(0, 0);
}

void			Player::update(void)
{
	_input = getch();

	if (_input == KEY_DOWN || _input == KEY_UP || _input == KEY_LEFT || _input == KEY_RIGHT)
		movement(_input);
	if (_input == ' ')
		shoot();
}
