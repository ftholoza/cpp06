/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:43:32 by francesco         #+#    #+#             */
/*   Updated: 2024/04/19 18:53:59 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "\033[1;31mError: to many parameters\033[0m" << std::endl;
        return (0);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}