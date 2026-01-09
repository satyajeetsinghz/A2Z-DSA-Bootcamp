/*
 * Monotonic Array (LeetCode Q896)
 *
 * Problem: Check if an array is monotonic increasing, monotonic decreasing,
 * or both (constant array). A monotonic increasing array has arr[i] <= arr[i+1]
 * for all valid i. A monotonic decreasing array has arr[i] >= arr[i+1] for all valid i.
 *
 * Approach (Single Pass, Track Two Flags):
 * - Initialize two boolean flags: `inc` (for increasing) and `dec` (for decreasing).
 * - Scan once through the array starting from index 1.
 * - If arr[i] < arr[i-1], then the array cannot be monotonic increasing, set inc = false.
 * - If arr[i] > arr[i-1], then the array cannot be monotonic decreasing, set dec = false.
 * - Return true if the array is either monotonic increasing (inc = true) or
 *   monotonic decreasing (dec = true) or both (constant array).
 *
 * Key Insight:
 * - An array is monotonic if it is either non-decreasing (inc) OR non-increasing (dec).
 * - We eliminate both possibilities only if we see both an increase and a decrease.
 * - Edge cases: Single element and constant arrays are both increasing and decreasing.
 *
 * Notes:
 * - Works with duplicates: [1, 2, 2, 3] is monotonic increasing.
 * - [5, 5, 5] is monotonic (both increasing and decreasing).
 * - Returns true only if at least one flag remains true after the scan.
 *
 * Complexity:
 * - Time: O(n) single pass through the array
 * - Space: O(1) constant extra space, only two boolean flags
 */

#include <iostream>
using namespace std;

// Function to check if array is monotonic
// Returns true if array is monotonic increasing OR monotonic decreasing
bool isMonotonic(int arr[], int n)
{
    // Flags to track if array is monotonic increasing and decreasing
    bool inc = true; // assume array is monotonic increasing
    bool dec = true; // assume array is monotonic decreasing

    // Single pass to check for violations of either property
    for (int i = 1; i < n; i++)
    {
        // If current element is less than previous, cannot be increasing
        if (arr[i] < arr[i - 1])
            inc = false;

        // If current element is greater than previous, cannot be decreasing
        if (arr[i] > arr[i - 1])
            dec = false;
    }

    // Return true if array is either monotonic increasing or decreasing
    return inc || dec;
}

int main()
{
    // Test case 1: monotonic increasing array => should return true
    int arr1[] = {1, 2, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Test case 2: neither increasing nor decreasing => should return false
    int arr2[] = {1, 2, 5, 6, 3, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Check arr1 (monotonic increasing)
    int res1 = isMonotonic(arr1, n1);
    cout << "Test 1 - Array [1, 2, 2, 3, 4]: ";
    if (res1)
        cout << "Monotonic (Increasing)" << endl;
    else
        cout << "Not Monotonic" << endl;

    // Check arr2 (neither increasing nor decreasing)
    int res2 = isMonotonic(arr2, n2);
    cout << "Test 2 - Array [1, 2, 5, 3, 4]: ";
    if (res2)
        cout << "Monotonic" << endl;
    else
        cout << "Not Monotonic" << endl;

    return 0;
}