/*
 * Majority Element - Optimal Approach (Boyer-Moore Voting Algorithm)
 * 
 * Problem: Find the element that appears more than n/2 times in the array.
 * 
 * Algorithm: Boyer-Moore Majority Voting Algorithm
 * This is a two-phase algorithm:
 * 
 * Phase 1 - Find Candidate:
 * - Maintain a candidate and a vote counter
 * - When count is 0, select current element as new candidate
 * - If element matches candidate, increment count (vote for it)
 * - If element differs from candidate, decrement count (vote against it)
 * 
 * Phase 2 - Verify Candidate:
 * - Count actual occurrences of the candidate
 * - Verify if it appears more than n/2 times
 * 
 * Why This Works:
 * - If a majority element exists (appears > n/2 times), it will survive
 * - The pairing/cancellation process ensures non-majority elements cancel out
 * - The majority element has enough occurrences to remain as final candidate
 * 
 * Intuition: Think of it as a voting battle where different elements cancel
 * each other out. The element with majority will always have votes remaining.
 * 
 * Time Complexity: O(N) - Two passes through the array
 * Space Complexity: O(1) - Only using constant extra space
 * 
 * Best approach among all: Uses minimal space while being efficient
 */

#include <iostream>
using namespace std;

int main() {
    // Sample input array to find majority element
    // In this array: 2 appears 5 times out of 7 total (5 > 7/2 = 3.5)
    int arr[] = {2, 2, 1, 2, 3, 2, 2};
    
    // Calculate the total number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // PHASE 1: Find the potential majority candidate using voting
    
    // Vote counter: tracks the "strength" of current candidate
    // Positive count = candidate is winning, Zero = need new candidate
    int count = 0;
    
    // Variable to store the current candidate for majority element
    // Initialized to -1 (will be set when count becomes 0)
    int candidate = -1;

    // First pass: Apply Boyer-Moore voting to find potential majority candidate
    // Core idea: Pair up different elements and eliminate them
    for (int i = 0; i < n; i++) {
        // When count reaches 0, we need to select a new candidate
        // This happens either at start or when previous candidate was "defeated"
        if (count == 0) {
            // Select current element as the new majority candidate
            candidate = arr[i];
            // Reset count to 1 (this candidate now has 1 vote)
            count = 1;
        }
        // Current element matches our candidate
        else if (arr[i] == candidate) {
            // Increment vote count (supporting vote for candidate)
            // This strengthens the candidate's position
            count++;
        }
        // Current element is different from candidate
        else {
            // Decrement vote count (opposing vote against candidate)
            // Conceptually: pair current element with one occurrence of candidate and eliminate both
            count--;
        }
    }

    // PHASE 2: Verify if the candidate is actually a majority element
    // Note: Verification is necessary because if NO majority exists,
    // the algorithm will still return a candidate (the last survivor)
    
    // Reset counter to count actual occurrences of the candidate
    count = 0;
    
    // Second pass: Count how many times the candidate actually appears
    for (int i = 0; i < n; i++) {
        // Check if current element matches our candidate
        if (arr[i] == candidate) {
            // Increment the occurrence counter
            count++;
        }
    }

    // Verify if candidate appears strictly more than n/2 times
    // This confirms whether it's truly a majority element
    if (count > n / 2) {
        // Candidate is verified as majority element - display it
        cout << "Majority element: " << candidate;
    }
    else {
        // Candidate doesn't meet majority threshold - no majority exists
        // (This typically won't happen if problem guarantees majority exists)
        cout << "No Majority Element found";
    }

    return 0;
}