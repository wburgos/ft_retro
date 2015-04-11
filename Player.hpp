/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 19:56:56 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "Entities.hpp"
#include "Entities.hpp"

class Player : public AEntities{
	public:
		Player(void);
		~Player(void);
		Player(Player const &src);
		Player		&operator=(Player const &rhs);
		// virtual		void die();
		// virtual		void move();
		int			getLife(void) const;
	private:
		int	_life;

};

#endif