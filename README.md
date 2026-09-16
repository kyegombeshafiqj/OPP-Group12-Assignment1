# OPP-Group12-Assignment1
Algorithmic Ordering and Ranking 
 Introduction
Data sequencing and comparative evaluation are central components of modern software systems, database engines, and data science workflows. The goal of this project by Group 12 was to implement, test, and analyze five fundamental operations responsible for ordering and evaluating elements within a dataset:

 Data Sequencing: Standard sort() to reorganize values directly, and argsort() to provide indirect index mappings for non-destructive data handling.

 Statistical & Window Ranking: Standard rank(), dense_rank(), and percentile_rank() to assign positional evaluation metrics to elements while handling duplicate values (ties) through various common methodologies.

By implementing these algorithms from scratch, our project explores the underlying computational complexities, memory performance, and practical use cases of positional data manipulation in software engineering.

Common Test Data
Input Array: [78, 92, 65, 85, 92, 70, 55, 85, 60, 75]
Total Elements (N): 10
Operation Explanations & Test Data Results
1. sort()
Explanation: Rearranges the elements of the array in ascending order (from smallest to largest).
Output: [55, 60, 65, 70, 75, 78, 85, 85, 92, 92]
2. argsort()
Explanation: Returns the indices that would sort the original array. It tells you the original position of each element in the newly sorted order.
Output: [6, 8, 2, 5, 9, 0, 3, 7, 1, 4](For example, the smallest number 55 is at index 6 in the original array, so 6 comes first).
3. rank()
Explanation: Assigns a rank to each element based on its value. By default, it uses the "average" method for ties. Tied values receive the average of the ranks they would have occupied.
Sorted Positions (1-indexed): 55 (1), 60 (2), 65 (3), 70 (4), 75 (5), 78 (6), 85 (7, 8), 92 (9, 10).
Output (mapped to original order): [6.0, 9.5, 3.0, 7.5, 9.5, 4.0, 1.0, 7.5, 2.0, 5.0]
4. dense_rank()
Explanation: Assigns ranks to elements, but ties receive the same rank without leaving gaps in the next rank number. Ranks always increase by 1 for the next distinct value.
Distinct Values Ranked: 55 (1), 60 (2), 65 (3), 70 (4), 75 (5), 78 (6), 85 (7), 92 (8).
Output (mapped to original order): [6, 8, 3, 7, 8, 4, 1, 7, 2, 5]
5. percentile_rank()
Explanation: Calculates the relative rank of an item as a percentage between 0 and 1. The standard formula is (Rank-1)/(N-1) (using the lowest rank for ties, known as the "min" ranking method).
Distinct Values Formula Bases: 55 (0/9), 60 (1/9), 65 (2/9), 70 (3/9), 75 (4/9), 78 (5/9), 85 (6/9), 92 (8/9).
Output (mapped to original order, rounded): [0.56, 0.89, 0.22, 0.67, 0.89, 0.33, 0.00, 0.67, 0.11, 0.44]

All the functions are verified and tested using the main.cpp file.