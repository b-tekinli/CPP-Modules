#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

typedef struct s_data {
    std::string username;
    int		    age;
    double	    level;
} t_data;

uintptr_t serialize(t_data* ptr);

t_data* deserialize(uintptr_t raw);

#endif
