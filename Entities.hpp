/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 20:03:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_HPP
# define ENTITIES_HPP
#include <iostream>

class AEntities{
	public:
		AEntities(int x, int y, char caract);
		~AEntities(void);
		AEntities(AEntities const &src);
		AEntities &operator=(AEntities const &rhs);
		// virtual void	move() = 0;
		// virtual void	die() = 0;
		bool			impact(AEntities const &src) const;
		int				getX(void) const;
		int				getY(void) const;
		char			getChar(void) const;

	protected:
		int		_x, _y;
		char	_char;

	private:
		AEntities(void);
};

#endif