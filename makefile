CC = g++ -std=c++11 -g

all:  knapsack shopping

knapsack: knapsack.o
		$(CC) knapsack.o -o knapsack

knapsack.o: knapsack.cpp
	$(CC) -c knapsack.cpp

shopping: shopping.o
		$(CC) shopping.o -o shopping

shopping.o: shopping.cpp
	$(CC) -c shopping.cpp

clean:
	rm -f *.o knapsack shopping
