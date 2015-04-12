/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 18:43:06 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine::GameEngine(void)
{
	initscr();
	nodelay(stdscr, TRUE);
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
	if (AEntities::loopCount == 2)
		AEntities::loopCount = 0;
	AEntities::loopCount++;
	if (rand() % 500 < 5)
		addEntity(new Enemy(_win, _winwidth, (rand() % _winheight)));
	updateEntities();
	refresh();
	return (true);
}

AEntities * 		GameEngine::getEntity(int n) const
{
	return (_entities[n]);
}

void				GameEngine::addEntity(AEntities * entity)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] == 0)
		{
			_entities[i] = entity;
			return ;
		}
	}
}

void				GameEngine::updateEntities(void)
{
	_p1->update();
	addEntity(_p1->getMissile());
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
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if ( _entities[i] == entity)
		{
			// delete _entities[i];
			_entities[i] = 0;
			return ;
		}
	}
}

void				GameEngine::colisionManager(void)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		for (int j = i + 1; j < ENTITIES_MAX; j++)
		{
			if (_entities[i] && _entities[j] && _entities[i]->impact(_entities[j]))
			{
				deleteEntity(_entities[i]);
				deleteEntity(_entities[j]);
			}
		}
		if (_entities[i] && _entities[i]->getX() < 0)
			deleteEntity(_entities[i]);
	}
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}
