#include "Movie.h"
#include "MovieLang.h"
#include "Moviedb.h"
#include <gtest/gtest.h>
#include<iostream>
#include<pthread.h>
#include<semaphore.h>
#include<list>
#include<iterator>
#include<cstdint>


pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
Moviedb movies;


void* efun1(void* pv) {



    pthread_mutex_lock(&m1);

    movies.addMovie("1","Avengers:Infinity War","27-04-2018", 250,"English");
    movies.addMovie("2","Deadpool 2","01-05-2018", 250,"English");
    movies.addMovie("3","Andhadhun","05-08-2018", 250,"Hindi");
    movies.addMovie("4","Sarileru Neekevvaru","11-01-2020", 200,"Telugu");
    movies.addMovie("5","Ala Vaikhuntapuramulo","12-01-2020", 200,"Telugu");
    movies.addMovie("6","Badla","08-03-2019", 200,"Hindi");

    pthread_mutex_unlock(&m1);
    sem_post(&s1);

}


void* efun2(void* pv) {


    sem_wait(&s1);            //changing sequence lead to deadlock
    pthread_mutex_lock(&m1);

    std::cout<<"\n";
    std::cout<<"The owner added :"<<movies.countAll()<<" Movies\n";
    std::cout<<"\n";

    pthread_mutex_unlock(&m1);
    //pthread_exit(NULL);
}

namespace {

class MovieLangdbTest : public ::testing::Test {

  protected:
    void SetUp() {

    }
    void TearDown() {}
};

TEST_F(MovieLangdbTest, AddMovieTest) {

    pthread_t pt1,pt2;    //thread handles
    sem_init(&s1,0,0);
    pthread_create(&pt1,NULL,efun1,NULL);
    pthread_create(&pt2,NULL,efun2,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);

    movies.addMovie("7","Bahubali 2","28-04-2017",250,"Telugu");
    EXPECT_EQ(7, movies.countAll());

    sem_destroy(&s1);
    pthread_mutex_destroy(&m1);
}


TEST_F(MovieLangdbTest, RemoveMovieTest) {
    movies.removeMovie("Badla");
    EXPECT_EQ(6, movies.countAll());
}
TEST_F(MovieLangdbTest, CountTest) {             //Just After Setup
    EXPECT_EQ(6, movies.countAll());
}

TEST_F(MovieLangdbTest, AnotherTest) {         //Just After Setup
    movies.addMovie("8","Srimanthudu","07-08-2015",200,"Telugu");
    movies.addMovie("9","The Social Network","12-11-2010",0,"English");
    EXPECT_EQ(8, movies.countAll());

}
}

