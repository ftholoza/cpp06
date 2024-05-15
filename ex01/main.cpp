/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:15:58 by francesco         #+#    #+#             */
/*   Updated: 2024/04/25 15:39:40 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"
# include "struct.hpp"

int main(int argc, char **argv)
{
    Data        ptr1;
    Data        *ptr2;
    uintptr_t   raw;
    if (argc != 2)
    {
        std::cout << "wrong parameters" << std::endl;
        return (0);
    }
    ptr1.str = argv[1];   
    std::cout << "ptr1 created with '" << ptr1.str << "' inside" << std::endl;
    std::cout << "Serialization" << std::endl;
    raw = Serializer::serialize(&ptr1);
    std::cout << "uintptr value: " << raw << std::endl;
    std::cout << "Deserialization" << std::endl;
    ptr2 = Serializer::deserialize(raw);
    std::cout << "inside ptr2 '" << ptr2->str << "'" << std::endl;
}