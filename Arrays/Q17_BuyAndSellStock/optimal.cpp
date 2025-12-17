/*
 * Best Time to Buy and Sell Stock - Optimal Approach
 * 
 * Problem: Given an array where arr[i] represents the stock price on day i,
 * find the maximum profit by buying on one day and selling on a future day.
 * If no profit is possible, return 0.
 * 
 * Algorithm: Single Pass - Kadane's Algorithm Variant
 * - Keep track of the minimum price seen so far (best buy price)
 * - For each day, calculate profit if we sell today after buying at min price
 * - Track the maximum profit throughout the traversal
 * 
 * Key Insight: To maximize profit, we should buy at the lowest price before
 * the current day and sell at the current day's price.
 * 
 * Time Complexity: O(N) - Single traversal through the array
 * Space Complexity: O(1) - Only using constant extra space
 */

#include <iostream>
using namespace std;

int main()
{
    // Sample input: Stock prices for each day
    // Example: Day 0 = $7, Day 1 = $1, Day 2 = $5, Day 3 = $3, Day 4 = $6, Day 5 = $4
    int arr[] = {7, 1, 5, 3, 6, 4};
    
    // Calculate the total number of days (array size)
    int n = sizeof(arr) / sizeof(arr[0]);

    // Track the minimum stock price encountered so far
    // Initialize with first day's price as we haven't seen any other prices yet
    int minPrice = arr[0];
    
    // Track the maximum profit achievable
    // Initialize to 0 because if we don't find any profitable transaction, profit is 0
    int maxProfit = 0;

    // Iterate through each day starting from day 1 (index 1)
    // We start from day 1 because we need at least one previous day to buy from
    for (int i = 1; i < n; i++)
    {
        // Update the minimum price if current day's price is lower
        // This represents the best buying opportunity we've seen so far
        minPrice = min(minPrice, arr[i]);
        
        // Calculate the profit if we sell on the current day
        // Profit = Selling Price (today) - Buying Price (minimum price before today)
        int profit = arr[i] - minPrice;
        
        // Update maximum profit if current profit is greater
        // This ensures we always keep track of the best transaction possible
        maxProfit = max(maxProfit, profit);
    }

    // Display the maximum profit that can be achieved
    // If maxProfit is 0, it means no profitable transaction was possible
    cout << "Maximum Profit is: " << maxProfit;

    return 0;
}