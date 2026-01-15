/*
 * Squares of a Sorted Array (LeetCode Q977)
 *
 * Problem: Given a sorted array of integers (can contain negative numbers),
 * return an array of the squares of each number sorted in non-decreasing order.
 *
 * Approach (Two Pointers):
 * - Since the input array is sorted, the largest absolute values are at the ends
 *   (either the smallest negative or the largest positive).
 * - Use two pointers: left at index 0, right at index n-1.
 * - Compare absolute values at both ends: abs(arr[left]) vs abs(arr[right]).
 * - Square the larger absolute value and place it at the end of the result array.
 * - Move the corresponding pointer inward (left++ or right--).
 * - Fill the result array from right to left (position n-1 down to 0).
 *
 * Key Insight:
 * - Largest squares come from the largest absolute values, which are at the edges.
 * - By filling from right to left, we avoid needing to sort after squaring.
 * - This avoids the O(n log n) sorting that a naive square-then-sort approach would need.
 *
 * Example:
 * - Input: [-4, -2, 0, 1, 5, 8]
 * - Output: [0, 1, 4, 16, 25, 64]
 * - Process: Compare abs(-4)=4 vs abs(8)=8 → square 8 → place 64
 *            Compare abs(-4)=4 vs abs(5)=5 → square 5 → place 25, etc.
 *
 * Complexity:
 * - Time: O(n) single pass through the array
 * - Space: O(n) for the result array (O(1) extra space for pointers)
 */

#include <iostream>
using namespace std;

// Function to compute squares of sorted array and return them in sorted order
// Parameters: arr[] - input sorted array, n - size of array, results[] - output array
void sortedSquares(int arr[], int n, int results[])
{
    int left = 0;       // Pointer starting from the leftmost element
    int right = n - 1;  // Pointer starting from the rightmost element
    int pos = n - 1;    // Position to fill in results array (from right to left)    // Position to fill in results array (from right to left)

    // Process elements from both ends towards the center
    while (left <= right)
    {
        // If left element has larger absolute value, square it and place in results
        if (abs(arr[left]) > abs(arr[right]))
        {
            results[pos] = arr[left] * arr[left];  // Square the left element
            left++;  // Move left pointer forward  // Move left pointer forward
        }
        // If right element has larger or equal absolute value, square it and place in results
        else
        {
            results[pos] = arr[right] * arr[right];  // Square the right element
            right--;  // Move right pointer backward  // Move right pointer backward
        }

        pos--;  // Move to next position (towards left) in results array
    }
}

int main()
{
    // Test case: sorted array with negative and positive numbers
    int arr[] = {-4, -2, 0, 1, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate number of elements

    int results[n];  // Array to store sorted squares
    sortedSquares(arr, n, results);  // Call function to compute sorted squares  // Call function to compute sorted squares

    // Display the results
    cout << "Sorted Squares are: [";
    for (int i = 0; i < n; i++)  // Iterate through results array
    {
        cout << results[i] << " ";  // Print each squared value
    }
    cout << "]";

    return 0;  // Exit program successfully
}