#include <iostream>
using namespace std;
int FirstOcc(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}
int LastOcc(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}
int CountOccurrences(int arr[], int n, int key)
{
    int first = FirstOcc(arr, n, key);
    if (first == -1)
    {
        return 0; // Key not found
    }
    int last = LastOcc(arr, n, key);
    return last - first + 1;
}
int main()
{
    int arr[7] = {1, 3, 3, 3, 3, 3, 7};
    cout << "First occurrence of 3 is: " << FirstOcc(arr, 7, 3) << endl;
    cout << "Last occurrence of 3 is: " << LastOcc(arr, 7, 3) << endl;
    cout << "The total occurence of 3 is: " << CountOccurrences(arr, 7, 3); // [( index of first occurrence + index of last occurrence ) - 1]
}