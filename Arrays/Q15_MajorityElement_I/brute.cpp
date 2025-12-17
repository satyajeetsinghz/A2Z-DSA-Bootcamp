/*
 * Majority Element - Brute Force Approach
 * 
 * Problem: Find the element that appears more than n/2 times in the array.
 * A majority element is guaranteed to exist in the given input.
 * 
 * Definition: Majority element appears strictly more than ⌊n/2⌋ times
 * Example: In array of size 8, element must appear at least 5 times to be majority
 * 
 * Algorithm: Nested Loop - Count and Compare
 * - For each element, count how many times it appears in the entire array
 * - If count exceeds n/2, that element is the majority element
 * - Return immediately when majority element is found
 * 
 * Drawbacks:
 * - Inefficient due to nested loops
 * - Counts same element multiple times if it appears at different positions
 * - No optimization or early termination for duplicate checks
 * 
 * Time Complexity: O(N²) - Nested loops where each element is compared with all others
 * Space Complexity: O(1) - Only using constant extra space (count variable)
 */

#include <iostream>

using namespace std;

int main()
{
    // Sample input array to find the majority element
    // In this array: 2 appears 5 times out of 8 total elements (5 > 8/2 = 4)
    // So, 2 is the majority element
    int arr[] = {1, 2, 2, 1, 4, 2, 2, 2};

    // Calculate the total number of elements in the array
    // sizeof(arr) gives total bytes, divide by bytes per element
    int n = sizeof(arr) / sizeof(arr[0]);

    // Outer loop: Select each element as a candidate to check if it's the majority
    // We examine every element from index 0 to n-1
    for (int i = 0; i < n; i++)
    {
        // Initialize counter to track occurrences of current candidate element
        // Reset to 0 for each new candidate we're testing
        int count = 0;

        // Inner loop: Count how many times the current candidate (arr[i]) appears
        // We scan the entire array to count all occurrences of arr[i]
        for (int j = 0; j < n; j++)
        {
            // Compare each element in the array with our current candidate
            if (arr[j] == arr[i])
            {
                // Found a match - increment the occurrence counter
                count++;
            }
        }

        // Check if current candidate's count exceeds the majority threshold
        // Majority means: strictly greater than n/2 (not equal to n/2)
        // Example: For n=8, we need count > 4, meaning at least 5 occurrences
        if (count > n / 2)
        {
            // Found the majority element - display it with its occurrence count
            // Exit immediately as we found what we were looking for
            cout << "Majority Element: " << arr[i] << " appeared " << count << " times.";
            return 0;
        }
    }

    // This line executes only if no element exceeded n/2 occurrences
    // Note: In standard problem definition, majority element is guaranteed to exist
    cout << "No Majority Element found.";

    return 0;
}