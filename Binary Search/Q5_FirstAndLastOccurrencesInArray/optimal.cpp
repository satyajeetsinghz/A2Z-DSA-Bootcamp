/*
 * First and Last Occurrences in a Sorted Array - Optimal Approach (Binary Search Variants)
 *
 * Problem: For a sorted array and a target value, find the index of the first (leftmost)
 * occurrence and the last (rightmost) occurrence of the target. If the target is not present,
 * return -1 for that occurrence.
 *
 * Also known as: Leftmost/Rightmost Index, Range Search
 *
 * Algorithm: Two modified Binary Searches (Boundary Finding)
 *
 * Key Idea:
 * - First occurrence (lower bound for equality): when arr[mid] == target, store mid and continue LEFT
 * - Last  occurrence (upper bound for equality): when arr[mid] == target, store mid and continue RIGHT
 *
 * Search Logic:
 * First Occurrence:
 *  - If arr[mid] == target: ans = mid; move high = mid - 1 (search earlier index)
 *  - If arr[mid]  < target: move low  = mid + 1 (target to the right)
 *  - If arr[mid]  > target: move high = mid - 1 (target to the left)
 *
 * Last Occurrence:
 *  - If arr[mid] == target: ans = mid; move low  = mid + 1 (search later index)
 *  - If arr[mid]  < target: move low  = mid + 1 (target to the right)
 *  - If arr[mid]  > target: move high = mid - 1 (target to the left)
 *
 * Why this is optimal:
 * - O(log N) time per search; overall O(log N) with two passes
 * - O(1) extra space
 * - Deterministic boundary discovery with minimal comparisons
 *
 * Time Complexity: O(log N) for each search
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

// Find first (leftmost) index of target; returns -1 if not present
int firstOccurrence(int arr[], int n, int target)
{
    // Inclusive boundaries and default answer
    int low = 0;
    int high = n - 1;
    int ans = -1;

    // Binary search for the left boundary
    while (low <= high)
    {
        // Safe mid calculation
        int mid = low + (high - low) / 2;

        // CASE 1: Found target; store and continue searching left half
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }

        // CASE 2: Current element smaller; target is to the right
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }

        // CASE 3: Current element larger; target is to the left
        else
        {
            high = mid - 1;
        }
    }

    // Leftmost index or -1
    return ans;
}

// Find last (rightmost) index of target; returns -1 if not present
int lastOccurrence(int arr[], int n, int target)
{
    // Inclusive boundaries and default answer
    int low = 0;
    int high = n - 1;
    int ans = -1;

    // Binary search for the right boundary
    while (low <= high)
    {
        // Safe mid calculation
        int mid = low + (high - low) / 2;

        // CASE 1: Found target; store and continue searching right half
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }

        // CASE 2: Current element smaller; target is to the right
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }

        // CASE 3: Current element larger; target is to the left
        else
        {
            high = mid - 1;
        }
    }

    // Rightmost index or -1
    return ans;
}

int main()
{
    // Sample sorted array with duplicates
    int arr[] = {1, 2, 3, 5, 5 , 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target value to locate range for
    int target = 5;

    // Compute first and last occurrences
    cout << "First Occurrence = " << firstOccurrence(arr, n, target) << endl;
    cout << "Last Occurrence  = " << lastOccurrence(arr, n, target);

    return 0;
}