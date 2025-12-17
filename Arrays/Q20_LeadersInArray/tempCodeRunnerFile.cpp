#include <iostream>
using namespace std;
int main()
{
    int arr[] = {12, 14, 16, 7, 6, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxLeader = INT8_MIN;
