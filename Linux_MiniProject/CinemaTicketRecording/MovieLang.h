#include "Movie.h"
#pragma once

class MovieLang : public Movie {
  private :
    std::string lang;
  public :
    MovieLang();
    MovieLang(std::string,std::string,std::string,long int,std::string);
    std::string getCode();
    std::string getLang();
    std::string getName();
    long int getCost();
};

