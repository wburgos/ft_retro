/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:45:59 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP
# define MISSILES_HPP

# include "AEntities.hpp"

class Missiles: public AEntities
{
	public:
		Missiles(WINDOW * win);
		~Missiles(void);
		Missiles(Missiles const &src);
		Missiles			&operator=(Missiles const &rhs);
		// virtual void	die();
		// virtual void	move();

	private:
		Missiles(void);
};

#endif
