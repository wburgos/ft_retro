/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 02:55:34 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
#include "Enemy.hpp"
#include "Entities.hpp"

class Enemy: public AEntities{
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(Enemy const &src);
		Enemy			&operator=(Enemy const &rhs);
		void	die();
		// virtual void	move();
};

#endif