/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 10:26:35 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP
# define MISSILES_HPP

# include "AEntities.hpp"

class Missiles: public AEntities
{
	public:
		Missiles(WINDOW * win, int x, int y, int direction);
		~Missiles(void);
		Missiles(Missiles const &src);
		Missiles			&operator=(Missiles const &rhs);

		void				die(void);
		void				movement(void);
		void				update(void);

	private:
		Missiles(void);

		int					_direction;
};

#endif
