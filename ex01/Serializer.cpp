/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:10:12 by francesco         #+#    #+#             */
/*   Updated: 2024/05/29 20:52:30 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &to_cpy) 
{
    (void)to_cpy;
}

Serializer &Serializer::operator=(const Serializer &to_cpy) 
{
    (void)to_cpy; 
    return (*this);
}



uintptr_t    Serializer::serialize(Data  *ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data         *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}