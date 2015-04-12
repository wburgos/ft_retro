/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 18:19:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 12:12:02 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>

int	main(int, char **)
{
	GameEngine		game;

	while (game.render())
		;
	return (0);
}
