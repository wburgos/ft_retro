/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 22:08:41 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ENTITIES_HPP
# define A_ENTITIES_HPP

#include <iostream>
#include <ncurses.h>

class AEntities
{
private:
	AEntities(void);

protected:
	WINDOW const *		_win;
	int					_x, _y;
	int					_winwidth, _winheight;
	char				_char;
	AEntities * 		_missile;

public:

	AEntities(WINDOW const * win, int x, int y, char caract);
	virtual ~AEntities(void);
	AEntities(AEntities const &src);

	AEntities &operator=(AEntities const & rhs);

	virtual void		movement() = 0;
	virtual void		update(void) = 0;

	void				draw(void);
	void				del(void);

	bool				impact(AEntities * entities) const;

	int					getX(void) const;
	int					getY(void) const;
	char				getChar(void) const;
	AEntities *			getMissile(void) const;

	static int			loopCount;
};

#endif
