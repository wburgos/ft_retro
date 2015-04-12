/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 14:18:29 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP
# define MISSILES_HPP

# include "AEntities.hpp"

class Missiles: public AEntities
{
	public:
		Missiles(WINDOW const * win, int x, int y, int direction);
		~Missiles(void);
		Missiles(Missiles const &src);
		Missiles			&operator=(Missiles const &rhs);

		void				movement(void);
		void				update(void);

	private:
		Missiles(void);

		int					_direction;
};

#endif
