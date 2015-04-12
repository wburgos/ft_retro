/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 08:56:50 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>

int	main(int, char **)
{
	GameEngine		game;

	while(game.getInput() != 'Q' && game.getInput() != 'q')
	{
		game.render();
	}
	return 0;
}
