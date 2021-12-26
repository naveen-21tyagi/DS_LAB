//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;
void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = arr[i];
        int j;
        for (j = i; j > 0 && tmp < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}
int main()
{
    int *arr, n;
    cout << "Enter no. of elements: ";
    cin >> n;
    arr = new int(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "In sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}