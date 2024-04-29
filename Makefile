CPPFLAGS = -std=c++11 -Wall
LDLIBS = -lm

testa_romano: romano.o testa_romano.cpp
	$(CXX) $(CPPFLAGS) romano.o testa_romano.cpp -o testa_romano $(LDLIBS)

romano.o: romano.cpp romano.hpp
	$(CXX) $(CPPFLAGS) -c romano.cpp -o romano.o

test: testa_romano
	./testa_romano

cpplint:
	cpplint --exclude=catch.hpp *.cpp *.hpp

gcov: testa_romano
	g++ $(CPPFLAGS) -fprofile-arcs -ftest-coverage romano.cpp testa_romano.cpp -o testa_romano
	./testa_romano
	gcov *.cpp

debug: testa_romano
	g++ $(CPPFLAGS) -g romano.cpp testa_romano.cpp -o testa_romano
	gdb testa_romano

cppcheck:
	cppcheck --enable=warning *.cpp *.hpp

valgrind: testa_romano
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_romano

clean:
	rm -rf *.o *.exe *.gc* testa_romano

