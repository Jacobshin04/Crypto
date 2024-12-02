a.out: main.o Linear.o Caesar.o Cipher.o Rsa.o
	g++ -g main.o Cipher.o Linear.o Caesar.o Rsa.o

main.o: main.cpp Cipher.hpp
	g++ -g -c main.cpp

Cipher.o: Cipher.cpp Cipher.hpp Caesar.hpp Linear.hpp Rsa.hpp
	g++ -g -c Cipher.cpp

Linear.o: Linear.cpp Cipher.hpp Linear.hpp
	g++ -g -c Linear.cpp

Caesar.o: Caesar.cpp Cipher.hpp Caesar.hpp
	g++ -g -c Caesar.cpp

Rsa.o: Rsa.cpp Rsa.hpp Cipher.hpp
	g++ -g -c Rsa.cpp
clean:
	rm -f *.o a.out

run:
	./a.out

debug:
	gdb ./a.out
