# Non-Dominated-Sorting-Algorithms

Implementation of some non-dominated sorting algorithms:
1. DDA-ENS: Dominance Degree Approach based Efficient Non-dominated Sorting. This is our proposed approach.  
2. Dominance Degree Approach for Non-Dominated Sorting (DDA-NS) [1]
3. Fast non-dominated sorting [2]

# Dataset:
Dataset contains randomly generated data for objective values, M = 2, 5, 10, 15.
For each objective, there is data for different number of solutions, N = 100, 200, 300, ... 2000
For each number of solutions, there are 50 dataset files. We have computed the average runtime for all the 50 datasets.

Filename format: data_N_M_i, where i: File number, N: Number of solutions & M: Number of objectives


[1] Y. Zhou, Z. Chen, and J. Zhang, "Ranking Vectors by Means of the Dominance Degree Matrix," IEEE Transactions on Evolutionary
Computation, vol. 21, no. 1, pp. 34–51, 2017.

[2] K. Deb, A. Pratap, S. Agarwal, and T. Meyarivan, "A Fast and Elitist Multiobjective Genetic Algorithm: NSGA-II," IEEE Transactions on Evolutionary Computation, vol. 6, no. 2, pp. 182–197, April 2002.
