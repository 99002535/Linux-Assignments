#include <string>
#pragma once


class Movie
{
   public:
    std::string code;
    std::string name;
    std::string date;
    long int cost;

    public:
        Movie();
        Movie(std::string, std::string, std::string, long int);
        virtual long int getCost()=0;
       // void setStudent(int ID, std::string name, double percentage, std::string gender);


};


