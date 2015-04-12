/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 13:58:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntities.hpp"

class Player : public AEntities
{
	public:
		Player(WINDOW const * win, int x, int y);
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
