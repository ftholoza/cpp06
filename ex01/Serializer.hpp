/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:48 by francesco         #+#    #+#             */
/*   Updated: 2024/05/29 20:53:21 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "struct.hpp"
# include <iostream>
# include <stdint.h>

class Serializer
{
    private:
        Serializer();
		Serializer(const Serializer &to_cpy);
		~Serializer();
		Serializer &operator=(const Serializer &to_cpy);

        
    public:
        static uintptr_t    serialize(Data  *ptr);
        static Data         *deserialize(uintptr_t raw);
};

# endif