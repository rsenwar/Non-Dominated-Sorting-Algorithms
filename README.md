### Non-Dominated-Sorting-Algorithms

Implementation of some non-dominated sorting algorithms:
1. DDA-ENS: Dominance Degree Approach based Efficient Non-dominated Sorting. This is our proposed approach.  
2. Dominance Degree Approach for Non-Dominated Sorting (DDA-NS) [1]
3. Fast non-dominated sorting [2]

#### Dataset:
There are two types of Datasets used for experimentation.

**1. Cloud Dataset:** Solutions randomly sampled from a uniform distribution on the interval [0,1]. Number of solutions vary from 100 to 5000 with an increment of 100, total 50 set of solutions. Four different number of objectives – 2, 5, 10 and 15 are considered. Total data files, 50*4 = 200.

Data file name format: *data_M_N.txt*, where M represents the number of objectives and N represents the number of solutions.


**2. Fixed fronts Dataset:** The number of fronts has been varied from 2 to 70 with an increment of 1. Thus, a total of 69 populations. Number of solutions fixed to N = 2000, Four different objectives - 2, 5, 10, 15 are considered. For each objective there are 69 data files. Total data files, 69*4 = 276.

Data file name format: *data_M_k.txt*, where M represents the number of objectives and k represents the number of fronts.



#### References
[1] Y. Zhou, Z. Chen, and J. Zhang, "Ranking Vectors by Means of the Dominance Degree Matrix," IEEE Transactions on Evolutionary
Computation, vol. 21, no. 1, pp. 34–51, 2017.

[2] K. Deb, A. Pratap, S. Agarwal, and T. Meyarivan, "A Fast and Elitist Multiobjective Genetic Algorithm: NSGA-II," IEEE Transactions on Evolutionary Computation, vol. 6, no. 2, pp. 182–197, April 2002.
