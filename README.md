# Push Swap

## Project Overview

`Push Swap` is a 42 School project that challenges you to sort a stack of randomly generated unique numbers using a limited set of operations and two stacks: `Stack A` and `Stack B`. The goal is to sort all numbers in `Stack A` in ascending order, with `Stack B` ending up empty, all while minimizing the total number of operations performed.

The allowed operations are:
* `sa`: swap a - swap the first two elements of stack A.
* `sb`: swap b - swap the first two elements of stack B.
* `ss`: sa and sb at the same time.
* `pa`: push a - take the first element from B and put it on top of A.
* `pb`: push b - take the first element from A and put it on top of B.
* `ra`: rotate a - shift all elements of stack A up by one. The first element becomes the last.
* `rb`: rotate b - shift all elements of stack B up by one. The first element becomes the last.
* `rr`: ra and rb at the same time.
* `rra`: reverse rotate a - shift all elements of stack A down by one. The last element becomes the first.
* `rrb`: reverse rotate b - shift all elements of stack B down by one. The last element becomes the first.
* `rrr`: rra and rrb at the same time.

## Algorithm Description

This project implements an optimized sorting algorithm designed to efficiently handle a varying number of elements (from 3 to 500+). The core strategy combines **value-based chunking**, **cost-efficient element selection**, and **ordered insertion** into the auxiliary stack.

### 1. Pre-processing and Chunking

Before sorting, the algorithm performs a crucial pre-processing step:
* The initial numbers are internally **sorted into a temporary array**. This array serves as a reference to determine the final sorted `index` (or `rank`) of each number.
* The numbers are then logically divided into **"chunks" based on their value ranges** (derived from their positions in the sorted reference array). The `chunk_size` is dynamically determined based on the total number of elements (`N`). I chose `sqrt(array_size) * 2` based on my experiments. This breaks down the large sorting problem into smaller, manageable sub-problems.

### 2. Moving Numbers from Stack A to Stack B (Chunk by Chunk)

The main sorting process involves iterating through these pre-defined chunks:

* **Targeting a Chunk:** For each chunk (e.g., numbers 0-19, then 20-39, etc.), the algorithm aims to move all numbers belonging to that chunk from `Stack A` to `Stack B`.
* **Cost-Efficient Element Selection:** For the current chunk, the algorithm scans `Stack A` from both its **top** (`ra` operations) and **bottom** (`rra` operations) to identify which number within the target chunk can be brought to the top of `Stack A` with the **minimum number of rotations**. This ensures efficient access to the numbers we want to push.
* **Ordered Insertion into Stack B:** Once the selected number from the current chunk is at the top of `Stack A`, it is pushed to `Stack B` (`pb`). Crucially, `Stack B` is not just a random dumping ground. Before pushing, the algorithm ensures the number is inserted into `Stack B` while maintaining a **descending order** (largest element at the top, smallest at the bottom).
    * If the number from `Stack A` is the largest or smallest among existing numbers in `Stack B`, it is pushed directly to the top of `Stack B`.
    * Otherwise, `Stack B` is rotated (`rb` or `rrb`) to bring the "closest but smaller" number to its top, creating the correct "slot" for the incoming number to maintain the descending order.
* This process (scanning A, pushing to B with ordered insertion) repeats until all numbers from the current chunk are moved to `Stack B`.
* The algorithm then proceeds to the next chunk until `Stack A` has only 3 elements (which I used a more efficient `sort_three` function to sort)

### 3. Moving Numbers from Stack B to Stack A (Final Sort)

Once `Stack A` is sorted and all numbers are in `Stack B` (which is now in descending order due to the ordered insertion strategy):

* Before pushing all elements from `Stack B` to `Stack A` I perform one final pass through `Stack B` so that everything is in descending order
* The algorithm then repeatedly pushes the top element of `Stack B` to `Stack A` (`pa`). Since `Stack B` is in descending order, this effectively moves the largest remaining number to `Stack A` first, then the next largest, and so on.
* This results in `Stack A` being sorted in **ascending order** when `Stack B` becomes empty.

### 4. Operation Optimization

To further minimize the total operation count, a **post-processing step** is applied to the generated sequence of operations:
* Consecutive `ra` and `rb` operations (e.g., `ra\nrb`) are combined into a single `rr` operation.
* Similarly, consecutive `rra` and `rrb` operations are combined into a single `rrr` operation.
* This pass runs over the entire list of generated moves to ensure maximum efficiency.

This comprehensive algorithm provides an effective and performant solution for the Push Swap problem, balancing computational complexity with operation count minimization.

## How to Build

To compile the project, navigate to the root directory and run `make`:

```bash
make
```
