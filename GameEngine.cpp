/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 15:12:02 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine::GameEngine(void) : _entities(0), _nbEntities(0)
{
	initscr();
	halfdelay(1);
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, _winheight, _winwidth);
	_p1 = new Player(stdscr, 0, _winheight / 2);
	_win = stdscr;
}

GameEngine::~GameEngine(void)
{
	t_entities *	tmp = _entities;
	t_entities *	prev = tmp;

	while (tmp)
	{
		delete tmp->entity;
		tmp->entity = 0;
		tmp = tmp->next;
		delete prev;
		prev = tmp;
	}
	delete _p1;
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
	// usleep(10000);
	addEntity(new Enemy(_win, _winwidth, (rand() % _winheight)));
	updateEntities();
	refresh();
	return (true);
}

AEntities * 		GameEngine::getEntity(int n) const
{
	if (_nbEntities > 0 && n >= 0 && n < _nbEntities)
	{
		t_entities * tmp = _entities;
		for (int i = 0; i < n; i++)
			tmp = tmp->next;
		return (tmp->entity);
	}
	return (0);
}

void				GameEngine::printEntities(void)
{
	t_entities *	tmp = _entities;

	while (tmp)
	{
		printw("%d\n", tmp->entity->getX());
		printw("%d\n", tmp->entity->getY());
		tmp = tmp->next;
	}
}

int					GameEngine::addEntity(AEntities * entity)
{
	if (!entity)
		return (_nbEntities);

	t_entities *	tmp;

	tmp = _entities;
	if (!tmp)
	{
		tmp = new t_entities;
		tmp->entity = entity;
		tmp->next = 0;
		_entities = tmp;
		_nbEntities++;
	}
	else
	{
		while (tmp->next)
		{
			if (tmp->entity == entity)
				break ;
			tmp = tmp->next;
		}
		if (tmp->entity == entity)
			return (_nbEntities);
		tmp->next = new t_entities;
		tmp->next->entity = entity;
		tmp->next->next = 0;
		_nbEntities++;
	}
	return (_nbEntities);
}

void				GameEngine::updateEntities(void)
{
	t_entities *	tmp = _entities;

	_p1->update();
	addEntity(_p1->getMissile());
	while (tmp)
	{
		tmp->entity->update();
		addEntity(tmp->entity->getMissile());
		tmp = tmp->next;
	}
}

void				GameEngine::deleteEntity(AEntities * entity)
{
	if (!_entities)
		return ;

	t_entities *	tmp = _entities;

	if (_entities->entity == entity)
	{
		_entities = _entities->next;
		delete tmp->entity;
		delete tmp;
		return ;
	}

	t_entities *	prev = tmp;

	while (tmp)
	{
		if (tmp->entity == entity)
		{
			prev->next = tmp->next;
			delete tmp->entity;
			delete tmp;
			tmp = prev->next;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void				GameEngine::colisionManager(AEntities * entity)
{
	t_entities *	node = _entities;

	if (!node)
		return ;

	while (node)
	{
		if (entity->impact(node->entity))
		{
			mvaddch(entity->getY(), entity->getX(), ' ');
			mvaddch(node->entity->getY(), node->entity->getX(), ' ');
			deleteEntity(entity);
			deleteEntity(node->entity);
		}
	}
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
