//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;
void merge(int *arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int *A = new int[n1];
    int *B = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        A[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        B[i] = arr[mid + 1 + i];
    }
    int a = 0, b = 0, c = l;
    while (a < n1 && b < n2)
    {
        if (A[a] <= B[b])
        {
            arr[c++] = A[a++];
        }
        else
        {
            arr[c++] = B[b++];
        }
    }
    while (a < n1)
    {
        arr[c++] = A[a++];
    }

    while (b < n2)
    {
        arr[c++] = B[b++];
    }
}
void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "In sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}