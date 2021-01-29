//Author: Adam Oberg
//Date: 1/29/2021
//Description: Program for cs325 assignment 3
/*
 Implement both algorithms in one program named knapsack. Your program should
 randomly generate test cases that are solved using both the DP and Recursive
 algorithm. The program should output to the terminal: n, W, time for the DP
 algorithm, max for the DP, time for the Recursive algorithm, max for
 Recursive. The max values should be the same.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class item {
public:
  int weight;
  int value;
};
//Solve the Recursive algorithm for the assignment
void recursiveAlgo(){

}

//Solve the DP algorithm for the assignment
void dpAlgo(){

}

std::vector<item> generation(int n){
  std::vector<item> v;
  item temp;
  for (size_t i = 0; i < n; i++) {
    temp.weight = rand () % 100 + 1;
    temp.value = rand () % 100 + 1;
    v.pushback(temp);
  }
return v;
}



int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int n , w;
  std::vector<items> items;
  std::cout << "How many N values would you like?: ";
  std::cin >> n;
  std::cout << "\nWhat is the weight of your knapsack?: ";
  std::cin >> w;
  items = generation(n);

  return 0;
}
