/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 23:54:17 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP
#include <ncurses.h>

class GameEngine{
	public:
		GameEngine(void);
		~GameEngine(void);
		GameEngine(GameEngine const &src);
		GameEngine	&operator=(GameEngine const &rhs);
		WINDOW		*getWindow(void);
		void		createNewWin(void);
		void		destroyWin(void);

	private:
		WINDOW	*_win;
		int		_height, _width, _startX, _startY;

};

#endif
