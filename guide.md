# Microsoft SDE Intern OA & Technical Interview --- 530-Question Master DSA Roadmap (2026 Edition)

**Target:** Microsoft Software Engineering Internship / SDE Intern OA + Technical Interviews  
**Edition:** 2026  
**Language Focus:** C++  
**Goal:** Build comprehensive master coverage of the DSA patterns most likely to appear in Microsoft Online Assessments (OA) and technical interviews, categorized by topic and sorted strictly by priority.

---

## Why this list is Microsoft-focused

Microsoft's official student-interview guidance highlights base knowledge, critical thinking, problem solving, and learning ability. Technical interviews and OAs evaluate core competencies through problem solving across key DSA patterns.

Recent candidate reports (2025–2026) emphasize:
1. **String Manipulation & Parsing:** Lexicographical sorting, character frequency, anagram grouping, and sliding window string matching.
2. **Matrix & Grid Traversal:** 2D matrix rotation, spiral traversal, flood fill, BFS island counting, and multi-source BFS.
3. **Graph Connectivity & Shortest Paths:** Course Schedule (Topological Sort), Connected Components (Union Find / DSU), Dijkstra's algorithm, and Network Delay Time.
4. **Data Structure Design:** LRU Cache, LFU Cache, Min Stack, Search Suggestions System (Trie), and Circular Queues.
5. **Trees & Lowest Common Ancestor (LCA):** Tree traversals, LCA in BST/Binary Trees, tree construction, and path sum problems.
6. **Dynamic Programming Variants:** 1D linear DP (House Robber, Staircase), Grid DP (Unique Paths, Min Path Sum), Subsequence DP (LIS, LCS), String DP (Edit Distance), and Knapsack patterns.

**Important:** This master list serves as a rigorous practice roadmap to build automatic pattern recognition for Microsoft OAs and technical interview rounds.

---

## Overview of Subtopics & Key Algorithms / Concepts

Here is the master blueprint of all 14 subtopics along with their individual core algorithms, techniques, and data structure concepts:

### 01. Arrays, Hashing & Prefix Sum
- **Kadane's Algorithm:** Maximum subarray sum in $O(N)$ time.
- **Boyer-Moore Majority Vote Algorithm:** Finding majority elements ($> N/2$, $> N/3$) in $O(N)$ time and $O(1)$ space.
- **Dutch National Flag Algorithm:** 3-way partitioning for sorting 0s, 1s, and 2s in one pass.
- **Prefix Sum & Difference Arrays:** Range sum queries, subarray sum matching, and 2D submatrix sum calculations.
- **Hash Maps & Sets:** Frequency counting, fast $O(1)$ lookups, and pair/triplet grouping.
- **Matrix Operations:** 2D grid traversal, 90-degree in-place rotation, spiral matrix traversal, and row/column zeroing.
- **Interval Processing:** Interval merging, insertion, overlap checking, and meeting room scheduling.
- **Cyclic Sort:** Finding missing, duplicate, or first positive numbers in $O(N)$ time with $O(1)$ auxiliary space.

### 02. Two Pointers, Sliding Window & Strings
- **Two Pointers (Opposite Direction):** Two Sum in sorted array, palindrome verification, container with most water.
- **Two Pointers (Same Direction / Fast & Slow):** Array deduplication, moving zeroes, subsegment compaction.
- **Sliding Window (Fixed Size):** Tracking maximum/minimum elements or vowel counts in subsegments of length $K$.
- **Sliding Window (Dynamic / Shrinkable):** Minimum window substring, longest substring without repeating characters, fruit basket packing.
- **Sliding Window (Non-Shrinkable):** Maintaining maximum window size efficiently across iterations.
- **String Parsing & Transformations:** String tokenization, word reversal, anagram frequency matching, and string compression.
- **Palindrome Expansion:** Expanding around single/double centers to find longest palindromic subsegments.
- **Pattern Matching Concepts:** KMP (Knuth-Morris-Pratt) prefix function and Rabin-Karp rolling hash algorithms.

### 03. Binary Search & Search on Answer
- **Standard Binary Search:** Iterative and recursive searching in sorted sequences.
- **Lower Bound & Upper Bound:** Locating first and last occurrences of target elements.
- **Rotated & Shifted Array Search:** Finding elements and minimums in single and duplicate rotated sorted arrays.
- **2D Matrix Binary Search:** Search in row-wise and column-wise sorted 2D matrices.
- **Binary Search on Answer Space:** Applying monotonic predicate functions `check(x)` to solve continuous allocation, shipping capacity, and eating rate problems (e.g., Koko Eating Bananas).
- **Peak Finding:** Binary search on non-sorted sequences via slope detection (Peak Element, Mountain Array).
- **Partition & Median Search:** Binary search over dual partitions (Median of Two Sorted Arrays).

### 04. Linked Lists
- **Floyd's Fast & Slow Pointer Technique:** Cycle detection (Tortoise and Hare), cycle entrance discovery, and middle node retrieval.
- **In-place Linked List Reversal:** Iterative and recursive reversal of full lists and subsegments ($K$-group reversal).
- **Dummy Node Technique:** Eliminating boundary edge-case checks for head/tail mutations.
- **Linked List Merging & Sorting:** Merge sort on linked lists, merging $K$ sorted lists via Min-Heap or Divide & Conquer.
- **Interleaving & Reordering:** Zipping, unzipping, and alternating odd-even nodes.
- **Deep Copy with Random Pointers:** Hash map mapping vs. in-place interleave-and-split pointer duplication.

### 05. Stack, Queue, Monotonic Stack & Design
- **Parentheses & Bracket Matching:** String validation, nested structure parsing, and decode string operations.
- **Expression Parsing:** Infix to Postfix/Prefix conversion and Reverse Polish Notation (RPN) calculator evaluation.
- **Monotonic Stack:** Next/Previous Greater/Smaller Element detection in $O(N)$ time for stock spans and temperatures.
- **Monotonic Stack Applications:** Largest rectangle in histogram, maximal rectangle in 2D grid, and trapping rain water.
- **Monotonic Queue:** Double-ended queue for tracking maximums/minimums in sliding windows.
- **Data Structure Design (System Design-Lite):** Min Stack, Max Stack, Circular Queue, Circular Deque, LRU Cache (Hash Map + Doubly Linked List), and LFU Cache.

### 06. Trees & Binary Search Trees (BST)
- **DFS Traversals:** Pre-order, In-order, Post-order traversals (both recursive and stack-based iterative).
- **BFS Level Order Traversal:** Standard level order, zigzag/snake traversal, right/left side views, and max width computation.
- **Tree Structural Properties:** Depth, height, balance check (AVL height property), and tree diameter calculation.
- **Path Problems:** Root-to-leaf paths, path sum verification, path sum count, and binary tree max path sum.
- **Lowest Common Ancestor (LCA):** LCA in BST (using search property) and LCA in general Binary Trees.
- **BST Core Operations:** BST search, insertion, deletion, validation, in-order successor/predecessor, and K-th smallest element.
- **Tree Reconstruction:** Building binary trees from Preorder+Inorder or Inorder+Postorder traversal arrays.
- **Tree Flattening & Serialization:** Flattening trees to linked lists, tree serialization and deserialization routines.

### 07. Graphs, BFS, DFS, Shortest Path & Union Find (DSU)
- **Grid Traversal:** 2D Flood fill, island counting, max area of island, surrounded regions, and Pacific-Atlantic flow.
- **Multi-Source BFS:** Simultaneous expansion in grids (Rotting Oranges, Distance to nearest 0 matrix).
- **Topological Sort:** Kahn's Algorithm (indegree array + queue) and DFS stack algorithm for dependency ordering (Course Schedule).
- **Cycle Detection:** Directed graph cycle detection (Recursion stack / Color marking) and Undirected graph cycle detection (DFS/BFS/DSU).
- **Disjoint Set Union (DSU):** Path compression and rank/size union optimizations for dynamic connectivity and component counting.
- **Shortest Path (Unweighted):** BFS traversal for minimum step path discovery in unweighted graphs and word ladders.
- **Shortest Path (Weighted Non-Negative):** Dijkstra's algorithm using C++ `std::priority_queue`.
- **Shortest Path (Negative Weights / Constraints):** Bellman-Ford algorithm and Shortest Path Faster Algorithm (SPFA).
- **All-Pairs Shortest Path:** Floyd-Warshall DP algorithm.
- **Minimum Spanning Tree (MST):** Kruskal's algorithm (Greedy + DSU) and Prim's algorithm (Greedy + Min-Heap).
- **Bipartite Graphs:** 2-colorability check via BFS/DFS graph traversal.

### 08. Dynamic Programming
- **1D Linear DP:** Fibonacci sequences, Climbing Stairs, Min Cost Stairs, House Robber I & II, Decode Ways, Delete and Earn.
- **Grid DP:** Unique Paths I & II, Minimum Path Sum, Triangle, Minimum Falling Path Sum, Maximal Square.
- **0/1 Knapsack Pattern:** Subset Sum, Target Sum, Partition Equal Subset Sum, Last Stone Weight II, Ones and Zeroes.
- **Unbounded Knapsack Pattern:** Coin Change I (Min coins), Coin Change II (Total ways), Rod Cutting, Combination Sum IV.
- **Subsequence DP:** Longest Increasing Subsequence (LIS) in $O(N \log N)$ via Binary Search, Longest Common Subsequence (LCS).
- **String DP:** Edit Distance, Distinct Subsequences, Delete Operation for Two Strings, Interleaving String.
- **Palindromic DP:** Longest Palindromic Substring, Longest Palindromic Subsequence, Palindromic Partitioning Cuts.
- **State Machine / Stock DP:** Buy and Sell Stock with Cooldown, Transaction Fees, K Transactions.
- **Interval DP:** Matrix Chain MCM, Burst Balloons, Minimum Cost Tree From Leaf Values.
- **Bitmask DP:** Subset state representation for small $N \le 20$ (Shortest Path Visiting All Nodes, Traveling Salesperson).

### 09. Greedy Algorithms, Heap & Priority Queue
- **Greedy Choice Property:** Local optimal decision making with mathematical proofs of global optimality.
- **Interval Scheduling:** Activity Selection, N Meetings in One Room, Non-overlapping Intervals, Minimum Platforms.
- **Task & Event Scheduling:** Task Scheduler with cooldown, Reorganize String without adjacent duplicates.
- **Heap Operations & Custom Comparators:** Building min-heaps, max-heaps, and custom lambda comparators in C++ `std::priority_queue`.
- **Top-K Pattern:** Kth Largest/Smallest element, Top K Frequent Words, K Closest Points to Origin.
- **Two-Heap Pattern:** Dual heap architecture (Max-Heap + Min-Heap) for real-time median tracking in data streams.
- **K-Way Merge:** Merging $K$ sorted lists or sorted arrays using priority queues.

### 10. Backtracking & Recursion
- **Subsets & Power Set:** Decision tree branching (Include / Exclude choices) with unique and duplicate handling.
- **Permutations Generation:** Generating all distinct ordering permutations of array/string elements.
- **Combination Sum Patterns:** Candidate combination search with element reuse and frequency bounds.
- **Grid Backtracking:** Word Search in 2D matrix, maze navigation, and path exploration with visited cell backtracking.
- **Constraint Satisfaction:** N-Queens placement, Sudoku Solver, Matchsticks to Square.
- **String Partitioning:** Palindrome Partitioning, Restore IP Addresses.
- **Pruning Techniques:** Branch-and-bound optimization, sorting before recursion to prune early.

