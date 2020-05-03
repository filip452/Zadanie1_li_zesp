
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: szablony
	./szablony 

szablony: obj/main.o obj/wek.o obj/LZ.o obj/macierz.o obj/UklRown.o
	g++ -Wall -pedantic -o szablony obj/main.o obj/wek.o obj/LZ.o\
		obj/macierz.o obj/UklRown.o

obj/main.o: src/main.cpp inc/wek.hh src/wekC.cpp inc/macierz.hh\
		src/macierzC.cpp inc/UklRown.hh src/UklRownC.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZ.o: inc/LZ.hh src/LZ.cpp
	g++ ${CPPFLAGS} -o obj/LZ.o src/LZ.cpp

obj/wek.o: src/wekC.cpp inc/wek.hh
	g++ ${CPPFLAGS} -o obj/wek.o src/wekC.cpp

obj/macierz.o: src/macierzC.cpp inc/macierz.hh
	g++ ${CPPFLAGS} -o obj/macierz.o src/macierzC.cpp

obj/UklRown.o: src/UklRownC.cpp inc/UklRown.hh
	g++ ${CPPFLAGS} -o obj/UklRown.o src/UklRownC.cpp

clean:
	rm -f obj/*.o szablony
