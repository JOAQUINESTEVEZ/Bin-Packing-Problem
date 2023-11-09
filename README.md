[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/UPpUQdeP)
# Solving Bin Packing Problem Using Approximate Greedy Algorithms
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Overview

The bin packing problem is a combinatorial optimization problem with many
real-world applications in logistics and operations research. The goal is to
efficiently pack a set of items with different sizes into a finite number of
bins.

In this project, you will gain first-hand experience with different algorithms
for solving bin packing problems. You will implement online algorithms that
pack items one by one without knowing the full input in advance. You will also
implement offline algorithms that can look at all the items first before
packing.

Finally, you will compare these heuristic solutions to an optimal packing
obtained by brute force search. This project provides an engaging way to
explore optimization algorithms, understand the tradeoffs between heuristics
and exact solutions, and reinforce core concepts like greedy algorithms,
recursion, and dynamic programming.

The skills you will exercise include:

+ Implement greedy algorithms and compared to a baseline brute-force algorithm
+ Designing classes using UML
+ Create modular project structure with Makefile to automate the building
  process
+ Documenting and testing your code thoroughly

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

To obtain the optimal solution for the bin packing problem, one approach is to
employ a brute-force algorithm that exhaustively explores all conceivable
combinations to identify the optimal solution. Because the bin packing problem
showcases optimal substructure and overlapping subproblems, it is amenable to
dynamic programming for optimal solution too. However, for the scope of this
project, we won't delve into this dynamic programming-based approach.

The reason for bypassing exact solutions, even those relying on dynamic
programming, lies in their inherent exponential complexity. Instead, we will
investigate an alternative approach using an approximate greedy algorithm to
address the problem. In this context, heuristics such as first-fit, next-fit,
and best-fit are commonly employed, especially for handling large instances of
the bin packing problem.

This project will serve as an exploration of the trade-offs among different
solution strategies, including brute-force, offline, and online approaches,
shedding light on their respective strengths and weaknesses.

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


```
Total items: 7
Policy              | Total Bins Used
--------------------|-----------------
Optimal Solution    | 4
Online - First Fit  | 4
Online - Next Fit   | 5
Online - Best Fit   | 4
Offline - First Fit | 4
Offline - Best Fit  | 4

Optimal:
Bin 0: 0.71, 0.28
Bin 1: 0.50, 0.41
Bin 2: 0.79, 0.21
Bin 3: 0.90

Online - First Fit:
Bin 0: 0.71, 0.28
Bin 1: 0.50, 0.41
Bin 2: 0.79, 0.21
Bin 3: 0.90

Online - Next Fit:
Bin 0: 0.71
Bin 1: 0.50, 0.28
Bin 2: 0.79
Bin 3: 0.41, 0.21
Bin 4: 0.90

Online - Best Fit:
Bin 0: 0.71, 0.28
Bin 1: 0.50, 0.41
Bin 2: 0.79, 0.21
Bin 3: 0.90

Offline - First Fit:
Bin 0: 0.90
Bin 1: 0.79, 0.21
Bin 2: 0.71, 0.28
Bin 3: 0.50, 0.41

Offline - Best Fit:
Bin 0: 0.90
Bin 1: 0.79, 0.21
Bin 2: 0.71, 0.28
Bin 3: 0.50, 0.41
```

### Baseline Algorithm

The brute-force approach for the bin packing problem aims to generate all
possible permutations of item placements within the bins. For each permutation,
it calculates the number of bins used. The solution that uses the least number
of bins is considered the optimal placement.

The number of permutations for ``n`` items will be ``n!``. With each
permutation, pack them one by one into bins, start a new bin when last bin is
full. Use the number of bins to select the best result.

### Documentation
Make a ``user manual`` to instruct user to use your program. Include
instruction on how to compile the program, how to make input file, how to run
the program and how to understand the output.

