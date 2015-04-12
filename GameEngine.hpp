/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:48:55 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <ncurses.h>
# include "Player.hpp"

class GameEngine
{
	public:
		GameEngine(void);
		~GameEngine(void);
		GameEngine(GameEngine const &src);

		GameEngine	&operator=(GameEngine const &src);

		void					acquireInput(void);
		void					render(void);

		WINDOW const *			getWindow(void) const;
		int						getInput(void) const;

	private:

		WINDOW const *			_win;
		int						_input;
		int						_height;
		int						_width;

		Player *				_p1;
};

#endif
