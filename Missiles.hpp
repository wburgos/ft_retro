/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 20:12:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP
# define MISSILES_HPP
#include "Missiles.hpp"
#include "Entities.hpp"

class Missiles: public AEntities{
	public:
		Missiles(void);
		~Missiles(void);
		Missiles(Missiles const &src);
		Missiles			&operator=(Missiles const &rhs);
		// virtual void	die();
		// virtual void	move();
};

#endif