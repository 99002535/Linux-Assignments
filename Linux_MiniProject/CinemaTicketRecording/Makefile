all: all.out
all.out : Movie.o MovieLang.o Moviedb.o Movie-test.o Moviedb-test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
Moviedb-test.o: Moviedb-test.cpp Movie.h MovieLang.h Moviedb.h
	g++ $< -c
Movie-test.o: Movie-test.cpp Movie.h MovieLang.h
	g++ $< -c
Moviedb.o: Moviedb.cpp Moviedb.h MovieLang.h Movie.h
	g++ $< -c
MovieLang.o: MovieLang.cpp MovieLang.h Movie.h
	g++ $< -c
Movie.o: Movie.cpp Movie.h
	g++ $< -c
clean:
	rm -rf *.o *.out
