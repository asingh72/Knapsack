all:
	g++ -std=c++11 brute_force_knapsack.cpp -o brute_force_knapsack.out
	g++ -std=c++11 greedy_algorithm.cpp -o greedy_algorithm.out
	g++ -std=c++11 dynamic_programming_knapsack.cpp -o dynamic_programming_knapsack.out
	
	