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

int max(int a, int b){
  return (a > b) ? a : b;
}

int recursiveAlgoRec(int weight, std::vector<item> v, int i, int** array) {
    // base condition
    if (i < 0)
        return 0;
    if (array[i][weight] != -1)
        return array[i][weight];

    if (v[i].weight > weight) {

        // Store the value of function call
        // stack in table before return
        array[i][weight] = recursiveAlgoRec(weight,v, i - 1, array);
        return array[i][weight];
    }
    else {
        // Store value in a table before return
        array[i][weight] = max(v[i].value + recursiveAlgoRec(weight - v[i].weight,
           v, i - 1, array), recursiveAlgoRec(weight, v, i - 1, array));
        // Return value of table after storing
        return array[i][weight];
    }
}

int recursiveAlgo(int weight, std::vector<item> v, int n){
    // double pointer to declare the
    // table dynamically
    int** array;
    array = new int*[n];

    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
      array[i] = new int[weight + 1];

    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < weight + 1; j++)
            array[i][j] = -1;
    return recursiveAlgoRec(weight, v, n - 1, array);
}

//Solve the DP algorithm for the assignment

int dpAlgo(int weight, std::vector<item> v, int n){
    int i, w;
    int knapsack[n + 1][weight + 1];
    for (i = 0; i <= n; i++){
        for (w = 0; w <= weight; w++){
            if (i == 0 || w == 0)
                knapsack[i][w] = 0;
            else if (v[i - 1].weight <= w)
                knapsack[i][w] = max(v[i - 1].value +
                  knapsack[i - 1][w - v[i - 1].weight],knapsack[i - 1][w]);
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
  n= 20;
  for (w= 100; w <= 1000; w+=100) {
    items.clear();
    items = generation(n);
    std::cout << "n = "<< n << " weight = "<< w;
    //dp ================================================================ dp
    auto start = std::chrono::steady_clock::now(); //start the clock
    dp = dpAlgo(w, items, n);
    auto end = std::chrono::steady_clock::now(); // stop the steady_clock
    std::cout << "| |Dp time: " <<
    std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
    << " μs. " << "max DP: "<< dp;
    //dp ================================================================ dp
    //Rec ================================================================ Rec
    auto start1 = std::chrono::steady_clock::now(); //start the clock
    rec = recursiveAlgo(w, items, n);
    auto end1 = std::chrono::steady_clock::now(); // stop the steady_clock
    std::cout << "| |Rec time: " <<
    std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count()
    << " μs " << "max Rec: "<< rec << '\n';
    //Rec ================================================================ Rec
  }
  return 0;
}