### 11. Trie, Segment Tree & Advanced Data Structures
- **Trie (Prefix Tree):** TrieNode construction, string insertion, full word search, prefix search, wildcard matching.
- **Trie Applications:** Search Suggestions System (Autocomplete), Replace Words, Map Sum Pairs.
- **Bitwise Trie:** Binary Trie for Maximum XOR Pair and Range Maximum XOR search.
- **Fenwick Tree (Binary Indexed Tree):** $O(\log N)$ point updates and prefix range sum queries.
- **Segment Tree:** Tree building, range minimum/sum queries, and lazy propagation for range updates.

### 12. Bit Manipulation, Math & Fast Computation
- **Bitwise Operators:** Bitwise AND (`&`), OR (`|`), XOR (`^`), NOT (`~`), Left Shift (`<<`), Right Shift (`>>`).
- **Bit Hacks:** `x & (x - 1)` (clearing lowest set bit), `x & -x` (extracting lowest set bit), XOR cancellation (`a ^ a = 0`).
- **Power of 2 & Bit Counting:** Power of 2 verification, Brian Kernighan's bit counting algorithm, C++ `__builtin_popcount`.
- **Fast Exponentiation:** Binary exponentiation ($O(\log N)$ modular power computation `Pow(x, n)`).
- **Number Theory & Primes:** Sieve of Eratosthenes ($O(N \log \log N)$ prime generation), Prime Factorization, Trailing Zeroes in Factorial.
- **Euclidean Algorithm:** GCD (Greatest Common Divisor) and LCM calculation.
- **Combinatorics & Math:** Pascal's Triangle properties, digital root, fraction conversion.

### 13. Microsoft High-Frequency Real OA & GFG Interview Classics
- **System Design-Lite Coding:** Real-world object/class design (LRU, LFU, Underground System, Parking System, File System).
- **String Parsing & Lexicography:** Alien Dictionary lexicographical verification and string parsing.
- **In-place Grid Transformations:** Matrix rotation, Game of Life state compression.
- **Classic Interview Complements:** GeeksforGeeks high-yield interview problems frequently asked in Microsoft India/Global technical rounds.

### 14. Striver A2Z Classics & Missing Essentials
- **Array & Binary Search Classics:** Sorted & Rotated check, Union of sorted arrays, Missing & Repeating numbers, Count Subarrays with XOR K, Book Allocation, Aggressive Cows, Painter's Partition.
- **Linked List & Stack Classics:** Length of Loop, Add 1 to LL, Flatten 2D LL, Sort 0s-1s-2s LL, The Celebrity Problem, Subarray Minimums & Ranges.
- **Tree & Graph Classics:** Boundary Traversal, Top/Bottom View, Children Sum Property, Burning Tree, Largest BST, Kosaraju's SCC, Articulation Points, Floyd Warshall, Shortest Path Modulo Reach.
- **DP Classics:** Ninja's Training (2D Activity DP), Rod Cutting (Unbounded Knapsack), Boolean Parenthesization (MCM Partition DP).

---

## How to use this list

- **P0 --- Must Solve:** Complete these first. You must be able to code them fluently from scratch without assistance.
- **P1 --- Strongly Recommended:** Solve after P0. Focus on recognizing pattern variations quickly during timed tests.
- **P2 --- Interview Follow-Up:** Essential for harder competitive OA problems and round-2/round-3 interview follow-ups.
- Mark `[x]` only when you can solve a problem **from scratch**, explain time/space complexity, and handle edge cases cleanly.

---

# 01. Arrays, Hashing & Prefix Sum --- 65

-   [ ] 001. LC 1 --- Two Sum --- P0
-   [ ] 002. LC 53 --- Maximum Subarray --- P0
-   [ ] 003. LC 54 --- Spiral Matrix --- P0
-   [ ] 004. LC 56 --- Merge Intervals --- P0
-   [ ] 005. LC 66 --- Plus One --- P0
-   [ ] 006. LC 73 --- Set Matrix Zeroes --- P0
-   [ ] 007. LC 75 --- Sort Colors --- P0
-   [ ] 008. LC 88 --- Merge Sorted Array --- P0
-   [ ] 009. LC 118 --- Pascal's Triangle --- P0
-   [ ] 010. LC 121 --- Best Time to Buy and Sell Stock --- P0
-   [ ] 011. LC 128 --- Longest Consecutive Sequence --- P0
-   [ ] 012. LC 169 --- Majority Element --- P0
-   [ ] 013. LC 189 --- Rotate Array --- P0
-   [ ] 014. LC 209 --- Minimum Size Subarray Sum --- P0
-   [ ] 015. LC 217 --- Contains Duplicate --- P0
-   [ ] 016. LC 238 --- Product of Array Except Self --- P0
-   [ ] 017. LC 242 --- Valid Anagram --- P0
-   [ ] 018. LC 268 --- Missing Number --- P0
-   [ ] 019. LC 347 --- Top K Frequent Elements --- P0
-   [ ] 020. LC 435 --- Non-overlapping Intervals --- P0
-   [ ] 021. LC 49 --- Group Anagrams --- P0
-   [ ] 022. LC 560 --- Subarray Sum Equals K --- P0
-   [ ] 023. LC 15 --- 3Sum --- P0
-   [ ] 024. LC 18 --- 4Sum --- P1
-   [ ] 025. LC 36 --- Valid Sudoku --- P1
-   [ ] 026. LC 41 --- First Missing Positive --- P1
-   [ ] 027. LC 48 --- Rotate Image --- P1
-   [ ] 028. LC 57 --- Insert Interval --- P1
-   [ ] 029. LC 119 --- Pascal's Triangle II --- P1
-   [ ] 030. LC 228 --- Summary Ranges --- P1
-   [ ] 031. LC 229 --- Majority Element II --- P1
-   [ ] 032. LC 253 --- Meeting Rooms II --- P1
-   [ ] 033. LC 271 --- Encode and Decode Strings --- P1
-   [ ] 034. LC 287 --- Find the Duplicate Number --- P1
-   [ ] 035. LC 303 --- Range Sum Query - Immutable --- P1
-   [ ] 036. LC 380 --- Insert Delete GetRandom O(1) --- P1
-   [ ] 037. LC 442 --- Find All Duplicates in an Array --- P1
-   [ ] 038. LC 448 --- Find All Numbers Disappeared in an Array --- P1
-   [ ] 039. LC 452 --- Minimum Number of Arrows to Burst Balloons --- P1
-   [ ] 040. LC 523 --- Continuous Subarray Sum --- P1
-   [ ] 041. LC 525 --- Contiguous Array --- P1
-   [ ] 042. LC 532 --- K-diff Pairs in an Array --- P1
-   [ ] 043. LC 554 --- Brick Wall --- P1
-   [ ] 044. LC 565 --- Array Nesting --- P1
-   [ ] 045. LC 724 --- Find Pivot Index --- P1
-   [ ] 046. LC 974 --- Subarray Sums Divisible by K --- P1
-   [ ] 047. LC 986 --- Interval List Intersections --- P1
-   [ ] 048. LC 930 --- Binary Subarrays With Sum --- P1
-   [ ] 049. LC 1074 --- Number of Submatrices That Sum to Target --- P1
-   [ ] 050. LC 1248 --- Count Number of Nice Subarrays --- P1
-   [ ] 051. LC 1371 --- Find the Longest Substring Containing Vowels in Even Counts --- P1
-   [ ] 052. LC 1423 --- Maximum Points You Can Obtain from Cards --- P1
-   [ ] 053. LC 1497 --- Check If Array Pairs Are Divisible by k --- P1
-   [ ] 054. LC 1590 --- Make Sum Divisible by P --- P1
-   [ ] 055. LC 289 --- Game of Life --- P2
-   [ ] 056. LC 304 --- Range Sum Query 2D - Immutable --- P2
-   [ ] 057. LC 381 --- Insert Delete GetRandom O(1) - Duplicates allowed --- P2
-   [ ] 058. LC 792 --- Number of Matching Subsequences --- P2
-   [ ] 059. LC 1072 --- Flip Columns For Maximum Number of Equal Rows --- P2
-   [ ] 060. LC 1525 --- Number of Good Ways to Split a String --- P2
-   [ ] 061. LC 1726 --- Tuple with Same Product --- P2
-   [ ] 062. LC 1814 --- Count Nice Pairs in an Array --- P2
-   [ ] 063. LC 2007 --- Find Original Array From Doubled Array --- P2
-   [ ] 064. LC 2131 --- Longest Palindrome by Concatenating Two Letter Words --- P2
-   [ ] 065. LC 2245 --- Maximum Trailing Zeros in a Cornered Path --- P2

# 02. Two Pointers, Sliding Window & Strings --- 45

-   [ ] 066. LC 3 --- Longest Substring Without Repeating Characters --- P0
-   [ ] 067. LC 11 --- Container With Most Water --- P0
-   [ ] 068. LC 26 --- Remove Duplicates from Sorted Array --- P0
-   [ ] 069. LC 27 --- Remove Element --- P0
-   [ ] 070. LC 125 --- Valid Palindrome --- P0
-   [ ] 071. LC 151 --- Reverse Words in a String --- P0
-   [ ] 072. LC 167 --- Two Sum II - Input Array Is Sorted --- P0
-   [ ] 073. LC 283 --- Move Zeroes --- P0
-   [ ] 074. LC 344 --- Reverse String --- P0
-   [ ] 075. LC 345 --- Reverse Vowels of a String --- P0
-   [ ] 076. LC 392 --- Is Subsequence --- P0
-   [ ] 077. LC 424 --- Longest Repeating Character Replacement --- P0
-   [ ] 078. LC 438 --- Find All Anagrams in a String --- P0
-   [ ] 079. LC 557 --- Reverse Words in a String III --- P0
-   [ ] 080. LC 567 --- Permutation in String --- P0
-   [ ] 081. LC 904 --- Fruit Into Baskets --- P0
-   [ ] 082. LC 1004 --- Max Consecutive Ones III --- P0
-   [ ] 083. LC 1456 --- Maximum Number of Vowels in a Substring of Given Length --- P0
-   [ ] 084. LC 16 --- 3Sum Closest --- P1
-   [ ] 085. LC 42 --- Trapping Rain Water --- P1
-   [ ] 086. LC 76 --- Minimum Window Substring --- P1
-   [ ] 087. LC 159 --- Longest Substring with At Most Two Distinct Characters --- P1
-   [ ] 088. LC 340 --- Longest Substring with At Most K Distinct Characters --- P1
-   [ ] 089. LC 643 --- Maximum Average Subarray I --- P1
-   [ ] 090. LC 680 --- Valid Palindrome II --- P1
-   [ ] 091. LC 713 --- Subarray Product Less Than K --- P1
-   [ ] 092. LC 992 --- Subarrays with K Different Integers --- P1
-   [ ] 093. LC 1052 --- Grumpy Bookstore Owner --- P1
-   [ ] 094. LC 1208 --- Get Equal Substrings Within Budget --- P1
-   [ ] 095. LC 1358 --- Number of Substrings Containing All Three Characters --- P1
-   [ ] 096. LC 1425 --- Constrained Subsequence Sum --- P1
-   [ ] 097. LC 1438 --- Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit --- P1
-   [ ] 098. LC 1658 --- Minimum Operations to Reduce X to Zero --- P1
-   [ ] 099. LC 1838 --- Frequency of the Most Frequent Element --- P1
-   [ ] 100. LC 1871 --- Jump Game VII --- P1
-   [ ] 101. LC 2024 --- Maximize the Confusion of an Exam --- P1
-   [ ] 102. LC 2302 --- Count Subarrays With Score Less Than K --- P1
-   [ ] 103. LC 30 --- Substring with Concatenation of All Words --- P2
-   [ ] 104. LC 862 --- Shortest Subarray with Sum at Least K --- P2
-   [ ] 105. LC 995 --- Minimum Number of K Consecutive Bit Flips --- P2
-   [ ] 106. LC 1151 --- Minimum Swaps to Group All 1's Together --- P2
-   [ ] 107. LC 1610 --- Maximum Number of Visible Points --- P2
-   [ ] 108. LC 1775 --- Equal Sum Arrays With Minimum Number of Operations --- P2
-   [ ] 109. LC 2090 --- K Radius Subarray Averages --- P2
-   [ ] 110. LC 2444 --- Count Subarrays With Fixed Bounds --- P2

