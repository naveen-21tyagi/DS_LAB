#include <iostream>
using namespace std;
// considering input to be 0-99
void countingSort(int *arr, int n)
{
    int C[100], arr_c[n];
    fill_n(C, 100, 0);
    for (int i = 0; i < n; i++)
    {
        C[arr[i]]++;
    }
    for (int i = 1; i < 100; i++)
    {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i > -1; i--)
    {
        arr_c[--C[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr_c[i];
    }
}
int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}