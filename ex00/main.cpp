/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:43:32 by francesco         #+#    #+#             */
/*   Updated: 2024/05/16 16:57:02 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv)
{
    int i = 2147483647;
    float   f = 2147483647;
    
    std::cout << f << std::endl;
    if (i == f)
        std::cout << "ok" << std::endl;
    if (argc != 2)
    {
        std::cout << "\033[1;31mError: wrong parameters\033[0m" << std::endl;
        return (0);
    }
    ScalarConverter::convert(argv[1]);
    return (0);
}