# 03. Binary Search & Search on Answer --- 35

-   [ ] 111. LC 33 --- Search in Rotated Sorted Array --- P0
-   [ ] 112. LC 34 --- Find First and Last Position of Element in Sorted Array --- P0
-   [ ] 113. LC 35 --- Search Insert Position --- P0
-   [ ] 114. LC 74 --- Search a 2D Matrix --- P0
-   [ ] 115. LC 153 --- Find Minimum in Rotated Sorted Array --- P0
-   [ ] 116. LC 162 --- Find Peak Element --- P0
-   [ ] 117. LC 240 --- Search a 2D Matrix II --- P0
-   [ ] 118. LC 278 --- First Bad Version --- P0
-   [ ] 119. LC 374 --- Guess Number Higher or Lower --- P0
-   [ ] 120. LC 704 --- Binary Search --- P0
-   [ ] 121. LC 875 --- Koko Eating Bananas --- P0
-   [ ] 122. LC 1011 --- Capacity To Ship Packages Within D Days --- P0
-   [ ] 123. LC 69 --- Sqrt(x) --- P1
-   [ ] 124. LC 81 --- Search in Rotated Sorted Array II --- P1
-   [ ] 125. LC 154 --- Find Minimum in Rotated Sorted Array II --- P1
-   [ ] 126. LC 367 --- Valid Perfect Square --- P1
-   [ ] 127. LC 378 --- Kth Smallest Element in a Sorted Matrix --- P1
-   [ ] 128. LC 410 --- Split Array Largest Sum --- P1
-   [ ] 129. LC 540 --- Single Element in a Sorted Array --- P1
-   [ ] 130. LC 658 --- Find K Closest Elements --- P1
-   [ ] 131. LC 852 --- Peak Index in a Mountain Array --- P1
-   [ ] 132. LC 1283 --- Find the Smallest Divisor Given a Threshold --- P1
-   [ ] 133. LC 1482 --- Minimum Number of Days to Make m Bouquets --- P1
-   [ ] 134. LC 1552 --- Magnetic Force Between Two Balls --- P1
-   [ ] 135. LC 1870 --- Minimum Speed to Arrive on Time --- P1
-   [ ] 136. LC 2064 --- Minimized Maximum of Products Distributed to Any Store --- P1
-   [ ] 137. LC 2226 --- Maximum Candies Allocated to K Children --- P1
-   [ ] 138. LC 4 --- Median of Two Sorted Arrays --- P2
-   [ ] 139. LC 668 --- Kth Smallest Number in Multiplication Table --- P2
-   [ ] 140. LC 719 --- Find K-th Smallest Pair Distance --- P2
-   [ ] 141. LC 774 --- Minimize Max Distance to Gas Station --- P2
-   [ ] 142. LC 786 --- K-th Smallest Prime Fraction --- P2
-   [ ] 143. LC 1901 --- Find a Peak Element II --- P2
-   [ ] 144. LC 2040 --- Kth Smallest Product of Two Sorted Arrays --- P2
-   [ ] 145. LC 2251 --- Number of Flowers in Full Bloom --- P2

# 04. Linked Lists --- 30

-   [ ] 146. LC 2 --- Add Two Numbers --- P0
-   [ ] 147. LC 19 --- Remove Nth Node From End of List --- P0
-   [ ] 148. LC 21 --- Merge Two Sorted Lists --- P0
-   [ ] 149. LC 83 --- Remove Duplicates from Sorted List --- P0
-   [ ] 150. LC 141 --- Linked List Cycle --- P0
-   [ ] 151. LC 160 --- Intersection of Two Linked Lists --- P0
-   [ ] 152. LC 203 --- Remove Linked List Elements --- P0
-   [ ] 153. LC 206 --- Reverse Linked List --- P0
-   [ ] 154. LC 234 --- Palindrome Linked List --- P0
-   [ ] 155. LC 328 --- Odd Even Linked List --- P0
-   [ ] 156. LC 876 --- Middle of the Linked List --- P0
-   [ ] 157. LC 23 --- Merge k Sorted Lists --- P1
-   [ ] 158. LC 24 --- Swap Nodes in Pairs --- P1
-   [ ] 159. LC 61 --- Rotate List --- P1
-   [ ] 160. LC 82 --- Remove Duplicates from Sorted List II --- P1
-   [ ] 161. LC 86 --- Partition List --- P1
-   [ ] 162. LC 92 --- Reverse Linked List II --- P1
-   [ ] 163. LC 138 --- Copy List with Random Pointer --- P1
-   [ ] 164. LC 142 --- Linked List Cycle II --- P1
-   [ ] 165. LC 143 --- Reorder List --- P1
-   [ ] 166. LC 148 --- Sort List --- P1
-   [ ] 167. LC 445 --- Add Two Numbers II --- P1
-   [ ] 168. LC 725 --- Split Linked List in Parts --- P1
-   [ ] 169. LC 1019 --- Next Greater Node In Linked List --- P1
-   [ ] 170. LC 1669 --- Merge In Between Linked Lists --- P1
-   [ ] 171. LC 2095 --- Delete the Middle Node of a Linked List --- P1
-   [ ] 172. LC 2181 --- Merge Nodes in Between Zeros --- P1
-   [ ] 173. LC 25 --- Reverse Nodes in k-Group --- P2
-   [ ] 174. LC 430 --- Flatten a Multilevel Doubly Linked List --- P2
-   [ ] 175. LC 1171 --- Remove Zero Sum Consecutive Nodes from Linked List --- P2

# 05. Stack, Queue, Monotonic Stack & Design --- 35

-   [ ] 176. LC 20 --- Valid Parentheses --- P0
-   [ ] 177. LC 150 --- Evaluate Reverse Polish Notation --- P0
-   [ ] 178. LC 155 --- Min Stack --- P0
-   [ ] 179. LC 239 --- Sliding Window Maximum --- P0
-   [ ] 180. LC 394 --- Decode String --- P0
-   [ ] 181. LC 496 --- Next Greater Element I --- P0
-   [ ] 182. LC 739 --- Daily Temperatures --- P0
-   [ ] 183. LC 1047 --- Remove All Adjacent Duplicates In String --- P0
-   [ ] 184. LC 1544 --- Make The String Great --- P0
-   [ ] 185. LC 71 --- Simplify Path --- P1
-   [ ] 186. LC 84 --- Largest Rectangle in Histogram --- P1
-   [ ] 187. LC 146 --- LRU Cache --- P1
-   [ ] 188. LC 225 --- Implement Stack using Queues --- P1
-   [ ] 189. LC 227 --- Basic Calculator II --- P1
-   [ ] 190. LC 232 --- Implement Queue using Stacks --- P1
-   [ ] 191. LC 402 --- Remove K Digits --- P1
-   [ ] 192. LC 460 --- LFU Cache --- P1
-   [ ] 193. LC 503 --- Next Greater Element II --- P1
-   [ ] 194. LC 622 --- Design Circular Queue --- P1
-   [ ] 195. LC 641 --- Design Circular Deque --- P1
-   [ ] 196. LC 735 --- Asteroid Collision --- P1
-   [ ] 197. LC 853 --- Car Fleet --- P1
-   [ ] 198. LC 901 --- Online Stock Span --- P1
-   [ ] 199. LC 907 --- Sum of Subarray Minimums --- P1
-   [ ] 200. LC 946 --- Validate Stack Sequences --- P1
-   [ ] 201. LC 1209 --- Remove All Adjacent Duplicates in String II --- P1
-   [ ] 202. LC 1762 --- Buildings With an Ocean View --- P1
-   [ ] 203. LC 2104 --- Sum of Subarray Ranges --- P1
-   [ ] 204. LC 85 --- Maximal Rectangle --- P2
-   [ ] 205. LC 224 --- Basic Calculator --- P2
-   [ ] 206. LC 316 --- Remove Duplicate Letters --- P2
-   [ ] 207. LC 772 --- Basic Calculator III --- P2
-   [ ] 208. LC 895 --- Maximum Frequency Stack --- P2
-   [ ] 209. LC 2289 --- Steps to Make Array Non-decreasing --- P2
-   [ ] 210. LC 2454 --- Next Greater Element IV --- P2

# 06. Trees & BST --- 45

