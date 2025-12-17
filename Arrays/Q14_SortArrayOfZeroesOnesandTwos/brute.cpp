/*
 * Sort Array of 0s, 1s, and 2s - Brute Force Approach
 * 
 * Problem: Given an array containing only 0s, 1s, and 2s, sort the array
 * in ascending order.
 * 
 * Also known as: Dutch National Flag Problem
 * 
 * Algorithm: Standard Library Sort
 * - Use built-in sorting algorithm (typically Introsort: hybrid of QuickSort, HeapSort, InsertionSort)
 * - Directly applies general-purpose sorting to the array
 * - Simple one-line solution but not optimal for this specific problem
 * 
 * Why "Brute Force":
 * - Doesn't exploit the constraint that array has only 3 distinct values (0, 1, 2)
 * - Uses general sorting which is overkill for this limited value range
 * - More efficient solutions exist that take advantage of the problem constraints
 * 
 * Drawbacks:
 * - Slower than specialized algorithms for this problem
 * - Doesn't leverage the limited number of distinct values
 * - Time complexity is worse than optimal O(N) solutions
 * 
 * Time Complexity: O(N log N) - General comparison-based sorting
 * Space Complexity: O(log N) - Recursion stack space used by sorting algorithm
 * 
 * Note: While this works correctly, better approaches (counting sort or Dutch flag)
 * can solve this in O(N) time with O(1) space.
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Sample input array containing only 0s, 1s, and 2s in random order
    // Expected output after sorting: 0 0 0 1 1 1 2 2 2
    int arr[] = {1, 0, 0, 1, 2, 2, 0, 2, 1};
    
    // Calculate the total number of elements in the array
    // sizeof(arr) gives total bytes, divided by bytes per element
    int n = sizeof(arr) / sizeof(arr[0]);

    // Apply standard library sort function (brute force approach)
    // sort() uses Introsort algorithm (hybrid sorting with O(N log N) complexity)
    // Parameters: start pointer (arr), end pointer (arr + n)
    // Sorts elements in ascending order: 0s first, then 1s, then 2s
    sort(arr, arr + n);

    // Display the sorted array
    // Range-based for loop: automatically iterates through each element
    for (int x : arr)
    {
        // Print current element followed by a space
        cout << x << " ";
    }

    return 0;
}