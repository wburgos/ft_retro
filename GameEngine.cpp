/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 14:17:07 by lrenoud-         ###   ########.fr       */
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
	usleep(10000);
	_input = getch();
	_p1->setInput(_input);
	if (rand() % 100 < 10)
		addEntity(new Enemy(_win,_winwidth ,rand() % _winheight));
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
	if (rand() % 100 < 25)
		addEntity(getEntity(rand() % _nbEntities)->shoot());
	// printEntities(); 
	while (tmp)
	{
		tmp->entity->update();
		tmp = tmp->next;
	}

}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
