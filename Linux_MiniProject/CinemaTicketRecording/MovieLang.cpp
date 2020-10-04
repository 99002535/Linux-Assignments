#include <string>
#include "Movie.h"
#include "MovieLang.h"

MovieLang::MovieLang():Movie(),lang(""){}

MovieLang::MovieLang(std::string code, std::string name, std::string date,long int cost, std::string lang):
    Movie(code,name,date,cost),lang(lang){
}
std::string MovieLang::getCode() {
    return code;
}
std::string MovieLang::getLang() {
    return lang;
}
std::string MovieLang::getName() {
    return name;
}
long int MovieLang::getCost() {
    return cost;
}