-   [ ] 211. LC 98 --- Validate Binary Search Tree --- P0
-   [ ] 212. LC 100 --- Same Tree --- P0
-   [ ] 213. LC 101 --- Symmetric Tree --- P0
-   [ ] 214. LC 102 --- Binary Tree Level Order Traversal --- P0
-   [ ] 215. LC 104 --- Maximum Depth of Binary Tree --- P0
-   [ ] 216. LC 110 --- Balanced Binary Tree --- P0
-   [ ] 217. LC 111 --- Minimum Depth of Binary Tree --- P0
-   [ ] 218. LC 112 --- Path Sum --- P0
-   [ ] 219. LC 199 --- Binary Tree Right Side View --- P0
-   [ ] 220. LC 226 --- Invert Binary Tree --- P0
-   [ ] 221. LC 230 --- Kth Smallest Element in a BST --- P0
-   [ ] 222. LC 235 --- Lowest Common Ancestor of a Binary Search Tree --- P0
-   [ ] 223. LC 236 --- Lowest Common Ancestor of a Binary Tree --- P0
-   [ ] 224. LC 257 --- Binary Tree Paths --- P0
-   [ ] 225. LC 543 --- Diameter of Binary Tree --- P0
-   [ ] 226. LC 617 --- Merge Two Binary Trees --- P0
-   [ ] 227. LC 700 --- Search in a Binary Search Tree --- P0
-   [ ] 228. LC 103 --- Binary Tree Zigzag Level Order Traversal --- P1
-   [ ] 229. LC 105 --- Construct Binary Tree from Preorder and Inorder Traversal --- P1
-   [ ] 230. LC 106 --- Construct Binary Tree from Inorder and Postorder Traversal --- P1
-   [ ] 231. LC 113 --- Path Sum II --- P1
-   [ ] 232. LC 114 --- Flatten Binary Tree to Linked List --- P1
-   [ ] 233. LC 116 --- Populating Next Right Pointers in Each Node --- P1
-   [ ] 234. LC 117 --- Populating Next Right Pointers in Each Node II --- P1
-   [ ] 235. LC 124 --- Binary Tree Maximum Path Sum --- P1
-   [ ] 236. LC 173 --- Binary Search Tree Iterator --- P1
-   [ ] 237. LC 426 --- Convert Binary Search Tree to Sorted Doubly Linked List --- P1
-   [ ] 238. LC 437 --- Path Sum III --- P1
-   [ ] 239. LC 450 --- Delete Node in a BST --- P1
-   [ ] 240. LC 508 --- Most Frequent Subtree Sum --- P1
-   [ ] 241. LC 513 --- Find Bottom Left Tree Value --- P1
-   [ ] 242. LC 515 --- Find Largest Value in Each Tree Row --- P1
-   [ ] 243. LC 572 --- Subtree of Another Tree --- P1
-   [ ] 244. LC 654 --- Maximum Binary Tree --- P1
-   [ ] 245. LC 701 --- Insert into a Binary Search Tree --- P1
-   [ ] 246. LC 863 --- All Nodes Distance K in Binary Tree --- P1
-   [ ] 247. LC 987 --- Vertical Order Traversal of a Binary Tree --- P1
-   [ ] 248. LC 1372 --- Longest ZigZag Path in a Binary Tree --- P1
-   [ ] 249. LC 99 --- Recover Binary Search Tree --- P2
-   [ ] 250. LC 297 --- Serialize and Deserialize Binary Tree --- P2
-   [ ] 251. LC 337 --- House Robber III --- P2
-   [ ] 252. LC 662 --- Maximum Width of Binary Tree --- P2
-   [ ] 253. LC 958 --- Check Completeness of a Binary Tree --- P2
-   [ ] 254. LC 968 --- Binary Tree Cameras --- P2
-   [ ] 255. LC 1110 --- Delete Nodes And Return Forest --- P2

# 07. Graphs, BFS, DFS, Shortest Path & Union Find --- 55

-   [ ] 256. LC 200 --- Number of Islands --- P0
-   [ ] 257. LC 207 --- Course Schedule --- P0
-   [ ] 258. LC 210 --- Course Schedule II --- P0
-   [ ] 259. LC 261 --- Graph Valid Tree --- P0
-   [ ] 260. LC 323 --- Number of Connected Components in an Undirected Graph --- P0
-   [ ] 261. LC 399 --- Evaluate Division --- P0
-   [ ] 262. LC 463 --- Island Perimeter --- P0
-   [ ] 263. LC 542 --- 01 Matrix --- P0
-   [ ] 264. LC 547 --- Number of Provinces --- P0
-   [ ] 265. LC 684 --- Redundant Connection --- P0
-   [ ] 266. LC 695 --- Max Area of Island --- P0
-   [ ] 267. LC 733 --- Flood Fill --- P0
-   [ ] 268. LC 752 --- Open the Lock --- P0
-   [ ] 269. LC 785 --- Is Graph Bipartite? --- P0
-   [ ] 270. LC 797 --- All Paths From Source to Target --- P0
-   [ ] 271. LC 994 --- Rotting Oranges --- P0
-   [ ] 272. LC 1091 --- Shortest Path in Binary Matrix --- P0
-   [ ] 273. LC 1631 --- Path With Minimum Effort --- P0
-   [ ] 274. LC 127 --- Word Ladder --- P1
-   [ ] 275. LC 130 --- Surrounded Regions --- P1
-   [ ] 276. LC 133 --- Clone Graph --- P1
-   [ ] 277. LC 269 --- Alien Dictionary --- P1
-   [ ] 278. LC 310 --- Minimum Height Trees --- P1
-   [ ] 279. LC 332 --- Reconstruct Itinerary --- P1
-   [ ] 280. LC 365 --- Water and Jug Problem --- P1
-   [ ] 281. LC 417 --- Pacific Atlantic Water Flow --- P1
-   [ ] 282. LC 433 --- Minimum Genetic Mutation --- P1
-   [ ] 283. LC 721 --- Accounts Merge --- P1
-   [ ] 284. LC 743 --- Network Delay Time --- P1
-   [ ] 285. LC 787 --- Cheapest Flights Within K Stops --- P1
-   [ ] 286. LC 802 --- Find Eventual Safe States --- P1
-   [ ] 287. LC 815 --- Bus Routes --- P1
-   [ ] 288. LC 841 --- Keys and Rooms --- P1
-   [ ] 289. LC 886 --- Possible Bipartition --- P1
-   [ ] 290. LC 934 --- Shortest Bridge --- P1
-   [ ] 291. LC 947 --- Most Stones Removed with Same Row or Column --- P1
-   [ ] 292. LC 990 --- Satisfiability of Equality Equations --- P1
-   [ ] 293. LC 1162 --- As Far from Land as Possible --- P1
-   [ ] 294. LC 1319 --- Number of Operations to Make Network Connected --- P1
-   [ ] 295. LC 1334 --- Find the City With the Smallest Number of Neighbors at a Threshold Distance --- P1
-   [ ] 296. LC 1368 --- Minimum Cost to Make at Least One Valid Path in a Grid --- P1
-   [ ] 297. LC 1376 --- Time Needed to Inform All Employees --- P1
-   [ ] 298. LC 1466 --- Reorder Routes to Make All Paths Lead to the City Zero --- P1
-   [ ] 299. LC 1514 --- Path with Maximum Probability --- P1
-   [ ] 300. LC 1584 --- Min Cost to Connect All Points --- P1
-   [ ] 301. LC 1926 --- Nearest Exit from Entrance in Maze --- P1
-   [ ] 302. LC 2101 --- Detonate the Maximum Bombs --- P1
-   [ ] 303. LC 778 --- Swim in Rising Water --- P2
-   [ ] 304. LC 847 --- Shortest Path Visiting All Nodes --- P2
-   [ ] 305. LC 1192 --- Critical Connections in a Network --- P2
-   [ ] 306. LC 1263 --- Minimum Moves to Move a Box to Their Target Location --- P2
-   [ ] 307. LC 1579 --- Remove Max Number of Edges to Keep Graph Fully Traversable --- P2
-   [ ] 308. LC 2092 --- Find All People With Secret --- P2
-   [ ] 309. LC 2290 --- Minimum Obstacle Removal to Reach Corner --- P2
-   [ ] 310. LC 2608 --- Shortest Cycle in a Graph --- P2

# 08. Dynamic Programming --- 65

-   [ ] 311. LC 5 --- Longest Palindromic Substring --- P0
-   [ ] 312. LC 62 --- Unique Paths --- P0
-   [ ] 313. LC 63 --- Unique Paths II --- P0
-   [ ] 314. LC 64 --- Minimum Path Sum --- P0
-   [ ] 315. LC 70 --- Climbing Stairs --- P0
-   [ ] 316. LC 91 --- Decode Ways --- P0
-   [ ] 317. LC 121 --- Best Time to Buy and Sell Stock --- P0
-   [ ] 318. LC 139 --- Word Break --- P0
-   [ ] 319. LC 198 --- House Robber --- P0
-   [ ] 320. LC 213 --- House Robber II --- P0
-   [ ] 321. LC 300 --- Longest Increasing Subsequence --- P0
-   [ ] 322. LC 322 --- Coin Change --- P0
-   [ ] 323. LC 416 --- Partition Equal Subset Sum --- P0
-   [ ] 324. LC 494 --- Target Sum --- P0
-   [ ] 325. LC 509 --- Fibonacci Number --- P0
-   [ ] 326. LC 518 --- Coin Change II --- P0
-   [ ] 327. LC 647 --- Palindromic Substrings --- P0
-   [ ] 328. LC 746 --- Min Cost Climbing Stairs --- P0
-   [ ] 329. LC 1137 --- N-th Tribonacci Number --- P0
-   [ ] 330. LC 1143 --- Longest Common Subsequence --- P0
-   [ ] 331. LC 72 --- Edit Distance --- P1
-   [ ] 332. LC 115 --- Distinct Subsequences --- P1
-   [ ] 333. LC 120 --- Triangle --- P1
-   [ ] 334. LC 140 --- Word Break II --- P1
-   [ ] 335. LC 221 --- Maximal Square --- P1
-   [ ] 336. LC 276 --- Paint Fence --- P1
-   [ ] 337. LC 279 --- Perfect Squares --- P1
-   [ ] 338. LC 309 --- Best Time to Buy and Sell Stock with Cooldown --- P1
-   [ ] 339. LC 343 --- Integer Break --- P1
-   [ ] 340. LC 368 --- Largest Divisible Subset --- P1
-   [ ] 341. LC 376 --- Wiggle Subsequence --- P1
-   [ ] 342. LC 377 --- Combination Sum IV --- P1
-   [ ] 343. LC 474 --- Ones and Zeroes --- P1
-   [ ] 344. LC 486 --- Predict the Winner --- P1
-   [ ] 345. LC 516 --- Longest Palindromic Subsequence --- P1
-   [ ] 346. LC 583 --- Delete Operation for Two Strings --- P1
-   [ ] 347. LC 646 --- Maximum Length of Pair Chain --- P1
-   [ ] 348. LC 674 --- Longest Continuous Increasing Subsequence --- P1
-   [ ] 349. LC 712 --- Minimum ASCII Delete Sum for Two Strings --- P1
-   [ ] 350. LC 714 --- Best Time to Buy and Sell Stock with Transaction Fee --- P1
-   [ ] 351. LC 740 --- Delete and Earn --- P1
-   [ ] 352. LC 931 --- Minimum Falling Path Sum --- P1
-   [ ] 353. LC 983 --- Minimum Cost For Tickets --- P1
-   [ ] 354. LC 1035 --- Uncrossed Lines --- P1
-   [ ] 355. LC 1048 --- Longest String Chain --- P1
-   [ ] 356. LC 1049 --- Last Stone Weight II --- P1
-   [ ] 357. LC 1105 --- Filling Bookcase Shelves --- P1
-   [ ] 358. LC 1130 --- Minimum Cost Tree From Leaf Values --- P1
-   [ ] 359. LC 1155 --- Number of Dice Rolls With Target Sum --- P1
-   [ ] 360. LC 1218 --- Longest Arithmetic Subsequence of Given Difference --- P1
-   [ ] 361. LC 1277 --- Count Square Submatrices with All Ones --- P1
-   [ ] 362. LC 1644 --- Lowest Common Ancestor of a Binary Tree II --- P1
-   [ ] 363. LC 174 --- Dungeon Game --- P1
-   [ ] 364. LC 97 --- Interleaving String --- P2
-   [ ] 365. LC 123 --- Best Time to Buy and Sell Stock III --- P2
-   [ ] 366. LC 188 --- Best Time to Buy and Sell Stock IV --- P2
-   [ ] 367. LC 312 --- Burst Balloons --- P2
-   [ ] 368. LC 673 --- Number of Longest Increasing Subsequence --- P2
-   [ ] 369. LC 887 --- Super Egg Drop --- P2
-   [ ] 370. LC 1000 --- Minimum Cost to Merge Stones --- P2
-   [ ] 371. LC 1312 --- Minimum Insertion Steps to Make a String Palindrome --- P2
-   [ ] 372. LC 1335 --- Minimum Difficulty of a Job Schedule --- P2
-   [ ] 373. LC 1478 --- Allocate Mailboxes --- P2
-   [ ] 374. LC 1547 --- Minimum Cost to Cut a Stick --- P2
-   [ ] 375. LC 1884 --- Egg Drop With 2 Eggs and N Floors --- P2

