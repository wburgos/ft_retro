/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 15:08:08 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <ncurses.h>
# include <unistd.h>
# include "Player.hpp"
# include "Enemy.hpp"
# include <cstdlib>

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);

	bool					render(void);
	void					updateEntities(void);

	AEntities *				getEntity(int n) const;
	int						addEntity(AEntities * entity);
	WINDOW const *			getWindow(void) const;
	void					printEntities(void);

private:
	GameEngine(GameEngine const &src);
	GameEngine	&operator=(GameEngine const &src);

	void					colisionManager(AEntities * entity);
	void					deleteEntity(AEntities * entity);

	typedef struct			s_entities
	{
		AEntities *			entity;
		struct s_entities * next;
	}						t_entities;

	WINDOW const *			_win;
	int						_winheight;
	int						_winwidth;
	Player *				_p1;
	t_entities *			_entities;
	int						_nbEntities;
};

#endif
