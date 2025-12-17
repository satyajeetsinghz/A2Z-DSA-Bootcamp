/*
 * Longest Subarray with Sum K - Better Approach using Prefix Sum & Hash Map
 * 
 * Problem: Given an array of integers (positive and negative) and a target sum K,
 * find the length of the longest contiguous subarray that sums to K.
 * 
 * Algorithm: Prefix Sum with Hash Map
 * 
 * Key Concept - Prefix Sum:
 * prefixSum[i] = sum of all elements from index 0 to i
 * 
 * Core Insight:
 * If we have prefixSum at index j and we want subarray sum = K ending at j,
 * we need to find if there exists an index i where:
 * prefixSum[j] - prefixSum[i-1] = K
 * Which means: prefixSum[i-1] = prefixSum[j] - K
 * 
 * So we look for (currentPrefixSum - K) in our hash map!
 * 
 * Strategy:
 * 1. Calculate prefix sum while traversing the array
 * 2. Store each prefix sum with its first occurrence index in hash map
 * 3. For each position, check if (currentPrefixSum - K) exists in map
 * 4. If exists, we found a subarray with sum K
 * 5. Calculate its length and track maximum length
 * 
 * Why Hash Map:
 * - O(1) lookup to check if a prefix sum exists
 * - Stores first occurrence index for maximum length calculation
 * 
 * When to use:
 * - Array has both positive AND negative numbers
 * - For only positive numbers, sliding window (optimal.cpp) is better
 * 
 * Time Complexity: O(N) - Single traversal with O(1) hash map operations
 * Space Complexity: O(N) - Hash map stores up to N prefix sums
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // Sample input array (can have positive, negative, or zero)
    // Subarray [2, -1, 2, 3] has sum = 6 and length = 4
    int arr[] = {1, 2, -1, 2, 3, 1, -2};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Target sum we're looking for in contiguous subarrays
    int k = 6;

    // Hash map to store prefix sums and their first occurrence indices
    // Key: prefix sum value
    // Value: index where this prefix sum first occurred
    unordered_map<int, int> prefixSumMap;

    // Variable to track the cumulative sum (prefix sum) as we traverse
    int prefixSum = 0;
    
    // Variable to track the maximum length of subarray with sum K
    int maxLen = 0;

    // Traverse through each element of the array
    for (int i = 0; i < n; i++)
    {
        // Add current element to prefix sum
        // prefixSum now represents sum of elements from index 0 to i
        prefixSum += arr[i];

        // CASE 1: Check if prefix sum itself equals K
        // This means subarray from index 0 to i has sum = K
        if (prefixSum == k)
        {
            // Length is from start to current position (i + 1 elements)
            maxLen = max(maxLen, i + 1);
        }

        // CASE 2: Check if (prefixSum - K) exists in hash map
        // If prefixSum - K exists at some earlier index, it means:
        // Sum from that index+1 to current index = K
        // Because: currentPrefixSum - previousPrefixSum = subarraySum
        int requiredSum = prefixSum - k;
        
        if (prefixSumMap.find(requiredSum) != prefixSumMap.end())
        {
            // Found a subarray with sum K
            // Calculate length: from (previousIndex + 1) to currentIndex
            int previousIndex = prefixSumMap[requiredSum];
            int length = i - previousIndex;
            
            // Update maximum length if current length is larger
            maxLen = max(maxLen, length);
        }

        // Store current prefix sum in hash map ONLY if it doesn't exist
        // We keep the FIRST occurrence to maximize subarray length
        // (We want the earliest index for a given prefix sum)
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end())
        {
            // Store prefix sum with current index
            prefixSumMap[prefixSum] = i;
        }
    }

    // Display the length of longest subarray with sum K
    cout << "Longest subarray length with sum " << k << " is: " << maxLen;

    return 0;
}