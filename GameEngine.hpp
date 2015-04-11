/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 23:11:56 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
#include <ncurses.h>

class GameEngine{
	public:
		GameEngine(int hei, int wid, int x, int y);
		~GameEngine(void);
		GameEngine(GameEngine const &src);
		GameEngine	&operator=(GameEngine const &rhs);
		WINDOW		*getWindow(void);
		void		createNewWin(void);
		void		destroyWin(void);

	private:
		GameEngine(void);
		WINDOW	*_win;
		int		_height, _width, _startX, _startY;

};

#endif