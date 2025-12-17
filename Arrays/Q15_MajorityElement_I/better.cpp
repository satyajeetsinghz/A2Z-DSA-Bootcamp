/*
 * Majority Element - Better Approach using Hash Map
 * 
 * Problem: Find the element that appears more than n/2 times in the array.
 * A majority element ALWAYS exists in the given input (guaranteed by problem).
 * 
 * Definition: Majority element appears strictly more than ⌊n/2⌋ times
 * Example: In array of size 8, element must appear at least 5 times
 * 
 * Algorithm: Hash Map Frequency Counter with Early Detection
 * - Use hash map to count frequency of each element as we traverse
 * - Check after each insertion if current element's count exceeds n/2
 * - Return immediately when majority element is found
 * - Early detection optimization avoids processing entire array
 * 
 * Advantages over Brute Force:
 * - Single pass instead of nested loops
 * - Early termination when majority is found
 * 
 * Time Complexity: O(N) - Single traversal with O(1) hash map operations
 * Space Complexity: O(N) - Hash map stores up to N unique elements in worst case
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    // Sample input array where we need to find majority element
    // In this array: 2 appears 5 times out of 8 (more than 8/2 = 4)
    int arr[] = {1, 2, 2, 1, 4, 2, 2, 2};

    // Calculate total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a hash map to store frequency count for each element
    // Key: array element, Value: count of occurrences
    // unordered_map provides O(1) average case insertion and lookup
    unordered_map<int, int> mp;

    // Traverse the array to count frequencies and detect majority element
    // We check for majority during traversal for early termination
    for(int i = 0; i < n; i++)
    {
        // Increment the frequency count for current element
        // If element doesn't exist in map, it's auto-initialized to 0, then incremented
        mp[arr[i]]++;

        // Check if current element has now become the majority element
        // Majority means: frequency > n/2 (strictly greater, not equal)
        if(mp[arr[i]] > n / 2)
        {
            // Found the majority element - print and exit immediately
            // Early exit optimization: no need to process remaining elements
            cout << "Majority element is: " << arr[i];
            return 0;
        }
    }

    // This line executes only if no majority element was found
    // Note: In standard problem, majority element is guaranteed to exist
    cout << "No Majority Elements found.";

    return 0;
}