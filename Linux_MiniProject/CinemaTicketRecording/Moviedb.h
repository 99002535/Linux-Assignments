#include<cstdint>
#include "Movie.h"
#include "MovieLang.h"
#pragma once
#include <list>
#include <iterator>
#pragma once

class Moviedb :  public MovieLang {
  public :
    std::list <MovieLang> ml;
  public :

    void addMovie(std::string, std::string, std::string, long int, std::string);
    void removeMovie(std::string);
    MovieLang* findMovieByCode(std::string);
    int countAll();
};






