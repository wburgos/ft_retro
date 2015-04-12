/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:46:39 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AEntities.hpp"

class Enemy: public AEntities
{
	public:
		Enemy(WINDOW * win);
		~Enemy(void);
		Enemy(Enemy const &src);
		Enemy			&operator=(Enemy const &rhs);
		void	die();
		// virtual void	move();

	private:
		Enemy(void);
};

#endif
