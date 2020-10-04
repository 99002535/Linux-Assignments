#include "MovieLang.h"
#include "Movie.h"
#include "Moviedb.h"
#include <string>
#include <list>
#include <iterator>
#include <thread>
#include <semaphore.h>
#include <iostream>

void Moviedb::addMovie(std::string cd, std::string name, std::string dt,long int cst, std::string lng) {
    ml.push_back(MovieLang(cd, name, dt, cst, lng));
}

void Moviedb::removeMovie(std::string name) {
    std::list<MovieLang> :: iterator iter;
    for(iter=ml.begin(); iter!=ml.end(); iter++) {
        if(iter->getName()== name) {
            ml.erase(iter);
            break;
        }
    }
}

int Moviedb::countAll() {
    return ml.size();
}


