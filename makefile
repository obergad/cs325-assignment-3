CC = g++ -std=c++11 -g

all:  knapsack

generatetxt: knapsack.o
		$(CC) knapsack.o -o knapsack

generatetxt.o: knapsack.cpp
	$(CC) -c knapsack.cpp

clean:
	rm -f *.o generatetxt
