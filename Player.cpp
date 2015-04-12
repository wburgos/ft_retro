/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 09:21:19 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player		&Player::operator=(Player const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Player::Player(WINDOW * win, int x, int y) : AEntities(win, x, y, '>'), _life(3)
{
	mvaddch(_y, _x, _char);
	move(0, 0);
	refresh();
}

Player::~Player(void)
{

}

Player::Player(Player const &src): AEntities(src), _life(3)
{

}

int				Player::getLife(void) const
{
	return _life;
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

void			Player::update(void)
{
	int winX, winY;
	int ch = getch();

	getmaxyx(_win, winY, winX);
	if (ch == KEY_DOWN || ch == KEY_UP || ch == KEY_LEFT || ch == KEY_RIGHT)
	{
		mvdelch(_y, _x);
		if (ch == KEY_UP && _y > 0)
			_y--;
		else if (ch == KEY_DOWN && _y < winY - 1)
			_y++;
		else if (ch == KEY_LEFT && _x > 0)
			_x -= 2;
		else if (ch == KEY_RIGHT && _x < winX - 2)
			_x += 2;
	}
	mvaddch(_y, _x, _char);
	move(0, 0);
}
