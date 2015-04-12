/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 21:11:39 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <ncurses.h>
# include <unistd.h>
# include <cstdlib>
# include "Player.hpp"
# include "Enemy.hpp"

# define ENTITIES_MAX 3000

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);

	bool					render(void);
	bool					updateEntities(void);

	AEntities *				getEntity(int n) const;
	void					addEntity(AEntities * entity);
	WINDOW const *			getWindow(void) const;
	void					printEntities(void);
	static int							i;
private:
	GameEngine(GameEngine const &src);
	GameEngine	&operator=(GameEngine const &src);

	bool					playerColision(void);
	void					entityColision(void);
	void					deleteEntity(AEntities * entity);

	WINDOW const *				_win;
	int							_winheight;
	int							_winwidth;
	Player *					_p1;
	AEntities *					_entities[ENTITIES_MAX];
	static int					_score;
};

#endif
