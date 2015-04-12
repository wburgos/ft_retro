/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 12:02:51 by wburgos          ###   ########.fr       */
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

		Player			&operator=(Player const &rhs);

		bool			die(void);
		void			movement(void);
		void			update(void);
		AEntities *		shoot(void);

		int				getLife(void) const;
		void			setInput(int input);
		int				getInput(void) const;

	private:
		Player(void);

		int			_life;
		int			_input;
};

#endif
