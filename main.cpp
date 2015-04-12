/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 16:27:53 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>

int	main(int, char **)
{
	srand(time(0));
	GameEngine		game;

	while (game.render())
		;
	return (0);
}
