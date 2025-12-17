/*
 * Two Sum Problem - Brute Force Approach
 * 
 * Problem: Given an array of integers and a target sum, find if there exist
 * two numbers in the array that add up to the target.
 * Return the pair if found, otherwise indicate no pair exists.
 * 
 * Algorithm: Nested Loop - Exhaustive Search
 * - Check every possible pair of elements in the array
 * - Outer loop selects first element of the pair
 * - Inner loop selects second element of the pair
 * - Compare sum of each pair with target
 * 
 * Approach:
 * - For each element at index i, check all elements after it (index j where j > i)
 * - This ensures we don't use the same element twice
 * - This also avoids checking duplicate pairs (e.g., (i,j) and (j,i))
 * 
 * Drawbacks:
 * - Inefficient for large arrays due to nested loops
 * - Checks every possible combination even when unnecessary
 * - No optimization or early termination beyond finding first pair
 * 
 * Time Complexity: O(N²) - Nested loops checking all pairs
 * Space Complexity: O(1) - Only using constant extra space
 * 
 * Note: While simple to understand, better approaches exist using hash maps
 * that can solve this in O(N) time.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array to search for two sum
    // In this example: 7 + 9 = 16 (target)
    int arr[] = {1, 3, 5, 7, 9};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Target sum we're trying to achieve with two numbers from the array
    int target = 16;

    // Brute Force: Check all possible pairs using nested loops
    
    // Outer loop: Select the first element of the pair
    // Iterate through each element as a potential first element
    for (int i = 0; i < n; i++)
    {
        // Inner loop: Select the second element of the pair
        // Start from i+1 to avoid using the same element twice
        // Also prevents checking duplicate pairs (e.g., pair (0,1) and (1,0))
        for (int j = i + 1; j < n; j++)
        {
            // Check if the sum of current pair equals the target
            // arr[i] is the first element, arr[j] is the second element
            if (arr[i] + arr[j] == target)
            {
                // Found a valid pair that sums to target
                // Display the pair and exit immediately
                cout << "Pair is: " << "[" << arr[i] << ", " << arr[j] << "]";
                
                // Return early as we found what we're looking for
                return 0;
            }
        }
    }

    // Checked all possible pairs without finding a match
    // No two elements in the array sum up to the target
    cout << "Pair is not found.";
    
    return 0;
}