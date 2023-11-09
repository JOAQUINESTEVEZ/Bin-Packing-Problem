# Solving Bin Packing Problem Using Approximate Greedy Algorithms

## Overview

The bin packing problem is a combinatorial optimization problem with many
real-world applications in logistics and operations research. The goal is to
efficiently pack a set of items with different sizes into a finite number of
bins.


Different heuristic solutions are compared to an optimal packing
obtained by brute force search. This project provides an engaging way to
explore optimization algorithms, understand the tradeoffs between heuristics
and exact solutions, and reinforce core concepts like greedy algorithms,
recursion, and dynamic programming.

## Project Description

The bin packing problem (BPP) involves packing a set of items with different
sizes into bins of fixed capacity. The goal is to minimize the number of bins
used.

Key aspects of the bin packing problem:

+ Items are provided as a list of sizes between 0 and 1.
+ Bins have capacity 1.
+ An item can be placed in a bin if it fits within the remaining capacity.
+ The objective is to pack all items using the minimum number of bins.

This is a combinatorial NP-hard optimization problem with many applications:

+ Packing trucks or containers to minimize number of vehicles
+ Resource allocation with limited capacities
+ Cutting stock problems in manufacturing

### Algorithm Overview
Greedy algorithms are algorithms that make a series of choices by selecting the
best option available without concerning for future consequences. Greedy
algorithms with heuristics provide near-optimal solutions to problems that are
computationally intensive to solve optimally. By making use of certain "rules
of thumb" or strategies, they achieve solutions in a reasonable time frame,
albeit without a guarantee of optimality.

In the context of BPP, greedy algorithms iteratively pack the next item into a
bin based on one of the following heuristics.

---

#### First Fit (FF)

**Principle**: The First Fit heuristic works on the principle of immediacy. As
soon as it encounters an item, it tries to fit it into the bins in the order
they were created or exist.

**Procedure**:
1. Start with the first bin and the first item.
2. Try to fit the current item into the bin.
3. If it fits, move on to the next item.
4. If it doesn't, try the next bin.
5. If no bins can accommodate the item, open a new bin.

**Efficiency**: It’s a fast approach since it doesn’t require searching through
all bins. However, it may not always yield the most space-efficient packing.

---

#### Next Fit (NF)

**Principle**: Next Fit is a variant of First Fit. Instead of checking all
previous bins, it only checks the last bin used.

**Procedure**:
1. Begin with the first item and the first bin.
2. Try to fit the current item into the current bin.
3. If it fits, proceed to the next item.
4. If it doesn't fit, open a new bin and place the item there.

**Efficiency**: While this approach is faster than First Fit, it tends to use
more bins since it doesn’t check all previously opened bins for potential
space.

---

#### Best Fit (BF)

**Principle**: The Best Fit heuristic is more discerning. It aims to utilize
space efficiently by placing each item into the tightest spot possible.

**Procedure**:
1. For each item, scan through all the bins.
2. Identify the bin where the item fits the most snugly — that is, the bin
   which will have the smallest leftover space after placing the item.
3. If no bin can accommodate the item, open a new bin.

**Efficiency**: Best Fit tends to use bins more efficiently than First Fit and
Next Fit since it seeks the tightest fit for each item. However, this approach
requires more computational time as it checks all bins for the best fit for
each item.

---

The BPP comes in two versions: online and offline. Both have practical
applications in real-world situations.

#### Online BPP

Items are processed in the order they are received, and once an item is placed
in a bin, the decision cannot be changed. Heuristics that can be used:

+ First Fit
+ Next Fit
+ Best Fit

#### Offline BPP

All items are known beforehand. This allows the algorithm to make more informed
decisions based on a global view of all items. There are many complicated
techniques to make the offline algorithm better but we will only focus on one
simple strategy here.

With the global view, we will add one ``pre-process`` step before applying the
heuristics. In this step, the bins are sorted in the descending order of the
item sizes. By packing larger items first, the results are more optimal than
the online version even with the same heuristics.

+ First Fit
+ Best Fit

### Input
The program expect to read data on item sizes from a text file named
``items.txt``. The format looks like:

```
0.41
0.50
...
0.90
```

Each line has an item size and you need count the number of items. Make sure
that you will read in 12 item sizes.

### Output
The program should generate a structured output to provide a clear and concise understanding of the results. The output should primarily consist of:

1. A message showing how many item sizes are loaded from the file.
1. A summary table showing the number of bins used by each algorithm.
1. Detailed bin allocation for each algorithm. Display sizes with 2 decimal
   places.

### Baseline Algorithm

The brute-force approach for the bin packing problem aims to generate all
possible permutations of item placements within the bins. For each permutation,
it calculates the number of bins used. The solution that uses the least number
of bins is considered the optimal placement.

The number of permutations for ``n`` items will be ``n!``. With each
permutation, pack them one by one into bins, start a new bin when last bin is
full. Use the number of bins to select the best result.

### Compilation
- Under WSL, type the command “make”, followed by the command “./main”.
- After using the program, run the command “make clean”.