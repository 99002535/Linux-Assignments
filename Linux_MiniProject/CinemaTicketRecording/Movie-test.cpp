#include "Movie.h"
#include "MovieLang.h"
#include "Moviedb.h"
#include <gtest/gtest.h>

namespace {

class MovieTest : public ::testing::Test {

  protected:
    void SetUp() {
        ptr = new MovieLang("1","Avengers:Infinity War","27-04-2018", 250,"English");
    }
    void TearDown() {
        delete ptr;
    }
    Movie *ptr;
};

TEST_F(MovieTest, DefaultConstructor) {
    MovieLang ft;
    EXPECT_EQ(0, ft.getCode().length());
    EXPECT_EQ(0, ft.getLang().length());
    EXPECT_EQ(0, ft.getName().length());
    EXPECT_EQ(0, ft.getCost());
}
TEST_F(MovieTest, ParameterizedConstructor) {
    MovieLang *fptr = dynamic_cast<MovieLang*>(ptr);
    EXPECT_STREQ("1", fptr->getCode().c_str());
    EXPECT_STREQ("English", fptr->getLang().c_str());
    EXPECT_STREQ("Avengers:Infinity War", fptr->getName().c_str());
    EXPECT_EQ(250, fptr->getCost());
}
TEST_F(MovieTest, AnotherTest) {
    MovieLang ft("2","Andhadhun","05-08-2018",200,"Hindi");
    Movie *pt = &ft;
    EXPECT_STREQ( "2", ft.getCode().c_str());
    EXPECT_STREQ("Hindi", ft.getLang().c_str());
    EXPECT_STREQ("Andhadhun", ft.getName().c_str());
    EXPECT_EQ(200, ft.getCost());
}

}



