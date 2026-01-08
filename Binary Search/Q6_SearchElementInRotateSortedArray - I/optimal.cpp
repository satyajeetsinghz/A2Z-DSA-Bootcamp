/*
 * Search Element in Rotated Sorted Array - Optimal Approach (Modified Binary Search)
 *
 * Problem: Given a sorted array that has been rotated at some pivot (unknown index),
 * search for a target element. If found, return its index; otherwise, return -1.
 *
 * Example: [4,5,6,7,0,1,2,3] is a rotated version of [0,1,2,3,4,5,6,7]
 *
 * Algorithm: Binary Search with Rotation Awareness
 *
 * Key Idea:
 * - In a rotated sorted array, at least one half (left or right of mid) is always sorted
 * - Identify which half is sorted by comparing arr[low] with arr[mid]
 * - Check if target lies in the sorted half's range
 * - If yes, search in that half; otherwise, search in the other half
 *
 * Search Logic:
 * 1. Calculate mid = low + (high - low) / 2
 * 2. If arr[mid] == target: return mid (found)
 * 3. Check which half is sorted:
 *    
 *    If LEFT half is sorted (arr[low] <= arr[mid]):
 *      - If target is in range [arr[low], arr[mid]): search left (high = mid - 1)
 *      - Otherwise: search right (low = mid + 1)
 *    
 *    If RIGHT half is sorted (arr[mid] <= arr[high]):
 *      - If target is in range (arr[mid], arr[high]]: search right (low = mid + 1)
 *      - Otherwise: search left (high = mid - 1)
 *
 * Why this is optimal:
 * - O(log N) time complexity - eliminates half the search space each iteration
 * - O(1) extra space
 * - Single pass binary search with rotation handling
 * - No need to find the pivot first (unlike two-step approaches)
 *
 * Time Complexity:  O(log N)
 * Space Complexity: O(1)
 */

#include <iostream>  // For input/output operations (cout)
using namespace std;

/**
 * Function: searchRotatedElement
 * Purpose: Searches for a target element in a rotated sorted array using modified binary search
 * 
 * Parameters:
 *   arr[]  - The rotated sorted array to search in
 *   n      - Size of the array (number of elements)
 *   target - The element we want to find in the array
 * 
 * Returns:
 *   int - Index of the target element if found, -1 if not found
 * 
 * Example: For arr = [4,5,6,7,0,1,2,3], target = 0, returns 4
 */
int searchRotatedElement(int arr[], int n, int target)
{
    int low = 0, high = n - 1;  // Initialize search boundaries: low = start index, high = end index

    // Continue searching while the search space is valid (low hasn't crossed high)
    while (low <= high)
    {
        // Calculate middle index (avoids integer overflow compared to (low+high)/2)
        int mid = low + (high - low) / 2;

        // Base case: If middle element is our target, we found it!
        if (arr[mid] == target)
        {
            return mid;  // Return the index where target is found
        }

        // Determine which half of the array is properly sorted
        // Check if LEFT HALF is sorted (compare leftmost with middle element)
        if (arr[low] <= arr[mid])
        {
            // Left half [low...mid] is sorted in ascending order
            
            // Check if target lies within the sorted left half's range
            // Target must be >= arr[low] AND < arr[mid] to be in left half
            if (arr[low] <= target && target < arr[mid])
            {
                // Target is in the left half, so eliminate right half
                high = mid - 1;  // Move high pointer to search left side
            }
            else
            {
                // Target is NOT in the left half, must be in right half
                low = mid + 1;  // Move low pointer to search right side
            }
        }
        else
        {
            // RIGHT HALF is sorted (since left half wasn't sorted, rotation point is in left)
            // Right half [mid...high] is sorted in ascending order
            
            // Check if target lies within the sorted right half's range
            // Target must be > arr[mid] AND <= arr[high] to be in right half
            if (arr[mid] < target && target <= arr[high])
            {
                // Target is in the right half, so eliminate left half
                low = mid + 1;  // Move low pointer to search right side
            }
            else
            {
                // Target is NOT in the right half, must be in left half
                high = mid - 1;  // Move high pointer to search left side
            }
        }
    }

    // If we exit the loop, target was not found in the array
    return -1;  // Return -1 to indicate target doesn't exist
}

/**
 * Function: main
 * Purpose: Driver function to test the searchRotatedElement function
 * Demonstrates searching for an element in a rotated sorted array
 */
int main()
{
    // Test array: Original sorted array [0,1,2,3,4,5,6,7] rotated at index 4
    int arr[] = {5, 6, 7, 8, 0, 1, 2, 3, 4};
    
    // Calculate number of elements in array (total bytes / bytes per element)
    int n = sizeof(arr) / sizeof(arr[0]);

    // The element we want to search for in the rotated array
    int target = 8;

    // Call the search function and store the result (index or -1)
    int index = searchRotatedElement(arr, n, target);

    // Check if element was found or not
    if (index == -1)
    {
        // Target not found in array
        cout << "Element does not exist";
    }
    else
    {
        // Target found, display its index position
        cout << "Element found at index: " << index;
    }

    return 0;  // Indicate successful program termination
}