# 09. Greedy, Heap & Priority Queue --- 35

-   [ ] 376. LC 45 --- Jump Game II --- P0
-   [ ] 377. LC 55 --- Jump Game --- P0
-   [ ] 378. LC 134 --- Gas Station --- P0
-   [ ] 379. LC 215 --- Kth Largest Element in an Array --- P0
-   [ ] 380. LC 409 --- Longest Palindrome --- P0
-   [ ] 381. LC 455 --- Assign Cookies --- P0
-   [ ] 382. LC 605 --- Can Place Flowers --- P0
-   [ ] 383. LC 763 --- Partition Labels --- P0
-   [ ] 384. LC 860 --- Lemonade Change --- P0
-   [ ] 385. LC 973 --- K Closest Points to Origin --- P0
-   [ ] 386. LC 1046 --- Last Stone Weight --- P0
-   [ ] 387. LC 135 --- Candy --- P1
-   [ ] 388. LC 358 --- Rearrange String k Distance Apart --- P1
-   [ ] 389. LC 406 --- Queue Reconstruction by Height --- P1
-   [ ] 390. LC 621 --- Task Scheduler --- P1
-   [ ] 391. LC 659 --- Split Array into Consecutive Subsequences --- P1
-   [ ] 392. LC 692 --- Top K Frequent Words --- P1
-   [ ] 393. LC 703 --- Kth Largest Element in a Stream --- P1
-   [ ] 394. LC 731 --- My Calendar II --- P1
-   [ ] 395. LC 759 --- Employee Free Time --- P1
-   [ ] 396. LC 767 --- Reorganize String --- P1
-   [ ] 397. LC 846 --- Hand of Straights --- P1
-   [ ] 398. LC 871 --- Minimum Number of Refueling Stops --- P1
-   [ ] 399. LC 1029 --- Two City Scheduling --- P1
-   [ ] 400. LC 1353 --- Maximum Number of Events That Can Be Attended --- P1
-   [ ] 401. LC 1405 --- Longest Happy String --- P1
-   [ ] 402. LC 1642 --- Furthest Building You Can Reach --- P1
-   [ ] 403. LC 1792 --- Maximum Average Pass Ratio --- P1
-   [ ] 404. LC 1834 --- Single-Threaded CPU --- P1
-   [ ] 405. LC 1942 --- The Number of the Smallest Unoccupied Chair --- P1
-   [ ] 406. LC 2402 --- Meeting Rooms III --- P1
-   [ ] 407. LC 295 --- Find Median from Data Stream --- P2
-   [ ] 408. LC 355 --- Design Twitter --- P2
-   [ ] 409. LC 502 --- IPO --- P2
-   [ ] 410. LC 632 --- Smallest Range Covering Elements from K Lists --- P2

# 10. Backtracking & Recursion --- 30

-   [ ] 411. LC 17 --- Letter Combinations of a Phone Number --- P0
-   [ ] 412. LC 22 --- Generate Parentheses --- P0
-   [ ] 413. LC 39 --- Combination Sum --- P0
-   [ ] 414. LC 46 --- Permutations --- P0
-   [ ] 415. LC 77 --- Combinations --- P0
-   [ ] 416. LC 78 --- Subsets --- P0
-   [ ] 417. LC 79 --- Word Search --- P0
-   [ ] 418. LC 784 --- Letter Case Permutation --- P0
-   [ ] 419. LC 1863 --- Sum of All Subset XOR Totals --- P0
-   [ ] 420. LC 40 --- Combination Sum II --- P1
-   [ ] 421. LC 47 --- Permutations II --- P1
-   [ ] 422. LC 52 --- N-Queens II --- P1
-   [ ] 423. LC 90 --- Subsets II --- P1
-   [ ] 424. LC 93 --- Restore IP Addresses --- P1
-   [ ] 425. LC 131 --- Palindrome Partitioning --- P1
-   [ ] 426. LC 216 --- Combination Sum III --- P1
-   [ ] 427. LC 254 --- Factor Combinations --- P1
-   [ ] 428. LC 282 --- Expression Add Operators --- P1
-   [ ] 429. LC 301 --- Remove Invalid Parentheses --- P1
-   [ ] 430. LC 357 --- Count Numbers with Unique Digits --- P1
-   [ ] 431. LC 1239 --- Maximum Length of a Concatenated String with Unique Characters --- P1
-   [ ] 432. LC 1415 --- The k-th Lexicographical String of All Happy Strings of Length n --- P1
-   [ ] 433. LC 1718 --- Construct the Lexicographically Largest Valid Sequence --- P1
-   [ ] 434. LC 37 --- Sudoku Solver --- P2
-   [ ] 435. LC 51 --- N-Queens --- P2
-   [ ] 436. LC 212 --- Word Search II --- P2
-   [ ] 437. LC 473 --- Matchsticks to Square --- P2
-   [ ] 438. LC 491 --- Non-decreasing Subsequences --- P2
-   [ ] 439. LC 698 --- Partition to K Equal Sum Subsets --- P2
-   [ ] 440. LC 842 --- Split Array into Fibonacci Sequence --- P2

# 11. Trie, Segment Tree & Advanced Data Structures --- 20

-   [ ] 441. LC 208 --- Implement Trie (Prefix Tree) --- P0
-   [ ] 442. LC 211 --- Design Add and Search Words Data Structure --- P0
-   [ ] 443. LC 307 --- Range Sum Query - Mutable --- P1
-   [ ] 444. LC 648 --- Replace Words --- P1
-   [ ] 445. LC 677 --- Map Sum Pairs --- P1
-   [ ] 446. LC 720 --- Longest Word in Dictionary --- P1
-   [ ] 447. LC 745 --- Prefix and Suffix Search --- P1
-   [ ] 448. LC 820 --- Shortest Encoding of Words --- P1
-   [ ] 449. LC 1268 --- Search Suggestions System --- P1
-   [ ] 450. LC 1396 --- Design Underground System --- P1
-   [ ] 451. LC 1603 --- Design Parking System --- P1
-   [ ] 452. LC 218 --- The Skyline Problem --- P2
-   [ ] 453. LC 308 --- Range Sum Query 2D - Mutable --- P2
-   [ ] 454. LC 315 --- Count of Smaller Numbers After Self --- P2
-   [ ] 455. LC 421 --- Maximum XOR of Two Numbers in an Array --- P2
-   [ ] 456. LC 493 --- Reverse Pairs --- P2
-   [ ] 457. LC 699 --- Falling Squares --- P2
-   [ ] 458. LC 715 --- Range Module --- P2
-   [ ] 459. LC 850 --- Rectangle Area II --- P2
-   [ ] 460. LC 1707 --- Maximum XOR With an Element From Array --- P2

# 12. Bit Manipulation, Math & Fast Computation --- 20

-   [ ] 461. LC 7 --- Reverse Integer --- P0
-   [ ] 462. LC 9 --- Palindrome Number --- P0
-   [ ] 463. LC 136 --- Single Number --- P0
-   [ ] 464. LC 191 --- Number of 1 Bits --- P0
-   [ ] 465. LC 202 --- Happy Number --- P0
-   [ ] 466. LC 231 --- Power of Two --- P0
-   [ ] 467. LC 338 --- Counting Bits --- P0
-   [ ] 468. LC 29 --- Divide Two Integers --- P1
-   [ ] 469. LC 50 --- Pow(x, n) --- P1
-   [ ] 470. LC 89 --- Gray Code --- P1
-   [ ] 471. LC 137 --- Single Number II --- P1
-   [ ] 472. LC 166 --- Fraction to Recurring Decimal --- P1
-   [ ] 473. LC 172 --- Factorial Trailing Zeroes --- P1
-   [ ] 474. LC 190 --- Reverse Bits --- P1
-   [ ] 475. LC 204 --- Count Primes --- P1
-   [ ] 476. LC 260 --- Single Number III --- P1
-   [ ] 477. LC 477 --- Total Hamming Distance --- P1
-   [ ] 478. LC 149 --- Max Points on a Line --- P2
-   [ ] 479. LC 201 --- Bitwise AND of Numbers Range --- P2
-   [ ] 480. LC 371 --- Sum of Two Integers --- P2

# 13. Microsoft High-Frequency Real OA & GFG Interview Classics --- 20

-   [ ] 481. GFG --- Kadane's Algorithm --- P0
-   [ ] 482. GFG --- Maximum Product Subarray --- P0
-   [ ] 483. GFG --- Longest Subarray with Sum K --- P0
-   [ ] 484. GFG --- Merge Overlapping Intervals --- P0
-   [ ] 485. GFG --- Minimum Platforms --- P0
-   [ ] 486. GFG --- Activity Selection --- P0
-   [ ] 487. GFG --- N Meetings in One Room --- P0
-   [ ] 488. GFG --- Next Greater Element --- P0
-   [ ] 489. GFG --- LRU Cache --- P0
-   [ ] 490. GFG --- Detect Cycle in an Undirected Graph --- P0
-   [ ] 491. GFG --- Detect Cycle in a Directed Graph --- P0
-   [ ] 492. GFG --- Topological Sort --- P0
-   [ ] 493. GFG --- Dijkstra Algorithm --- P0
-   [ ] 494. GFG --- 0/1 Knapsack --- P0
-   [ ] 495. GFG --- Count Inversions --- P1
-   [ ] 496. GFG --- Job Sequencing Problem --- P1
-   [ ] 497. GFG --- Bellman-Ford Algorithm --- P1
-   [ ] 498. GFG --- Kruskal's Algorithm --- P1
-   [ ] 499. GFG --- Prim's Algorithm --- P1
-   [ ] 500. GFG --- Matrix Chain Multiplication --- P2

# 14. Striver A2Z Classics & Missing Essentials --- 30

