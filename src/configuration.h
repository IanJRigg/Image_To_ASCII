#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <cstdint>
#include <iostream>

#define NORMAL   "\x1B[0m"
#define RED      "\x1B[91m"
#define GREEN    "\x1B[92m"
#define YELLOW   "\x1B[93m"
#define BLUE     "\x1B[94m"
#define MAGENTA  "\x1B[95m"
#define CYAN     "\x1B[96m"
#define WHITE    "\x1B[97m"

typedef std::int_fast8_t   Int8;
typedef std::int_fast16_t  Int16;
typedef std::int_fast32_t  Int32;
typedef std::int_fast64_t  Int64;

typedef std::uint_fast8_t  UInt8;
typedef std::uint_fast16_t UInt16;
typedef std::uint_fast32_t UInt32;
typedef std::uint_fast64_t UInt64;

#define Print_Out(stream) std::cout << YELLOW << stream << NORMAL << std::endl;
#define Print_Err(stream) std::cout << RED    << stream << NORMAL << std::endl;

#endif