Make a document containing the UML class diagram for this project. You can draw
using free software or online services like draw.io, plantUML or Dia. To
simplify your work, no need to include relationships (arrows) for the diagrams.
Just list classes. Here is a good [Tutorial](https://www.visual-paradigm.com/guide/uml-unified-modeling-language/uml-class-diagram-tutorial/).

## Requirements

- **Functionality Required**:
  * Implementation of the bin packing problem.
  * Implement both online and offline versions of the approximation algorithms.
  * Include the brute-force algorithm as the baseline.

- **Main driver for input/output**:
  * Read from a file named ``items.txt`` for item sizes.
  * Display for the results, showcasing the number of bins used by each
    algorithm and the specific bin content.

- **Documentation**:
  * A User's manual describing how to set up and run the program. Make it a
    file named ``manual.pdf``.
  * UML diagrams reflecting the final layout of the program. Put the diagrams
    in a file named ``uml.pdf``.
  * You can use other formats including ``.txt``, ``.md``, ``.docx``, and
    ``.rtf``.

- **Modular Design**:
  * The program should be designed in a modular fashion, separating
    functionalities like various algorithm implementations, result
    display, etc., into distinct classes or functions.

- **Makefile**:
  * Include a makefile to ensure easy compilation and execution of the project.
    This makefile should be designed to work in a Linux environment (SSH
    server, WSL, CodeSpaces, etc.). It should allow the ``make`` command to
    compile an executable called ``main`` to run the main logic and reproduce
    the sample run.

- **Pass provided tests**
  * ``make -f test.mk make-main`` will test if your ``make`` command run will
    compile a ``main`` executable.
  * ``make -f test.mk test-run`` will test if your ``./main`` will run without
    errors.
  * ``make -f test.mk check-outputs`` will test if your ``./main`` run will
    generate correct outputs. There four sub-cases tested under that. You can
    read the [test.mk](test.mk) file to see what are they if you want to test outputs
    partially.

- **Use provided files**
  * **Never modify any of the provided files!** The only exception is when a
    starting framework is provided for you finish. You will always see explicit
    instruction if modification of any file is required!

## Implementation Hints
- **Order of implementation**

  * Online algorithms should be implemented before offline as offline algorithm
    only need to pre-sort the array and the rest of the code should be the
    same as its online counterparts.
  * Brute force is like make a permutation and then apply the online next fit.

- **Use the tests on partially finished work**

  The provided ``test.mk`` allows tests of partially finished ``main``. You may
  finish only part of the ``main.cpp`` and run the tests that test that portion
  of the output. This is also the way to get partial credit on autograding if
  you cannot finish everything before the due date.

- **Passing the item sizes as parameters**

  This can be a tricky step. We normally pass vectors by const reference type
  like ``const vector<double> & theData`` or ``vector<double> &theData`` to
  reduce object duplication overhead. For the offline algorithm, because you
  need to sort the vector before using it. Make sure that you will only sort a
  copy of the original data so the original data will not be destroyed.

## Grade Breakdown
+ [10 pts] Compilable through make commands (autograding)

  + ``make`` or ``make main`` can compile your main executable.

+ [60 pts] Functionality (autograding)

  * [10 pts] ``./main`` runs without error.
  * [10 pts] ``./main`` can correctly load from the file and display the number
    of sizes it loads.
  * [10 pts] ``./main`` can correctly display results for the optimal solution
    run (brute force).
  * [15 pts] ``./main`` can correctly display results for the online run.
  * [15 pts] ``./main`` can correctly display results for the off run.

+ [20 pts] Documentations.

  * [10 pts] User manual
  * [10 pts] UML diagrams

+ [5 pts] Correct submission: no missing or redundant files
+ [5 pts] Code quality: good modular design, clean code, good documentations

## Instruction for TA
+ Autograding [70 pts]

  You can test manually with ``make -f test.mk make-main``, ``make -f test.mk
  test-run`` and ``make -f test.mk check-outputs`` as needed.

+ Read the code briefly on GitHub to see whether the results are from the
  algorithm run or hard-coded. The latter will be considered cheating and the
  project will get a zero grade.
+ Read user manual and UML diagram documents. Should be readable and align to
  the code.
+ Check missing or redundant files in the submission. Also check for
  undesirable modifications of provided files.
+ Read briefly for extremely ugly code. Be forgiving on small problems.
