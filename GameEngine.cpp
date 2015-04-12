/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 17:22:55 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine::GameEngine(void)
{
	initscr();
	halfdelay(1);
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, _winheight, _winwidth);
	_p1 = new Player(stdscr, 0, _winheight / 2);
	_win = stdscr;
	for (int i = 0; i < ENTITIES_MAX; i++)
		_entities[i] = 0;
}

GameEngine::~GameEngine(void)
{
	// t_entities *	tmp = _entities;
	// t_entities *	prev = tmp;

	// while (tmp)
	// {
	// 	delete tmp->entity;
	// 	tmp->entity = 0;
	// 	tmp = tmp->next;
	// 	delete prev;
	// 	prev = tmp;
	// }
	// delete _p1;
	endwin();
}

GameEngine::GameEngine(GameEngine const &src) :
_win(src._win), _winheight(src._winheight), _winwidth(src._winwidth)
{
}

GameEngine		&GameEngine::operator=(GameEngine const &src)
{
	if (this != &src)
		_win = src._win;
	return (*this);
}

bool				GameEngine::render(void)
{
	if (rand() % 100 < 20)
		addEntity(new Enemy(_win, _winwidth, (rand() % _winheight)));
	updateEntities();
	refresh();
	return (true);
}

AEntities * 		GameEngine::getEntity(int n) const
{
	// if (_nbEntities > 0 && n >= 0 && n < _nbEntities)
	// {
	// 	t_entities * tmp = _entities;
	// 	for (int i = 0; i < n; i++)
	// 		tmp = tmp->next;
	// 	return (tmp->entity);
	// }
	return (_entities[n]);
}

// void				GameEngine::printEntities(void)
// {
// 	t_entities *	tmp = _entities;

// 	while (tmp)
// 	{
// 		printw("%d\n", tmp->entity->getX());
// 		printw("%d\n", tmp->entity->getY());
// 		tmp = tmp->next;
// 	}
// }

void				GameEngine::addEntity(AEntities * entity)
{
	// if (!entity)
	// 	return (_nbEntities);

	// t_entities *	tmp;

	// tmp = _entities;
	// if (!tmp)
	// {
	// 	tmp = new t_entities;
	// 	tmp->entity = entity;
	// 	tmp->next = 0;
	// 	_entities = tmp;
	// 	_nbEntities++;
	// }
	// else
	// {
	// 	while (tmp->next)
	// 	{
	// 		if (tmp->entity == entity)
	// 			break ;
	// 		tmp = tmp->next;
	// 	}
	// 	if (tmp->entity == entity)
	// 		return (_nbEntities);
	// 	tmp->next = new t_entities;
	// 	tmp->next->entity = entity;
	// 	tmp->next->next = 0;
	// 	_nbEntities++;
	// }
	// return (_nbEntities);
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] == 0)
			_entities[i] = entity;
	}
}

void				GameEngine::updateEntities(void)
{
	// t_entities *	tmp = _entities;

	_p1->update();
	addEntity(_p1->getMissile());
	// while (tmp)
	// {
	// 	tmp->entity->update();
	// 	addEntity(tmp->entity->getMissile());
	// 	tmp = tmp->next;
	// }
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i])
		{
			_entities[i]->update();
			addEntity(_entities[i]->getMissile());
		}
	}
	colisionManager();
}

void				GameEngine::deleteEntity(AEntities * entity)
{
	// if (!_entities)
	// 	return ;

	// t_entities *	tmp = _entities;

	// if (_entities->entity == entity)
	// {
	// 	_entities = _entities->next;
	// 	delete tmp->entity;
	// 	delete tmp;
	// 	return ;
	// }

	// t_entities *	prev = tmp;

	// while (tmp)
	// {
	// 	if (tmp->entity == entity)
	// 	{
	// 		prev->next = tmp->next;
	// 		delete tmp->entity;
	// 		delete tmp;
	// 		return ;
	// 	}
	// 	prev = tmp;
	// 	tmp = tmp->next;
	// }
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] == entity)
			_entities[i] = 0;
	}
}

void				GameEngine::colisionManager(void)
{
	// t_entities *	node = _entities;
	// while (node)
	// {
	// 	if (node->entity->impact(node->next))
	// 	{
	// 		deleteEntity(node->entity);
	// 	}
	// 	node = node->next;
	// }
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i])
		{
			for (int j = i + 1; j < ENTITIES_MAX; j++)
			{
				if (_entities[j] && _entities[i]->impact(_entities[j]))
				{
					deleteEntity(_entities[i]);
					deleteEntity(_entities[j]);
				}
			}
		}
	}
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
