/*
 * Find Unique Numbers - Brute Force Approach
 * 
 * Problem: Given an array of integers where some numbers appear multiple times,
 * find numbers that appear exactly once (unique numbers).
 * 
 * Algorithm: Nested Loop - Count and Compare
 * - For each element, count how many times it appears in the entire array
 * - If count equals 1, that element is unique
 * - Print the unique element and exit
 * 
 * Approach:
 * - Outer loop selects each element as a candidate
 * - Inner loop counts occurrences of that candidate in the entire array
 * - Check if count is exactly 1
 * 
 * Drawbacks:
 * - Inefficient due to nested loops
 * - Counts same element multiple times if it appears at different positions
 * - Early exit finds only the FIRST unique element (may miss others)
 * - No optimization for already-counted elements
 * 
 * Time Complexity: O(N²) - Nested loops where each element is compared with all others
 * Space Complexity: O(1) - Only using constant extra space
 * 
 * Note: Better approaches exist using hash maps or sets with O(N) time complexity.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array with duplicate and unique elements
    // Elements: 1 appears twice, 2 appears twice, 3 appears once (unique)
    int arr[] = {1, 2, 3, 2, 1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Outer loop: Select each element as a candidate to check if it's unique
    // Examine every element from index 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // Initialize counter to track occurrences of current candidate element
        // Reset to 0 for each new candidate we're testing
        int count = 0;
        
        // Inner loop: Count how many times the current candidate (arr[i]) appears
        // Scan the entire array to count all occurrences of arr[i]
        for (int j = 0; j < n; j++)
        {
            // Compare each element in the array with our current candidate
            if (arr[i] == arr[j])
            {
                // Found a match (including the element itself at position i)
                // Increment the occurrence counter
                count++;
            }
        }

        // Check if current candidate appears exactly once in the array
        // count == 1 means the element is unique (no duplicates)
        if (count == 1)
        {
            // Found a unique number - display it
            cout << "Unique number is: " << arr[i];
            
            // Exit after finding the first unique number
            // Note: This means we won't find other unique numbers if they exist
            break;
        }
    }

    return 0;
}