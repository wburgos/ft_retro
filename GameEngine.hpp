/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 02:54:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Entities.hpp"

class GameEngine{
	public:
		GameEngine(Player *p1, Enemy *e1);
		~GameEngine(void);
		GameEngine(GameEngine const &src);
		GameEngine	&operator=(GameEngine const &rhs);
		WINDOW		*getWindow(void);
		void		move(int *ch);
		void		fresh(void);

	private:
		GameEngine(void);
		WINDOW	*_win;
		Player	*_p1;
		Enemy	*_e1;
		int		_height, _width, _startX, _startY;

};

#endif
