/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 03:06:15 by lrenoud-         ###   ########.fr       */
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
		AEntities &operator=(AEntities const *rhs);
		// virtual void	move() = 0;
		virtual void	die() = 0;
		bool			impact(AEntities const *e1) const;
		int				getX(void) const;
		int				getY(void) const;
		void			setY(int nb);
		void			setX(int nb);
		char			getChar(void) const;

	protected:
		int		_x, _y;
		char	_char;

	private:
		AEntities(void);
};

#endif