/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 14:12:52 by wburgos          ###   ########.fr       */
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
	usleep(10000);
	_input = getch();
	_p1->setInput(_input);
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
	if (_p1->getInput() == ' ')
		addEntity(_p1->shoot());
	// printEntities();
	while (tmp)
	{
		tmp->entity->update();
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

void				GameEngine::colisionManager(void)
{
	t_entities *	node = _entities;

	while (node)
	{
		t_entities *	nextNodes = node->next;
		if (!nextNodes)
			return ;
		while (nextNodes)
		{
			if (node->entity->impact(nextNodes->entity))
			{
				mvaddch(node->entity->getY(), node->entity->getX(), ' ');
				mvaddch(nextNodes->entity->getY(), nextNodes->entity->getX(), ' ');
				deleteEntity(node->entity);
				deleteEntity(nextNodes->entity);
			}
		}
		node = node->next;
	}
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
