/*
 * Sort Array of 0s, 1s, and 2s - Better Approach (Counting Sort)
 * 
 * Problem: Given an array containing only 0s, 1s, and 2s, sort the array
 * in ascending order without using any sorting library.
 * 
 * Also known as: Dutch National Flag Problem (variant)
 * 
 * Algorithm: Counting Sort Approach
 * This is a two-pass algorithm:
 * 
 * Pass 1 - Count Phase:
 * - Traverse array and count occurrences of 0s, 1s, and 2s
 * - Store counts in separate variables
 * 
 * Pass 2 - Overwrite Phase:
 * - First, place all 0s from beginning
 * - Then, place all 1s after 0s
 * - Finally, place all 2s at the end
 * 
 * Advantages over Brute Force:
 * - More efficient than general sorting (O(n log n))
 * - Exploits the fact that there are only 3 distinct values
 * 
 * Limitation:
 * - Requires two complete passes through the array
 * - Not stable (original order of equal elements not preserved)
 * 
 * Time Complexity: O(2N) ≈ O(N) - Two passes through the array
 * Space Complexity: O(1) - Only using constant extra space
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array with 0s, 1s, and 2s in unsorted order
    // Expected output after sorting: 0 0 1 1 1 2 2 2
    int arr[] = {2, 1, 0, 0, 2, 1, 2, 1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // PASS 1: COUNT PHASE
    // Initialize counters to track frequency of each distinct value
    // These will store how many 0s, 1s, and 2s are in the array
    int countZeros = 0, countOnes = 0, countTwos = 0;

    // First traversal: Count occurrences of each value (0, 1, 2)
    // This gives us the frequency distribution
    for(int i = 0; i < n; i++)
    {
        // Check if current element is 0
        if(arr[i] == 0)
        {
            // Increment counter for 0s
            countZeros++;
        }
        // Check if current element is 1
        else if(arr[i] == 1)
        {
            // Increment counter for 1s
            countOnes++;
        }
        // Current element must be 2 (given only 0s, 1s, 2s exist)
        else
        {
            // Increment counter for 2s
            countTwos++;
        }
    }

    // PASS 2: OVERWRITE PHASE
    // Index pointer to track current position while placing elements
    // Will move from 0 to n-1 as we place sorted elements
    int index = 0;

    // Place all 0s at the beginning of the array
    // Loop runs countZeros times, placing 0 at each position
    while(countZeros--)
    {
        // Place 0 at current index and move to next position
        // Post-increment: use current index value, then increment it
        arr[index++] = 0;
    }

    // Place all 1s immediately after the 0s
    // Loop runs countOnes times, continuing from where 0s ended
    while(countOnes--)
    {
        // Place 1 at current index and move to next position
        arr[index++] = 1;
    }

    // Place all 2s at the end after 0s and 1s
    // Loop runs countTwos times, filling remaining positions
    while(countTwos--)
    {
        // Place 2 at current index and move to next position
        arr[index++] = 2;
    }

    // Display the sorted array
    // Range-based for loop: iterate through each element
    for(int x : arr)
    {
        // Print current element followed by a space
        cout << x << " ";
    }

    return 0;
}