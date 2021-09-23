#include <iostream>
#include <stdio.h>
#include "my_lib.h"

void print_hello_world()
{
    printf("printf - Hello World!\n");
}

void cout_hello_world()
{
    std::cout << "cout - Hello World!" << std::endl;
}

linalg::aliases::float3 print_linalg_vector() 
{
    linalg::aliases::float3 my_float3 {1,2,3};

    std::cout << "Vec: " << my_float3[0] << my_float3[1] << my_float3[2] << std::endl;

    return my_float3;
}

bool print_boost_version()
{
    std::cout << "Boost version: " << BOOST_VERSION << std::endl;

    return true;
}