/*
 * Next Permutation Algorithm
 * 
 * Problem: Given an array of integers, rearrange the numbers to get 
 * the lexicographically next greater permutation.
 * 
 * Algorithm Steps:
 * 1. Find the break point from right where arr[i] < arr[i+1]
 * 2. If no break point exists, array is in descending order (last permutation)
 * 3. Find the smallest element from right that is greater than arr[idx]
 * 4. Swap these elements
 * 5. Reverse/Sort the elements after idx to get the smallest arrangement
 * 
 * Time Complexity: O(3N) ≈ O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Sample input array to find next permutation
    int arr[] = {1, 2, 3, 4, 5};
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Variable to store the break point index
    // Initialize to -1 to handle the case when array is in descending order
    int idx = -1;

    // STEP 1: Find the break point from right to left
    // We need to find the first index where arr[i] < arr[i+1]
    // This is the pivot point where we need to make the change
    for (int i = n - 2; i >= 0; i--)
    {
        // Check if current element is smaller than the next element
        if (arr[i] < arr[i + 1])
        {
            // Store the index of break point
            idx = i;
            break;
        }
    }

    // STEP 2: Check if break point was found
    // If idx is still -1, it means array is in descending order
    // This is the last permutation, so we need to return the first permutation
    if (idx == -1)
    {
        // Sort the entire array in ascending order to get the first permutation
        sort(arr, arr + n);
    }
    // STEP 3: If break point exists, find the next permutation
    else
    {
        // Find the smallest element from right that is greater than arr[idx]
        // We traverse from right to left to find the immediate next greater element
        for (int i = n - 1; i > idx; i--)
        {
            // Check if current element is greater than element at break point
            if (arr[i] > arr[idx])
            {
                // Swap the elements to place the next greater element at break point
                swap(arr[i], arr[idx]);
                
                // Break after first swap as we found the immediate next greater element
                break;
            }
        }

        // STEP 4: Reverse the elements after idx position
        // This ensures we get the smallest lexicographical arrangement
        // The elements after idx are in descending order, reversing makes them ascending
        reverse(arr + idx + 1, arr + n);
    }

    // Print the next permutation
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}