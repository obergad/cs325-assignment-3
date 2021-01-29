//Author: Adam Oberg
//Date: 1/29/2021
//Description: Program for cs325 assignment 3
/*
 Implement both algorithms in one program named knapsack. Your program should
 randomly generate test cases that are solved using both the DP and Recursive
 algorithm. The program should output to the terminal: n, weight, time for the DP
 algorithm, max for the DP, time for the Recursive algorithm, max for
 Recursive. The max values should be the same.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>

struct item {
public:
  int weight;
  int value;
};

//Solve the Recursive algorithm for the assignment
void recursiveAlgo(){

}

//Solve the DP algorithm for the assignment
int max(int a, int b){
  return (a > b) ? a : b;
}

int dpAlgo(int weight, std::vector<item> v, int n){
    int i, w;
    int knapsack[n + 1][weight + 1];
    for (i = 0; i <= n; i++){
        for (w = 0; w <= weight; w++){
            if (i == 0 || w == 0)
                knapsack[i][w] = 0;
            else if (v[i - 1].weight <= w)
                knapsack[i][w] = max(v[i - 1].value
                          + knapsack[i - 1][w - v[i - 1].weight],
                          knapsack[i - 1][w]);
            else
                knapsack[i][w] = knapsack[i - 1][w];
        }
    }

    return knapsack[n][weight];
}

std::vector<item> generation(int n){
  std::vector<item> v;
  item temp;
  for (int i = 0; i < n; i++) {
    temp.weight = rand() % 100+ 1;
    temp.value = rand() % 100 + 1;
    v.push_back(temp);
  }
return v;
}



int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int n , w, dp, rec;
  std::vector<item> items;
  w = 100;
  for (n = 10; n < 40; n+=5) {
    items.clear();
    items = generation(n);
    std::cout << "n = "<< n << " weight = "<< w << '\n';
    //dp ================================================================ dp
    auto start = std::chrono::steady_clock::now(); //start the clock
    dp = dpAlgo(w, items, n);
    auto end = std::chrono::steady_clock::now(); // stop the steady_clock
    std::cout << "Dp time: " <<
    std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
    << " μs. " << "max DP: "<< dp << '\n';
    //dp ================================================================ dp
  }


  return 0;
}
