/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 14:18:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Missiles.hpp"
# include "AEntities.hpp"

class Enemy: public AEntities
{
	public:
		Enemy(WINDOW const * win, int x, int y);
		~Enemy(void);
		Enemy(Enemy const &src);
		Enemy			&operator=(Enemy const &rhs);

		AEntities *		shoot(void);
		void			update(void);
		void			movement(void);

	private:
		Enemy(void);
};

#endif
