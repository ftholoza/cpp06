/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:11:08 by francesco         #+#    #+#             */
/*   Updated: 2024/05/29 20:46:58 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include "iostream"
# include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ScalarConverter &operator=(ScalarConverter &to_copy);
        static void convert(std::string to_convert);
};

#endif