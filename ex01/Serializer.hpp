/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:48 by francesco         #+#    #+#             */
/*   Updated: 2024/04/25 15:36:04 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALZER_HPP
# define SERIALIZER_HPP

# include "struct.hpp"
# include <iostream>
# include <cstdint>

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