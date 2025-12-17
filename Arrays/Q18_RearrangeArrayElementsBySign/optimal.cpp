/*
 * Rearrange Array Elements by Sign - Optimal Approach
 * 
 * Problem: Given an array of positive and negative integers (equal count),
 * rearrange them alternately starting with a positive number.
 * 
 * Approach: Two-pointer technique
 * - Use one pointer for even indices (0, 2, 4...) for positive numbers
 * - Use another pointer for odd indices (1, 3, 5...) for negative numbers
 * - Single pass through the array placing elements at correct positions
 * 
 * Time Complexity: O(N) - Single traversal through the array
 * Space Complexity: O(N) - Additional array to store rearranged elements
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array with equal number of positive and negative integers
    int arr[] = {3, 1, -2, -5, -2, 4};
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a new array to store the rearranged elements
    int ans[n];
    
    // Index pointer for positive numbers - starts at 0 (even positions)
    // Positive numbers will be placed at indices: 0, 2, 4, 6, ...
    int posIndex = 0;
    
    // Index pointer for negative numbers - starts at 1 (odd positions)
    // Negative numbers will be placed at indices: 1, 3, 5, 7, ...
    int negIndex = 1;

    // Traverse through the entire array once
    for (int i = 0; i < n; i++)
    {
        // Check if current element is positive or zero
        if (arr[i] >= 0)
        {
            // Place positive number at current even index
            ans[posIndex] = arr[i];
            
            // Move to next even index (skip one position)
            posIndex += 2;
        }
        // Current element is negative
        else
        {
            // Place negative number at current odd index
            ans[negIndex] = arr[i];
            
            // Move to next odd index (skip one position)
            negIndex += 2;
        }
    }

    // Display the result
    cout << "Rearranged Array Elements: ";

    // Print all elements of the rearranged array
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}