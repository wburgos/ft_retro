/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 21:02:28 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine::GameEngine(void)
{
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, _winheight, _winwidth);
	_p1 = new Player(stdscr, 0, _winheight / 2);
	_win = stdscr;
	for (int i = 0; i < ENTITIES_MAX; i++)
		_entities[i] = 0;
}

GameEngine::~GameEngine(void)
{
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
	usleep(15000);
	mvprintw(0, 0, "Score: %d", _score);
	if (AEntities::loopCount == 2)
		AEntities::loopCount = 0;
	AEntities::loopCount++;
	if (rand() % GameEngine::i < 5)
	{
		int enY = rand() % _winheight;
		addEntity(new Enemy(_win, _winwidth, (enY == 0) ? 1 : enY));
	}
	if (!updateEntities())
		return (false);
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

bool				GameEngine::updateEntities(void)
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
	if (playerColision())
		return (false);
	entityColision();
	return (true);
}

void				GameEngine::deleteEntity(AEntities * entity)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if ( _entities[i] == entity)
		{
			if (_entities[i])
				delete _entities[i];
			mvaddch(_entities[i]->getY(), _entities[i]->getX(), ' ');
			_entities[i] = 0;
			return ;
		}
	}
}

bool				GameEngine::playerColision(void)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] && _p1->impact(_entities[i]))
			return (true);
	}
	return (false);
}

void				GameEngine::entityColision(void)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		for (int j = i + 1; j < ENTITIES_MAX; j++)
		{
			if (_entities[i] && _entities[j] && _entities[i]->impact(_entities[j]))
			{
				_score += 10;
				deleteEntity(_entities[i]);
				deleteEntity(_entities[j]);
			}
		}
		if (_entities[i] && (_entities[i]->getX() < 0 || _entities[i]->getX() > 3000))
			deleteEntity(_entities[i]);
	}
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}

int			GameEngine::i = 200;
unsigned int GameEngine::_score = 0;
