/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 14:00:11 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_HPP
# define ENTITIES_HPP

#include <iostream>
#include <ncurses.h>

class AEntities
{
	public:
		AEntities(WINDOW const * win, int x, int y, char caract);
		virtual ~AEntities(void);
		AEntities(AEntities const &src);

		AEntities &operator=(AEntities const & rhs);

		virtual void	movement() = 0;
		virtual void	update() = 0;

		bool			impact(AEntities const & e1) const;

		int				getX(void) const;
		int				getY(void) const;
		void			setY(int nb);
		void			setX(int nb);
		char			getChar(void) const;

	protected:
		WINDOW const *		_win;
		int				_x, _y;
		int				_winwidth, _winheight;
		char			_char;

	private:
		AEntities(void);
};

#endif
