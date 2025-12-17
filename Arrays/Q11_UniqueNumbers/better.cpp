/*
 * Find Unique Numbers - Better Approach using Map (Frequency Counter)
 * 
 * Problem: Given an array of integers where some numbers appear multiple times,
 * find all numbers that appear exactly once (unique numbers).
 * 
 * Algorithm: Frequency Counter using Map
 * 
 * Strategy:
 * 1. Count frequency of each element using a map
 * 2. Traverse the map and print elements with frequency = 1
 * 
 * Why Map (not unordered_map):
 * - map stores elements in sorted order (ordered by keys)
 * - Provides sorted output automatically
 * - O(log N) insertion but acceptable for this use case
 * 
 * Map Structure:
 * - Key: The array element
 * - Value: Frequency/count of that element
 * - Example: {1: 2, 2: 2, 3: 2, 5: 1} means 5 appears once
 * 
 * Advantages:
 * - Clear and readable approach
 * - Works with any data type
 * - Automatically handles counting logic
 * 
 * Time Complexity: O(N log N) - N insertions with O(log N) each + traversal
 * Space Complexity: O(K) - K is number of unique elements in array
 * 
 * Note: For unsorted output with O(1) insertion, use unordered_map instead.
 */

#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Sample input array with duplicate and unique elements
    // Elements: 1 appears twice, 2 twice, 3 twice, 5 once (unique)
    int arr[] = {1, 2, 3, 2, 1, 5, 3};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // PHASE 1: Build Frequency Map
    
    // Create a map to store frequency count for each element
    // Key: array element, Value: count of occurrences
    // map automatically keeps keys in sorted order
    map<int, int> freq;

    // First pass: Count frequency of each element
    // Traverse array and increment count for each element
    for (int i = 0; i < n; i++)
    {
        // Increment frequency of current element
        // If element doesn't exist in map, it's auto-initialized to 0, then incremented
        // Example: freq[1]++ means count how many times 1 appears
        freq[arr[i]]++;
    }

    // PHASE 2: Find and Display Unique Elements
    
    // Traverse the frequency map to find unique elements
    // 'auto' deduces type as pair<int, int> (key-value pair)
    // x.first = element value (key), x.second = frequency (value)
    for (auto x : freq)
    {
        // Check if current element appears exactly once
        // x.second == 1 means frequency is 1 (unique element)
        if (x.second == 1)
        {
            // Found a unique number - display it
            // x.first contains the actual element value
            cout << "Unique number is: " << x.first << endl;
        }
    }
    
    return 0;
}