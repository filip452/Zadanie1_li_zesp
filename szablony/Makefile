
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: szablony
	./szablony

szablony: obj/main.o obj/wek.o obj/LZ.o
	g++ -Wall -pedantic -o szablony obj/main.o obj/wek.o obj/LZ.o

obj/main.o: src/main.cpp inc/wek.hh src/wek.cpp src/wekC.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZ.o: inc/LZ.hh src/LZ.cpp
	g++ ${CPPFLAGS} -o obj/LZ.o src/LZ.cpp

obj/wek.o: src/wek.cpp src/wekC.cpp inc/wek.hh
	g++ ${CPPFLAGS} -o obj/wek.o src/wekC.cpp

clean:
	rm -f obj/*.o szablony
