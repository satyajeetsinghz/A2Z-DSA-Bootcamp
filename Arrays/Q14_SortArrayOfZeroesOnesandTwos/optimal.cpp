/*
 * Sort Array of 0s, 1s, and 2s - Optimal Approach (Dutch National Flag Algorithm)
 * 
 * Problem: Given an array containing only 0s, 1s, and 2s, sort the array
 * in ascending order in-place.
 * 
 * Also known as: Dutch National Flag Problem (proposed by Edsger Dijkstra)
 * Named after the three colors of the Dutch flag: red, white, and blue
 * 
 * Algorithm: Three-Way Partitioning using Three Pointers
 * 
 * Array is divided into 4 regions during processing:
 * [0...low-1]   -> All 0s (sorted)
 * [low...mid-1] -> All 1s (sorted)
 * [mid...high]  -> Unsorted (elements to be examined)
 * [high+1...n-1]-> All 2s (sorted)
 * 
 * Strategy:
 * - 'low' pointer marks the end of 0s region
 * - 'mid' pointer scans and examines elements
 * - 'high' pointer marks the start of 2s region
 * 
 * Rules:
 * - If arr[mid] == 0: Swap with low, increment both low and mid
 * - If arr[mid] == 1: It's in correct place, just increment mid
 * - If arr[mid] == 2: Swap with high, decrement high (don't move mid yet)
 * 
 * Why this is optimal:
 * - Single pass through array (O(N) time)
 * - In-place sorting (O(1) extra space)
 * - No counting phase needed
 * - Each element examined exactly once
 * 
 * Time Complexity: O(N) - Single traversal through array
 * Space Complexity: O(1) - Only using three pointer variables
 * 
 * This is the BEST approach for this problem.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array containing 0s, 1s, and 2s in unsorted order
    // Expected output after sorting: 0 0 0 1 1 1 2
    int arr[] = {1, 0, 0, 2, 1, 1, 0};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // THREE POINTERS for Dutch National Flag Algorithm:
    
    // 'low' pointer: Marks the position where next 0 should be placed
    // All elements before 'low' index are guaranteed to be 0s
    // Invariant: arr[0...low-1] contains only 0s
    int low = 0;
    
    // 'mid' pointer: Current element being examined/processed
    // This pointer scans through the array from left to right
    // Invariant: arr[low...mid-1] contains only 1s
    int mid = 0;
    
    // 'high' pointer: Marks the position where next 2 should be placed
    // All elements after 'high' index are guaranteed to be 2s
    // Invariant: arr[high+1...n-1] contains only 2s
    int high = n - 1;

    // Main loop: Process elements until mid crosses high
    // When mid > high, all elements have been examined and placed correctly
    while (mid <= high)
    {
        // CASE 1: Current element is 0 (belongs to leftmost section)
        if (arr[mid] == 0)
        {
            // Swap current element with element at 'low' position
            // This moves 0 to the correct region (beginning of array)
            swap(arr[low], arr[mid]);
            
            // Increment 'low' pointer to expand the 0s region
            // Now arr[0...low-1] contains all 0s
            low++;
            
            // Increment 'mid' pointer to examine next element
            // Safe to move mid because element at low was either 0 or 1
            // (we know it's not 2 because mid hasn't reached it yet)
            mid++;
        }

        // CASE 2: Current element is 1 (belongs to middle section)
        else if (arr[mid] == 1)
        {
            // Element is already in correct position (middle region)
            // No swap needed, just move to next element
            // This expands the 1s region naturally
            mid++;
        }

        // CASE 3: Current element is 2 (belongs to rightmost section)
        else
        {
            // Swap current element with element at 'high' position
            // This moves 2 to the correct region (end of array)
            swap(arr[mid], arr[high]);
            
            // Decrement 'high' pointer to expand the 2s region from right
            // Now arr[high+1...n-1] contains all 2s
            high--;
            
            // IMPORTANT: Don't increment 'mid' here!
            // The element we swapped from 'high' position is unseen
            // It could be 0, 1, or 2, so we need to examine it in next iteration
        }
    }

    // Display the sorted array
    // All 0s are at the beginning, then 1s, then 2s at the end
    for (int x : arr)
    {
        // Print each element followed by a space
        cout << x << " ";
    }

    return 0;
}