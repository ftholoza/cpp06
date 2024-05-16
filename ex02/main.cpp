/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:58:35 by francesco         #+#    #+#             */
/*   Updated: 2024/05/16 17:20:53 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    std::srand(std::time(nullptr));
    int x = std::rand() % 3;
    if (x == 0)
        return (new A);
    else if (x == 1)
        return (new B);
    else
        return (new C);
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void	identify(Base &p) 
{
	Base temp;
	try {
		temp = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		temp = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		temp = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}

int     main( void )
{
    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();

    std::cout << "/* **************************************** */" << std::endl;

    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << std::endl;

    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b ); std::cout << std::endl;

    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c ); std::cout << std::endl;

    std::cout << "d* = "; identify( d );
    std::cout << "d& = "; identify( *d ); std::cout << std::endl;

    std::cout << "/* ***************************************** */" << std::endl;


    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}