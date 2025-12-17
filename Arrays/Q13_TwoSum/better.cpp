/*
 * Two Sum Problem - Better Approach using Hash Set
 * 
 * Problem: Given an array of integers and a target sum, find if there exist
 * two numbers in the array that add up to the target.
 * Return the pair if found, otherwise indicate no pair exists.
 * 
 * Algorithm: Hash Set (Complement Search)
 * Key Insight: For each number x, check if (target - x) exists in the array
 * 
 * Approach:
 * - Traverse array and for each element, calculate the complement needed
 * - Check if complement exists in the hash set of previously seen numbers
 * - If found: We have our pair (current element + complement = target)
 * - If not found: Add current element to hash set for future lookups
 * 
 * Why Hash Set:
 * - O(1) average-case lookup time to check if complement exists
 * - O(1) insertion time to add elements
 * - Only stores unique values we've seen so far
 * 
 * Advantages over Brute Force:
 * - Single pass through array instead of nested loops
 * - Trade space for time: uses extra memory for significant speed gain
 * 
 * Time Complexity: O(N) - Single traversal with O(1) hash set operations
 * Space Complexity: O(N) - Hash set stores up to N elements in worst case
 */

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // Sample input array to search for two sum
    // In this example: 5 + 7 = 12 (target)
    int arr[] = {1, 3, 5, 7};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Target sum we're trying to achieve with two numbers
    int target = 12;

    // Create a hash set to store numbers we've already encountered
    // This allows O(1) lookup to check if a complement exists
    // unordered_set provides average O(1) insertion and search
    unordered_set<int> seen_number;

    // Traverse through each element in the array
    for (int i = 0; i < n; i++)
    {
        // Calculate the complement: the number needed to reach target
        // If current element is x, we need (target - x) to make the sum
        int needed = target - arr[i];

        // Check if the needed complement exists in our seen numbers
        // find() returns end() iterator if element is not found
        if (seen_number.find(needed) != seen_number.end())
        {
            // Found the pair! The complement was seen earlier in the array
            // Current element (arr[i]) + needed = target
            cout << "Pair: " << arr[i] << " and " << needed << endl;
            
            // Exit immediately as we found a valid pair
            return 0;
        }

        // Complement not found yet, add current element to hash set
        // This element might be needed as a complement for future elements
        seen_number.insert(arr[i]);
    }

    // Traversed entire array without finding a valid pair
    // No two numbers sum up to the target
    cout << "No pair found.";
    
    return 0;
}