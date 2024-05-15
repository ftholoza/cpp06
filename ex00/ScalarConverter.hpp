/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:11:08 by francesco         #+#    #+#             */
/*   Updated: 2024/04/19 18:27:25 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALAR_CONVERT_HPP
# define SCALAE_CONVERTER_HPP

# include "iostream"

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter &operator=(ScalarConverter &to_copy);
        static void convert(std::string to_convert);
};

#endif