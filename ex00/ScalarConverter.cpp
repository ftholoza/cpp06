/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:32:32 by francesco         #+#    #+#             */
/*   Updated: 2024/05/16 16:36:09 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include "limits"
# include "limits.h"
# include "cerrno"
# include "iostream"
# include "iomanip"
# include "string"
# include <cfloat>
# include <cmath>

void    print_char(std::string str)
{
    double  nb;

    nb = atof(str.c_str());
    if (isascii(nb))
    {
        if (std::isprint(nb))
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: " << "Impossible: Non Ascii" << std::endl;
    return ;
}

void    print_float(std::string str)
{
    float   value;
    float   x;
    
    value = atof(str.c_str());
    x = std::modf(value, &x);
    if (x == 0)
       std::cout << "float: " << value << ".0f" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl; 
}

void    print_double(std::string str)
{
    double   value;
    double   x;
    
    value = atof(str.c_str());
    x = std::modf(value, &x);
    if (x == 0)
        std::cout << "double: " << value << ".0" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

bool     is_digit(std::string data)
{
    const char      *str;
    int             i;

    i = 1;
    str = data.c_str();
    if (!std::isdigit(str[0]) && (str[0] != '-' && str[0] != '+'))
        return (false);
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool    is_char(std::string data)
{
    if (data.size() != 1)
        return (false);
    else
    {
        if (isascii(data.front()) && isprint(data.front()) && !is_digit(data))
            return (true);
        else
            return (false);
    }
    return (false);
}

bool    is_int(std::string data)
{
    const char *str = data.c_str();
    bool        flag = false;
    int         i = 0;
    
    if (str[0] == '+' || str[0] == '-')
        i++;
    while (i < data.size())
    {
        if (std::isdigit(str[i]))
            i++;
        else
            return (false);  
    }
    return (true);
}

bool    is_float(std::string data)
{
    const char *str = data.c_str();
    bool        flag = false;
    int         i = 0;
    
    if (data == "+inff" || data == "-inff" || data == "inff" || data == "nanf")
        return (true);
    if (data.back() != 'f')
        return (false);
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (str[i] == '.')
        return false;
    while (i < data.size() - 1)
    {
        if (str[i] == '.' && flag == false)
        {
            flag = true;
            i++;
        }
        else if (std::isdigit(str[i]))
            i++;
        else
            return (false);
    }
    if (data.size() > 1 && data[data.size() -2] == '.')
       return (false);
    return (true);
}

bool    float_check_overflow(std::string str)
{
    float   value;
    
    value = std::atof(str.c_str());
    if (std::isinf(value))
        return (true);
    return (false);
}

bool    double_check_overflow(std::string str)
{
    double  value;
    
    value = std::atof(str.c_str());
    if (std::isinf(value))
        return (true);
    return (false);
}

bool    int_check_overflow(std::string str)
{
    int i;
    
    if (str.find('.') != -1)
    {
        i = str.find('.');
        while (str.size() != i)
            str.erase(str.size() - 1);      
    }
    if (str.back() == 'f')
        str.erase(str.size() - 1);
    if (str.size() == 11)
    {
        if (str.front() == '-' && str.compare("-2147483648") > 0)
            return (true);
        if (str.front() == '+' && str.compare("+2147483647") > 0) 
            return (true);
        if (str.front() == '-' && str.compare("-2147483648") <= 0)
            return (false);
        if (str.front() == '+' && str.compare("+2147483647") <= 0) 
            return (false);
    }
    if (str.size() == 10)
    {
        if (str.compare("2147483647") > 0)
            return (true);
        if (str.compare("2147483647") <= 0)
            return (false);
    }
    if (str.size() > 11)
        return (true);
    return (false);
}

bool    is_double(std::string data)
{
    const char *str = data.c_str();
    bool        flag = false;
    int         i = 0;
    
    if (data.find('.') == data.size() -1)
        return (false);
    if (data == "+inf" || data == "-inf" || data == "inf" || data == "nan")
        return (true);
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (str[i] == '.')
        return false;
    while (i < data.size())
    {
        if (str[i] == '.' && flag == false)
        {
            flag = true;
            i++;
        }
        else if (std::isdigit(str[i]))
            i++;
        else
            return (false);  
    }
    return (true);
}

void    converter_char(std::string str)
{
    if (!std::isprint(str.front()))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << str.front() << std::endl;
    std::cout << "int: " << static_cast<int>(str.front()) << std::endl;
    std::cout << "float: " << static_cast<float>(str.front()) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str.front()) << ".0" << std::endl;
}

void    converter_int(std::string str)
{
    int nb;

    nb = std::atoi(str.c_str());
    print_char(str);
    if (int_check_overflow(str) == true)
        std::cout << "int: " << "impossible oflw" << std::endl;
    else
        std::cout << "int: " << std::atoi(str.c_str()) << std::endl; 
    if (float_check_overflow(str))
        std::cout << "float: " << nb << "f" << std::endl;
    else
        print_float(str);
    print_double(str);
}

bool    check_inf(std::string str)
{
    if (str == "+inff" || str == "inff" || str == "-inff" || str == "nanf")
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.erase(str.size() -1) << std::endl;
        return (true);
    }
    if (str == "+inf" || str == "inf" || str == "-inf" || str == "nan")
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return (true);
    }
    return (false);
}

void    converter_float(std::string str)
{
    double   nb;
    bool     flag = false;
    nb = std::atof(str.c_str());
    if (check_inf(str) == true)
        return ;
    print_char(str);
    if (int_check_overflow(str))
       std::cout << "int: " << "Impossible oflw" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    if (float_check_overflow(str))
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    else
        print_float(str);
    std::cout << "double: " << nb << std::endl;
}

void    converter_double(std::string str)
{
    double   nb;

    nb = atof(str.c_str());
    if (check_inf(str) == true)
        return ;
    print_char(str);
    if (int_check_overflow(str))
        std::cout << "int: " << "Impossible ofw" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    if (float_check_overflow(str))
        std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    else
        print_float(str);
    std::cout << "double: " << nb << std::endl;
}

int return_type_value(std::string str)
{
    if (is_char(str))
        return (0);
    if (is_int(str))
        return (1);
    if (is_float(str))
        return (2);
    if (is_double(str))
        return (3);
    return (4);
}

void ScalarConverter::convert(std::string to_convert)
{
    switch (return_type_value(to_convert))
    {
        case 0:
            converter_char(to_convert);
            break;
        case 1:
            converter_int(to_convert);
            break;
        case 2:
            converter_float(to_convert);
            break;
        case 3:
            converter_double(to_convert);
            break;
        default:
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: " << "Impossible" << std::endl;
            std::cout << "float: " << "Impossible" << std::endl;
            std::cout << "double: " << "Impossible" << std::endl;
        break ;
    }
    return ;
}