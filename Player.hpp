/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 09:44:33 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntities.hpp"

class Player : public AEntities
{
	public:
		Player(WINDOW * win, int x, int y);
		~Player(void);
		Player(Player const &src);

		Player		&operator=(Player const &rhs);

		void		die(void);
		void		movement(int input);
		void		shoot(void) const;
		void		update(void);

		int			getLife(void) const;

	private:
		Player(void);

		int			_life;
		int			_input;
};

#endif