-   [ ] 501. LC 1752 --- Check if Array Is Sorted and Rotated --- P0
-   [ ] 502. GFG --- Union of Two Sorted Arrays --- P0
-   [ ] 503. GFG --- Find Missing and Repeating Number --- P0
-   [ ] 504. IB --- Count Subarrays with Given XOR K --- P0
-   [ ] 505. GFG --- Book Allocation Problem --- P0
-   [ ] 506. GFG --- Aggressive Cows --- P0
-   [ ] 507. GFG --- Painter's Partition Problem --- P0
-   [ ] 508. GFG --- Length of Loop in Linked List --- P0
-   [ ] 509. GFG --- Add 1 to a Number Represented as Linked List --- P0
-   [ ] 510. GFG --- Flattening a Linked List --- P0
-   [ ] 511. GFG --- Sort a Linked List of 0s, 1s and 2s --- P0
-   [ ] 512. GFG --- The Celebrity Problem --- P0
-   [ ] 513. LC 907 --- Sum of Subarray Minimums --- P0
-   [ ] 514. LC 2104 --- Sum of Subarray Ranges --- P1
-   [ ] 515. GFG --- Substring with K Distinct Characters --- P1
-   [ ] 516. GFG --- Shortest Job First --- P1
-   [ ] 517. GFG --- Connect Ropes with Minimum Cost --- P1
-   [ ] 518. GFG --- Boundary Traversal of Binary Tree --- P1
-   [ ] 519. GFG --- Top View of Binary Tree --- P1
-   [ ] 520. GFG --- Bottom View of Binary Tree --- P1
-   [ ] 521. GFG --- Children Sum Property in Binary Tree --- P1
-   [ ] 522. GFG --- Minimum Time Taken to Burn the Binary Tree --- P1
-   [ ] 523. GFG --- Largest BST in Binary Tree --- P1
-   [ ] 524. GFG --- Strongly Connected Components (Kosaraju's Algorithm) --- P1
-   [ ] 525. GFG --- Articulation Points in Graph --- P1
-   [ ] 526. GFG --- Floyd Warshall Algorithm --- P1
-   [ ] 527. GFG --- Minimum Multiplications to Reach End --- P1
-   [ ] 528. GFG --- Ninja's Training --- P1
-   [ ] 529. GFG --- Rod Cutting Problem --- P1
-   [ ] 530. GFG --- Boolean Parenthesization --- P2

------------------------------------------------------------------------

# Microsoft OA Priority Order

If your Microsoft OA or technical interview is approaching soon, **do not attempt all 530 equally**. Follow this strategic priority roadmap:

## Tier A --- Finish First (High OA Frequency)
1. **Arrays + Hashing + Prefix Sum** (Subtopic 1)
2. **Two Pointers & Sliding Window** (Subtopic 2)
3. **Binary Search & Search on Answer** (Subtopic 3)
4. **Linked Lists** (Subtopic 4)
5. **Trees & BST Core** (Subtopic 6)
6. **BFS / DFS & Grid Graphs** (Subtopic 7)
7. **Basic & Linear DP** (Subtopic 8)
8. **Greedy & Heap / Priority Queue** (Subtopic 9)
9. **Stack & Monotonic Stack** (Subtopic 5)

## Tier B --- Finish Second (Technical Interview Core)
- **LRU & LFU Cache Design** (Subtopic 5)
- **Topological Sort & Course Schedule** (Subtopic 7)
- **Disjoint Set Union (DSU) & Minimum Spanning Trees** (Subtopic 7)
- **Dijkstra's Shortest Path Algorithm** (Subtopic 7)
- **Backtracking & Recursion** (Subtopic 10)
- **Advanced DP (Knapsack, LCS, LIS, String DP)** (Subtopic 8)
- **Search Suggestions System / Trie** (Subtopic 11)
- **Bit Manipulation Core** (Subtopic 12)

## Tier C --- Advanced & Follow-Ups (Interview Mastery)
- **Median of Two Sorted Arrays** (Subtopic 3)
- **Hard Interval / Bitmask DP** (Subtopic 8)
- **Sudoku Solver & N-Queens** (Subtopic 10)
- **Segment Tree & Fenwick Tree** (Subtopic 11)
- **Hard Graph & Eulerian Path / Critical Connections** (Subtopic 7)

------------------------------------------------------------------------

# Pattern Checklist

Before your Microsoft OA, ensure you recognize these patterns instantly:

| Pattern | Key Recognition Signals |
| :--- | :--- |
| **Hash Map / Set** | Frequency counting, pair lookup, $O(1)$ fast search, string grouping |
| **Prefix Sum** | Subarray sum, range sum queries, contiguous sum equal to $K$ |
| **Two Pointers** | Sorted array target sum, palindrome check, container water bounds |
| **Sliding Window** | Contiguous subsegment optimization, substring with $K$ distinct chars |
| **Binary Search** | Sorted input, monotonic predicate space `check(x)`, rotated array |
| **Fast & Slow Pointers** | Linked list cycle detection, middle node, cycle start node |
| **Monotonic Stack** | Next greater element, previous smaller element, histogram area |
| **Monotonic Queue** | Max / Min element in a sliding window of size $K$ |
| **BFS** | Shortest path in unweighted graph/grid, level-by-level traversal |
| **DFS** | Island components traversal, tree paths, backtracking search |
| **Union Find (DSU)** | Dynamic connectivity, component merging, cycle detection |
| **Topological Sort** | Dependency ordering, prerequisite scheduling (Course Schedule) |
| **Dijkstra** | Shortest path in weighted graph with non-negative edge weights |
| **Greedy** | Local optimal choice leading to global optimum (Interval scheduling) |
| **Heap / Priority Queue** | Top-$K$ elements, continuous stream median, $K$-way merge |
| **1D / Grid DP** | Overlapping subproblems, grid paths, stair climbing |
| **Knapsack DP** | Item selection (take / leave choice) with weight/sum target |
| **String / LCS DP** | String alignment, edit distance, common subsequence |
| **LIS DP** | Longest increasing subsequence ending at index $i$ |
| **Backtracking** | Exhaustive search across decision tree with pruning |
| **Trie** | Prefix searching, autocomplete suggestions, dictionary lookup |
| **Bit Manipulation** | Bit masking, single number XOR cancellation, subset flags |

------------------------------------------------------------------------

# OA Simulation Rule

After working through the roadmap, complete **10 timed mock OAs**.

For each mock session:
- **Duration:** 60--75 minutes
- **Format:** 2 medium/hard DSA problems
- **Rules:** No external solutions or editorials allowed; write in C++ from scratch
- **Testing:** Verify custom edge cases manually before submitting
- **Pacing Goal:**
  ```text
  Problem 1  → 20–25 min
  Problem 2  → 25–35 min
  Debugging  → 10–15 min
  ```

The ultimate objective is to make **pattern recognition instantaneous** for every problem encountered in Microsoft assessments.

------------------------------------------------------------------------

# Operating Systems (OS) Core Interview Roadmap

This section covers the essential Operating System concepts frequently tested in Microsoft technical interview rounds, based on the standard GFG OS curriculum.

---

## 1. Basics
- [ ] **Introduction to OS:** Functions, goals, layered architecture, kernel vs user space.
- [ ] **Types of OS:** Batch, Multiprogramming, Multitasking/Time-sharing, Real-Time (RTOS), Distributed, Clustered OS.
- [ ] **Kernel in OS:** Monolithic Kernel vs Microkernel vs Hybrid Kernel.
- [ ] **System Calls:** User mode vs Kernel mode, Mode switch (Dual mode operation), `fork()`, `exec()`, `wait()`, `exit()`, `open()`, `read()`, `write()`.
- [ ] **System Initialization & Booting:** BIOS, MBR, Bootloader (GRUB), Kernel loading, Init/Systemd process.

---

## 2. Process Management & CPU Scheduling
- [ ] **Process Introduction:** Program vs Process, Memory layout of a process (Code, Data, Heap, Stack).
- [ ] **Process Control Block (PCB):** PID, State, PC, Registers, Scheduling info, Memory management info, I/O status.
- [ ] **Process Table & Process States:** 5-State / 7-State model (New, Ready, Running, Waiting/Blocked, Terminated, Suspend Ready, Suspend Blocked).
- [ ] **Process Schedulers:** Long-Term Scheduler (LTS/Job), Short-Term Scheduler (STS/CPU), Medium-Term Scheduler (MTS/Swapper).
- [ ] **Dispatcher vs Scheduler:** Context Switching overhead, Dispatch latency.
- [ ] **Preemptive vs Non-Preemptive Scheduling:** Response time, throughput, turnaround time, waiting time.
- [ ] **CPU Scheduling Algorithms:**
  - First-Come, First-Served (FCFS) & Convoy Effect.
  - Shortest Job First (SJF) & Shortest Remaining Time First (SRTF).
  - Round Robin (RR) & Time Quantum tradeoff.
  - Priority Scheduling (Preemptive & Non-Preemptive).
  - Multi-Level Queue (MLQ) & Multi-Level Feedback Queue (MLFQ).
- [ ] **Starvation and Aging:** Definition, causes, and solving starvation using dynamic aging.

---

## 3. Process Synchronization & IPC
- [ ] **Inter-Process Communication (IPC):** Shared Memory vs Message Passing, Pipes, Named Pipes (FIFO), Sockets.
- [ ] **Race Condition & Critical Section:** Entry section, Critical section, Exit section, Remainder section.
- [ ] **Criteria for Valid Synchronization:** Mutual Exclusion, Progress, Bounded Waiting, Architectural Neutrality.
- [ ] **Software-Based Solutions:**
  - Peterson's Algorithm (2 processes).
  - Dekker's Algorithm.
  - Lamport's Bakery Algorithm ($N$ processes).
- [ ] **Hardware-Based Solutions:** Test-and-Set (TAS), Compare-and-Swap (CAS), Disabling Interrupts.
- [ ] **Semaphores:** Counting Semaphore vs Binary Semaphore, `wait()` (P) and `signal()` (V) atomic operations.
- [ ] **Mutex vs Semaphore:** Ownership concept, binary semaphore vs mutual exclusion lock.
- [ ] **Monitors:** High-level synchronization construct, condition variables (`wait()`, `signal()`).
- [ ] **Priority Inversion:** Definition, Priority Inheritance Protocol, Priority Ceiling Protocol.
- [ ] **Classical IPC Problems:**
  - Producer-Consumer Problem (Bounded Buffer).
  - Readers-Writers Problem (Reader Preference vs Writer Preference).
  - Dining Philosophers Problem & Deadlock-Free Solutions.
  - Sleeping Barber Problem.

---

## 4. Deadlock
- [ ] **Introduction & Necessary Conditions (Coffman Conditions):**
  1. Mutual Exclusion
  2. Hold and Wait
  3. No Preemption
  4. Circular Wait
- [ ] **Resource Allocation Graph (RAG):** Claim edge, Assignment edge, Request edge, Cycle detection for single vs multiple instances.
- [ ] **Deadlock Handling Strategies:**
  - Ignorance (Ostrich Algorithm).
  - Deadlock Prevention (Breaking any 1 of 4 Coffman conditions).
  - Deadlock Avoidance (Safe State, Banker's Algorithm: Resource-Request & Safety algorithms).
  - Deadlock Detection and Recovery (Killing processes, resource preemption).
- [ ] **Deadlock vs Starvation vs Livelock:** Differences, state transitions, and identification.
- [ ] **Methods of Resource Allocation & Deadlock-Free Programs:** Resource ordering, total resource limits.

---

## 5. Multithreading & Concurrency
- [ ] **Thread Concepts:** Process vs Thread, Thread Control Block (TCB), Shared vs Private thread resources.
- [ ] **User-Level Threads (ULT) vs Kernel-Level Threads (KLT):** Pros, cons, context switch speeds, kernel visibility.
- [ ] **Multitasking:** Process-based vs Thread-based multitasking.
- [ ] **Multithreading Models:** Many-to-One, One-to-One, Many-to-Many, Two-Level model.
- [ ] **Benefits & Pitfalls of Multithreading:** Resource sharing, responsiveness, scalability, race conditions, false sharing.

---

## 6. Memory Management
- [ ] **Basics:** Memory hierarchy, Memory units, Logical (Virtual) vs Physical address, Memory Management Unit (MMU).
- [ ] **Contiguous Allocation:** Fixed partitioning (Static MFT) vs Variable partitioning (Dynamic MVT).
  - Internal Fragmentation vs External Fragmentation.
  - Allocation Algorithms: First Fit, Best Fit, Worst Fit, Next Fit.
  - Compaction & Buddy System (Power-of-2 allocation).
- [ ] **Non-Contiguous Allocation:**
  - **Paging:** Pages, Page Frames, Page Table Base Register (PTBR), Address translation formula (`Logical = Page# + Offset`).
  - **Page Table Structure:** Page Table Entries (PTE), Protection bits, Present/Absent bit, Dirty (Modified) bit, Referenced bit.
  - Multi-Level Paging, Inverted Page Table, Translation Lookaside Buffer (TLB), Effective Memory Access Time (EMAT).
  - **Segmentation:** Logical address (`Segment# + Offset`), Segment Table, Base & Limit registers.
  - **Segmentation with Paging:** Combined benefits of logical modularity and zero external fragmentation.
- [ ] **Advanced Memory Concepts:**
  - Overlays.
  - **Virtual Memory & Demand Paging:** Lazy swapper, Pure demand paging.
  - **Page Fault Handling:** 6-step hardware/OS trap sequence.
  - Swap Space Management.
- [ ] **Page Replacement & Thrashing:**
  - FIFO Page Replacement & Belady's Anomaly.
  - Optimal Page Replacement (OPT / MIN).
  - Least Recently Used (LRU) Page Replacement.
  - Second Chance (Clock) Page Replacement Policy.
  - **Thrashing:** Causes, Degree of Multiprogramming graph, Page Fault Frequency (PFF) method, Working Set Model in Paging.
- [ ] **Kernel Memory & System Virtualization:**
  - Kernel memory allocation: Buddy allocator & Slab allocator (Caches & Objects).
  - Memory Interleaving.
  - OS-Level Virtualization & Containers.

---

## 7. Disk Management & File Systems
- [ ] **File Systems:** File attributes, file operations, file types, File Control Block (FCB) / Inode.
- [ ] **Unix File System:** Inodes, direct blocks, single indirect, double indirect, triple indirect pointers.
- [ ] **Directory Structures:** Single-level, Two-level, Tree-structured, Acyclic graph, General graph directory.
- [ ] **File Allocation Methods:** Contiguous allocation, Linked allocation (FAT), Indexed allocation (Inode).
- [ ] **File Access Methods:** Sequential Access, Direct / Random Access, Indexed Access.
- [ ] **Secondary Storage (Hard Disk Drive Architecture):** Platters, Tracks, Sectors, Cylinders, Read/Write heads.
- [ ] **Disk Performance Metrics:** Seek time, Rotational latency, Transfer time.
- [ ] **Disk Scheduling Algorithms:**
  - FCFS (First-Come, First-Served).
  - SSTF (Shortest Seek Time First) & Starvation.
  - SCAN (Elevator Algorithm).
  - C-SCAN (Circular SCAN).
  - LOOK and C-LOOK.
- [ ] **I/O Concepts:**
  - **Spooling:** Simultaneous Peripheral Operations On-Line (concept, printer daemon).
  - **Spooling vs Buffering:** Detailed comparison and use cases.
  - **Free Space Management:** Bit vector / Bitmap, Linked List, Grouping, Counting.

---

## 8. Advanced OS Interview Essentials
- [ ] **Zombie vs Orphan Processes:**
  - Zombie process lifecycle, `wait()` system call, Process Table saturation.
  - Orphan process lifecycle, Adoption by `init` / `systemd` (PID 1), Automatic reaping.
- [ ] **Copy-on-Write (COW):**
  - Efficient process creation via `fork()`, Read-only shared page frames, Page fault on write trigger, Copy overhead reduction.
- [ ] **RAID Levels & Storage Reliability:**
  - RAID 0 (Data Striping, High performance, Zero redundancy).
  - RAID 1 (Disk Mirroring, 100% Redundancy, Fast read).
  - RAID 5 (Block Striping with Distributed Parity, Single-disk fault tolerance).
  - RAID 6 (Dual Distributed Parity, Two-disk fault tolerance).
  - RAID 10 (1+0 Striped Mirrors).
- [ ] **32-Bit vs. 64-Bit Architectures & Operating Systems:**
  - Register width, data bus width, address bus width.
  - Mathematical 4 GB limit of 32-bit systems ($2^{32}\text{ bytes}$).
  - 64-bit theoretical (16 Exabytes) vs practical (48-bit 256 TB / 57-bit 128 PB) limits.
  - Pointer sizes (4 vs 8 bytes), data type models (ILP32 vs LP64 / LLP64), and backward compatibility (WoW64).
- [ ] **POSIX Signals & Signal Handling:**
  - Standard signals (`SIGINT`, `SIGKILL`, `SIGTERM`, `SIGSEGV`, `SIGCHLD`, `SIGSTOP`).
  - Uncatchable signals (`SIGKILL`, `SIGSTOP`), custom signal handlers (`signal()` / `sigaction()`).
- [ ] **Direct Memory Access (DMA) & I/O Communication:**
  - Polling vs. Interrupt-Driven I/O vs. DMA.
  - DMA controller operation, Cycle Stealing mode vs. Burst mode.
- [ ] **Hard Links vs. Soft (Symbolic) Links:**
  - Inode sharing, `link_count`, filesystem boundary constraints, dangling/broken symlinks.
- [ ] **Memory-Mapped Files (`mmap`):**
  - Zero-copy architecture, page cache direct mapping, high-speed file operations, and Shared Memory IPC.

------------------------------------------------------------------------

# Object-Oriented Programming (OOPs) Core Interview Roadmap

This section covers the fundamental and advanced Object-Oriented Programming concepts in **both C++ and Python**, based on the standard GFG OOPs curriculum.

---

## 1. Core OOPs Pillars
- [ ] **Classes & Objects:** Memory layout, instantiation, state vs. behavior, C++ vs. Python syntax.
- [ ] **Encapsulation & Data Hiding:** Access modifiers (`public`, `protected`, `private`), Getters/Setters, Name Mangling (`__var`) in Python.
- [ ] **Abstraction & Interfaces:** Abstract Base Classes (`abc.ABC`), Pure virtual functions (`virtual void func() = 0`), Interface contracts.
- [ ] **Inheritance & The Diamond Problem:**
  - Single, Multiple, Multilevel, Hierarchical, and Hybrid inheritance.
  - The Diamond Problem, Virtual Base Classes in C++, Method Resolution Order (MRO / C3 Linearization) and `super()` in Python.
- [ ] **Polymorphism (Compile-time vs. Runtime):**
  - Function & Operator Overloading (Compile-time).
  - Function Overriding, Virtual Functions, `vptr` and `vtable` internals in C++, Dynamic Dispatch & Duck Typing in Python.

---

## 2. Constructors, Destructors & Object Lifecycle
- [ ] **Constructors & Initializers:** Default, Parameterized, Initializer lists in C++, `__init__` vs. `__new__` in Python.
- [ ] **Copy Constructors, Shallow vs. Deep Copy:**
  - Pointer aliasing bugs, Rule of 3 / 5 / 0 in C++, `copy.copy()` vs. `copy.deepcopy()` in Python.
- [ ] **Move Semantics & Rvalues (C++):** Rvalue references (`&&`), `std::move`, Move constructor and Move assignment operator.
- [ ] **Destructors & Virtual Destructors:**
  - Memory cleanup, Why base class destructors MUST be virtual in C++, `__del__` and Garbage Collection (Reference counting + Cyclic GC) in Python.

---

## 3. Advanced OOPs Concepts & Relationships
- [ ] **Association, Aggregation & Composition:** "Is-A" vs. "Has-A", Strong lifecycle dependency (Composition) vs. Weak dependency (Aggregation).
- [ ] **Static Members & Methods:** `static` keyword in C++ vs. `@staticmethod` and `@classmethod` (`cls`) in Python, `this` vs. `self`.
- [ ] **Friend Classes/Functions & Python Dunder Methods:** `friend` in C++ vs. Magic/Dunder methods (`__str__`, `__repr__`, `__len__`, `__eq__`, `__add__`) in Python.
- [ ] **Object Slicing & Type Casting:** Object slicing in C++ value semantics, `dynamic_cast`, `static_cast`, Duck typing in Python.

---

## 4. SOLID Design Principles
- [ ] **Single Responsibility Principle (SRP):** One class, one single reason to change.
- [ ] **Open/Closed Principle (OCP):** Open for extension, closed for modification.
- [ ] **Liskov Substitution Principle (LSP):** Subtypes must be substitutable for their base types (Square-Rectangle problem).
- [ ] **Interface Segregation Principle (ISP):** Clients should not be forced to depend on interfaces they do not use.
- [ ] **Dependency Inversion Principle (DIP):** High-level modules should not depend on low-level modules; both should depend on abstractions.

---

## 5. Essential Design Patterns
- [ ] **Singleton Pattern:** Thread-safe Meyers Singleton in C++, Metaclass / `__new__` Singleton in Python.
- [ ] **Factory Method Pattern:** Encapsulating object creation based on input parameters.
- [ ] **Builder Pattern:** Step-by-step construction of complex objects with method chaining.
- [ ] **Adapter Pattern:** Translating incompatible interfaces.
- [ ] **Decorator Pattern:** Dynamically attaching new behaviors to objects/functions.
- [ ] **Observer Pattern:** One-to-many dependency event notification (Pub-Sub).
- [ ] **Strategy Pattern:** Defining a family of interchangeable algorithms at runtime.

------------------------------------------------------------------------

# Database Management Systems (DBMS) Core Interview Roadmap

This section covers essential Database Management Systems concepts based on the standard GFG DBMS curriculum.

---

## 1. Basics & ER Modeling
- [ ] **Introduction to DBMS:** DBMS vs. File Systems, Advantages, ACID guarantees.
- [ ] **Three-Schema Architecture:** Physical (Internal), Logical (Conceptual), View (External) level.
- [ ] **Data Independence:** Physical Data Independence vs. Logical Data Independence.
- [ ] **Entity-Relationship (ER) Model:**
  - Entities, Entity Sets, Attributes (Simple, Composite, Derived, Multi-valued).
  - Cardinality & Participation Constraints (1:1, 1:N, M:N, Total vs. Partial participation).
  - Weak Entity Sets & Identifying Relationships.
  - Extended ER: Generalization, Specialization, Aggregation.
- [ ] **ER-to-Relational Table Mapping:** Rules for converting entities, 1:N, M:N, and weak entities into normalized tables.

---

## 2. Relational Model & Relational Algebra
- [ ] **Relational Model Concepts:** Relations (Tables), Tuples (Rows), Attributes (Columns), Domains, Degree vs. Cardinality.
- [ ] **Keys in DBMS:**
  - Super Key, Candidate Key, Primary Key, Alternate Key.
  - Foreign Key, Referential Integrity Constraints, Cascading Actions (`CASCADE`, `SET NULL`, `RESTRICT`).
- [ ] **Relational Algebra Operators:**
  - Fundamental: Selection ($\sigma$), Projection ($\pi$), Cross Product ($\times$), Union ($\cup$), Difference ($-$).
  - Derived: Set Intersection ($\cap$), Joins (Natural $\bowtie$, Theta $\bowtie_\theta$, Equi, Left/Right/Full Outer Joins), Division ($\div$).

---

## 3. Functional Dependencies & Normalization
- [ ] **Functional Dependencies (FD):** Trivial, Non-trivial, Semi-trivial dependencies.
- [ ] **Armstrong's Axioms & Attribute Closure:** Reflexivity, Augmentation, Transitivity; Algorithm to find Candidate Keys.
- [ ] **Database Anomalies:** Insertion, Deletion, Update Anomalies.
- [ ] **Normal Forms:**
  - **1NF:** Atomic attribute values, no repeating groups.
  - **2NF:** 1NF + No Partial Dependency (No non-prime attribute depends on a subset of a candidate key).
  - **3NF:** 2NF + No Transitive Dependency (For $X \to Y$, either $X$ is a Super Key or $Y$ is a Prime Attribute).
  - **BCNF (Boyce-Codd Normal Form):** Stricter 3NF (For every $X \to Y$, $X$ MUST be a Super Key).
  - **4NF & 5NF:** Multi-valued dependencies & Join dependencies.
- [ ] **Decomposition Properties:** Lossless Join Decomposition (Testing using matrix/intersection rule) vs. Dependency Preserving Decomposition.

---

## 4. SQL (Structured Query Language)
- [ ] **SQL Sublanguages:** DDL (`CREATE`, `ALTER`, `DROP`, `TRUNCATE`), DML (`INSERT`, `UPDATE`, `DELETE`), DQL (`SELECT`), DCL (`GRANT`, `REVOKE`), TCL (`COMMIT`, `ROLLBACK`, `SAVEPOINT`).
- [ ] **Clauses & Aggregation:** `WHERE` vs. `HAVING`, `GROUP BY`, `ORDER BY`, `DISTINCT`, `LIMIT` / `OFFSET`.
- [ ] **SQL Joins:** `INNER JOIN`, `LEFT JOIN`, `RIGHT JOIN`, `FULL OUTER JOIN`, `CROSS JOIN`, `SELF JOIN`.
- [ ] **Advanced SQL Queries:**
  - Correlated & Nested Subqueries.
  - Common Table Expressions (CTEs - `WITH` clause).
  - Window Functions: `ROW_NUMBER()`, `RANK()`, `DENSE_RANK()`, `LEAD()`, `LAG()`.
  - Finding $N$-th Highest Salary (Top Interview SQL problem).

---

## 5. Transactions & Concurrency Control
- [ ] **Transactions & ACID Properties:** Atomicity, Consistency, Isolation, Durability.
- [ ] **Transaction State Lifecycle:** Active, Partially Committed, Committed, Failed, Aborted.
- [ ] **Concurrency Anomalies (Read/Write Conflicts):**
  - Dirty Read (Write-Read / WR conflict).
  - Unrepeatable Read (Read-Write / RW conflict).
  - Lost Update (Write-Write / WW conflict).
  - Phantom Read.
- [ ] **Serializability:**
  - Conflict Serializability (Testing via Precedence Graph / Conflict Graph cycle detection).
  - View Serializability & Blind Writes.
- [ ] **Schedule Recoverability:** Recoverable Schedules, Cascadeless Schedules, Strict Schedules.
- [ ] **Concurrency Control Protocols:**
  - **Two-Phase Locking (2PL):** Growing phase, Shrinking phase (Basic, Conservative, Strict, Rigorous 2PL).
  - **Timestamp Ordering Protocol:** Basic TO, Thomas Write Rule.

---

## 6. Indexing & Storage Engine Architecture
- [ ] **File Organization:** Sequential, Heap, Hash file organization.
- [ ] **Types of Indexes:** Primary Index, Secondary Index, Clustered Index, Non-Clustered Index, Dense vs. Sparse Index.
- [ ] **B-Trees & B+ Trees:**
  - Internal node vs. Leaf node structure.
  - Search, Insertion, and Deletion complexity ($O(\log_B N)$).
  - Why B+ Trees are standard for relational database disk storage (Linked leaf nodes, fast range queries).
- [ ] **Dynamic Hashing:** Extendible Hashing (Directory, Global/Local Depth) vs. Linear Hashing.

---

## 7. Advanced DBMS, Recovery & NoSQL
- [ ] **Deadlock Management in DBMS:** Wait-For Graph, Wait-Die Scheme vs. Wound-Wait Scheme (Timestamp-based prevention).
- [ ] **Database Recovery Management:**
  - Log-Based Recovery (Write-Ahead Logging / WAL).
  - Undo and Redo operations, Checkpoints (Fuzzy checkpointing).
- [ ] **CAP Theorem & BASE Properties:** Consistency, Availability, Partition Tolerance trade-offs.
- [ ] **SQL (RDBMS) vs. NoSQL:** Document (MongoDB), Key-Value (Redis), Columnar (Cassandra), Graph (Neo4j).

------------------------------------------------------------------------

# Machine Learning (ML) Master Interview Roadmap

This section covers the end-to-end Machine Learning curriculum based on the standard GFG Machine Learning guide, from math foundations and algorithms to deployment and MLOps.

---

## 1. ML Pipeline, Preprocessing & Evaluation
- [ ] **ML Workflow & Data Cleaning:** Handling missing values (Imputation), outlier detection (IQR, Z-Score), categorical encoding (One-Hot, Target, Ordinal).
- [ ] **Feature Engineering & Selection:** Feature scaling (Standardization vs. Normalization), filter/wrapper/embedded methods, Variance Threshold.
- [ ] **Model Evaluation Metrics:**
  - Classification: Confusion Matrix, Precision, Recall, F1-Score, Specificity, ROC-AUC curve, Log-Loss.
  - Regression: MAE, MSE, RMSE, $R^2$, Adjusted $R^2$.
- [ ] **Bias-Variance Tradeoff & Regularization:** Underfitting vs. Overfitting, L1 Lasso (Sparse feature selection), L2 Ridge (Weight shrinkage), ElasticNet.
- [ ] **Validation & Tuning:** K-Fold Cross-Validation, Stratified K-Fold, GridSearchCV, RandomizedSearchCV, Optuna.

---

## 2. Supervised Learning: Regression & Classification
- [ ] **Linear Regression:** Simple & Multiple Linear Regression, Cost function (MSE), Ordinary Least Squares (OLS) vs. Gradient Descent (Batch, Mini-batch, Stochastic).
- [ ] **Logistic Regression:** Sigmoid / Softmax activation, Log-Loss (Binary Cross-Entropy), Decision boundaries, Odds ratio.
- [ ] **Decision Trees:** Entropy, Information Gain, Gini Impurity, Tree pruning (Pre-pruning vs. Post-pruning), CART algorithm.
- [ ] **Support Vector Machines (SVM):** Maximum margin hyperplane, Support vectors, Hard vs. Soft margin ($C$ parameter), Kernel Trick (Linear, Polynomial, RBF/Gaussian).
- [ ] **K-Nearest Neighbors (KNN):** Lazy learner, Distance metrics (Euclidean, Manhattan, Minkowski), Choosing optimal $K$, Curse of Dimensionality.
- [ ] **Naïve Bayes:** Bayes' Theorem, Conditional independence assumption, Gaussian NB, Multinomial NB, Bernoulli NB, Laplace Smoothing ($\alpha$).
- [ ] **Ensemble Learning:**
  - **Bagging:** Bootstrap Aggregating, Random Forest, Out-of-Bag (OOB) error, Feature importance.
  - **Boosting:** AdaBoost (Weight updating), Gradient Boosting Machine (GBM), XGBoost, LightGBM, CatBoost.

---

## 3. Unsupervised Learning: Clustering & Dimensionality Reduction
- [ ] **Centroid & Distribution Clustering:** K-Means, K-Means++ initialization, Elbow Method, Silhouette Score, Gaussian Mixture Models (GMM) & Expectation-Maximization (EM).
- [ ] **Hierarchical & Density Clustering:** Agglomerative Clustering, Dendrogram linkage (Single, Complete, Average, Ward), DBSCAN ($\epsilon$, MinPts, Core/Border/Noise), OPTICS.
- [ ] **Dimensionality Reduction:**
  - Principal Component Analysis (PCA): Covariance matrix, Eigenvalues & Eigenvectors, Explained variance ratio.
  - Non-linear techniques: t-SNE, UMAP, LDA (Linear Discriminant Analysis - Supervised), Independent Component Analysis (ICA).
- [ ] **Association Rule Mining:** Market Basket Analysis, Support, Confidence, Lift, Apriori Algorithm, FP-Growth.

---

## 4. Reinforcement Learning
- [ ] **RL Foundations:** Agent, Environment, State ($S$), Action ($A$), Reward ($R$), Policy ($\pi(a|s)$), Value function ($V(s)$), Action-Value function ($Q(s, a)$).
- [ ] **Model-Based RL:** Markov Decision Processes (MDP), Bellman Equations, Value Iteration, Policy Iteration, Monte Carlo Tree Search (MCTS).
- [ ] **Model-Free RL:**
  - Q-Learning (Off-Policy TD Control), Bellman Optimality update.
  - SARSA (On-Policy TD Control).
  - Deep Q-Networks (DQN: Experience Replay, Target Network).
  - Policy Gradients (REINFORCE), Actor-Critic (A2C, A3C).

---

## 5. Semi-Supervised, Self-Supervised & Few-Shot Learning
- [ ] **Semi-Supervised Learning:** Pseudo-Labeling, Self-Training, Co-Training, Label Propagation.
- [ ] **Self-Supervised Learning:** Contrastive Learning (SimCLR, MoCo), Masked Language/Image Modeling (BERT, MAE).
- [ ] **Few-Shot & Zero-Shot Learning:** Meta-learning, Siamese Networks (Contrastive loss), Prototypical Networks.

---

## 6. Time Series Forecasting
- [ ] **Time Series Fundamentals:** Trend, Seasonality, Cyclicality, Stationarity, Augmented Dickey-Fuller (ADF) test, ACF and PACF plots.
- [ ] **Statistical Forecasting Models:** Moving Average (MA), Exponential Smoothing (Simple, Holt's linear, Holt-Winters seasonal), ARIMA ($p, d, q$), SARIMA ($P, D, Q, s$).

---

## 7. Model Deployment & MLOps
- [ ] **Interactive Prototyping:** Building web UIs using Streamlit and Gradio.
- [ ] **Production APIs:** Serving models with FastAPI and Flask, Pydantic request validation, async inference.
- [ ] **MLOps Lifecycle:**
  - Experiment Tracking & Model Registry (MLflow, Weights & Biases).
  - Model Monitoring: Data Drift (KS-Test), Concept Drift (Performance degradation).
  - Containerization & CI/CD: Dockerizing ML models, Automated testing, ONNX runtime optimization.





