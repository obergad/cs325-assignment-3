//Author: Adam Oberg
//Date: 1/29/2021
//Description: Program for cs325 assignment 3
/*
Input: The input file named “shopping.txt” consists of T test cases
 T (1 ≤ T ≤ 100) is given on the first line of the input file.
 Each test case begins with a line containing a single integer number N that
indicates the number of items (1 ≤ N ≤ 100) in that test case
 Followed by N lines, each containing two integers: P and W. The first integer
(1 ≤ P ≤ 5000) corresponds to the price of object and the second integer
(1 ≤ W ≤ 100) corresponds to the weight of object.
 The next line contains one integer (1 ≤ F ≤ 30) which is the number of people
in that family.
 The next F lines contains the maximum weight (1 ≤ M ≤ 200) that can be carried
 by the ith person in the family (1 ≤ i ≤ F).
Output: Written to a file named “results.txt”. For each test case your program
should output the maximum total price of all goods that the family can carry out
during their shopping spree and for each the family member, numbered 1 ≤ i ≤ F,
list the item numbers 1 ≤ N ≤ 100 that they should select.

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


int main(int argc, char const *argv[]) {
  std::ifstream file;
  std::vector<item> items;
  std::vector<int> people;
  int num_items, num_people, tempInt, maxValue, test_cases;
  item tempItem;
  file.open("shopping.txt");
  file >> test_cases;
  for (size_t j = 0; j < test_cases; j++) {
    std::cout << "======= Case number " << j + 1 << " ==========="<<'\n';
    items.clear();
    people.clear();
    file >> num_items;
    // std::cout << "Total Items: "<< num_items << '\n';
    for (int i = 0; i < num_items; i++) {
      file >> tempItem.value;
      maxValue += tempItem.value;
      file >> tempItem.weight;
      items.push_back(tempItem);
      // std::cout << "Item: "<< i << " val,weight || "<< items[i].value << "," << items[i].weight << '\n';
    }
    file >> num_people;
    // std::cout << "Total People: "<< num_people << '\n';
    for (int i = 0; i < num_people; i++) {
      file >> tempInt;
      people.push_back(tempInt);
      // std::cout << "Person: " << i << " cap: " << people[i] <<'\n';
    }
    //Run test cases
    std::cout << "Max Value: "<< maxValue << '\n' << "Memeber's Value" << '\n';
    for (size_t i = 0; i < num_people; i++) {
      maxValue = dpAlgo(people[i], items, num_items);
      std::cout << i <<": " << maxValue << '\n';
    }
  }
  return 0;
}
