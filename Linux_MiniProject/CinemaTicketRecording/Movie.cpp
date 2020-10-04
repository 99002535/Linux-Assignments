#include"Movie.h"
#include <string>


Movie::Movie():code(),name(),date(),cost(0){}

Movie::Movie(std::string code, std::string name, std::string date, long int cost) : code(code), name(name), date(date), cost(cost) {}

