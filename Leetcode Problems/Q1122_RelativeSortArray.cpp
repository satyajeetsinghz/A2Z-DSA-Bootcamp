/*
 * Relative Sort Array (LeetCode Q1122)
 *
 * Problem: Given two arrays arr1 and arr2, sort arr1 such that the relative ordering
 * of items in arr1 follows the order defined in arr2. Elements not in arr2 should
 * appear at the end in ascending order.
 *
 * Approach (Frequency Counting):
 * - Use a frequency array to count occurrences of each element in arr1.
 * - Since arr1[i] can be up to 1000, we create a freq array of size 1001.
 * - First pass: Count frequency of each element in arr1.
 * - Second pass: Print elements in the order they appear in arr2, using their frequency.
 * - Third pass: Print remaining elements (not in arr2) in ascending order.
 *
 * Key Insight:
 * - Frequency array allows us to maintain counts while preserving the custom order.
 * - Elements in arr2 define the priority order for sorting.
 * - Elements not in arr2 are automatically sorted (by iterating freq array in order).
 * - This avoids the need for custom comparator-based sorting.
 *
 * Example:
 * - Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * - Output: [2,2,2,1,4,3,3,9,6,7,19]
 * - Process: Print 2 three times, 1 once, 4 once, 3 twice, 9 once, 6 once (from arr2)
 *            Then print remaining elements (7, 19) in ascending order
 *
 * Complexity:
 * - Time: O(n1 + n2 + 1000) = O(n1 + n2) where n1 is size of arr1, n2 is size of arr2
 * - Space: O(1001) = O(1) constant space for frequency array
 */

#include <iostream>
using namespace std;

// Function to sort arr1 based on relative order defined in arr2
// Parameters: arr1[] - array to be sorted, arr2[] - defines relative order
//            n1 - size of arr1, n2 - size of arr2
void relativeSortArray(int arr1[], int arr2[], int n1, int n2)
{
    // Frequency array to count occurrences of each element (values 0 to 1000)
    int freq[1001] = {0};

    // First pass: Count frequency of each element in arr1
    for (int i = 0; i < n1; i++)
    {
        freq[arr1[i]]++;  // Increment count for this element
    }

    // Second pass: Print elements in the order they appear in arr2
    for (int i = 0; i < n2; i++)
    {
        int val = arr2[i];  // Get the current element from arr2
        // Print this element as many times as it appears in arr1
        while (freq[val] > 0)
        {
            cout << val << " ";  // Print the element
            freq[val]--;  // Decrement its frequency
        }
    }

    // Third pass: Print remaining elements (not in arr2) in ascending order
    for (int i = 0; i <= 1000; i++)
    {
        // If element still has frequency > 0, it wasn't in arr2
        while (freq[i] > 0)
        {
            cout << i << " ";  // Print the element
            freq[i]--;  // Decrement its frequency
        }
    }
}

int main()
{
    // Test case: arr1 to be sorted based on relative order in arr2
    int arr1[] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int arr2[] = {2, 1, 4, 3, 9, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);  // Calculate size of arr1
    int n2 = sizeof(arr2) / sizeof(arr2[0]);  // Calculate size of arr2

    // Display input arrays
    cout << "Input arr1: [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19]" << endl;
    cout << "Input arr2 (order): [2, 1, 4, 3, 9, 6]" << endl;
    cout << "Output: ";
    
    relativeSortArray(arr1, arr2, n1, n2);  // Call function to sort and print

    cout << endl;
    return 0;  // Exit program successfully
}