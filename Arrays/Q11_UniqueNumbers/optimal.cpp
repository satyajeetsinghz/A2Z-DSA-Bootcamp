/*
 * Find Unique Number - Optimal Approach using XOR (Bit Manipulation)
 * 
 * Problem: Given an array where every element appears exactly twice except
 * one element that appears exactly once, find the unique element.
 * 
 * IMPORTANT CONSTRAINT: This approach assumes:
 * - All elements appear exactly TWICE except ONE element that appears ONCE
 * - Won't work if multiple elements appear odd number of times
 * 
 * Algorithm: XOR Bit Manipulation
 * 
 * Key Properties of XOR (^):
 * 1. a ^ a = 0 (any number XOR with itself equals 0)
 * 2. a ^ 0 = a (any number XOR with 0 equals itself)
 * 3. XOR is commutative: a ^ b = b ^ a
 * 4. XOR is associative: (a ^ b) ^ c = a ^ (b ^ c)
 * 
 * Strategy:
 * - XOR all elements together
 * - Duplicate pairs cancel out to 0 (property 1)
 * - Only the unique element remains (property 2)
 * 
 * Example: [1, 2, 3, 2, 1]
 * Step 1: 0 ^ 1 = 1
 * Step 2: 1 ^ 2 = 3
 * Step 3: 3 ^ 3 = 0 (cancels out)
 * Step 4: 0 ^ 2 = 2
 * Step 5: 2 ^ 1 = 3 (final answer - the unique element)
 * 
 * Why this is optimal:
 * - Single pass through array
 * - No extra space for data structures
 * - Constant time operations (XOR is O(1))
 * 
 * Time Complexity: O(N) - Single traversal through the array
 * Space Complexity: O(1) - Only one variable used
 * 
 * This is the MOST OPTIMAL approach for this specific problem variant.
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input array where all elements appear twice except one
    // Elements: 1 twice, 2 twice, 3 once (unique)
    // XOR result: 1^2^3^2^1 = (1^1)^(2^2)^3 = 0^0^3 = 3
    int arr[] = {1, 2, 3, 2, 1};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize result variable to 0
    // This is our accumulator for XOR operations
    // Starting with 0 because: any_number ^ 0 = any_number
    int ans = 0;

    // Single pass: XOR all elements together
    // Duplicate elements will cancel out (a ^ a = 0)
    // Only the unique element will remain
    for (int i = 0; i < n; i++)
    {
        // XOR current element with accumulated result
        // ans ^= arr[i] is equivalent to: ans = ans ^ arr[i]
        // 
        // How it works:
        // - First occurrence of a number: gets XORed into ans
        // - Second occurrence of same number: XORs again, canceling to 0
        // - Unique element: XORed once, remains in the result
        ans ^= arr[i];
    }

    // Display the unique number
    // After XORing all elements, ans contains only the unique element
    // All pairs have canceled out to 0
    cout << "Unique number is: " << ans;

    return 0;
}