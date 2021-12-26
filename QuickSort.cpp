//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;

void swap(int *A, int *B)
{
    int tmp = *A;
    *A = *B;
    *B = tmp;
}
int partition(int *arr, int l, int r)
{
    int i = l, j = r - 1;
    while (true)
    {
        while (arr[i] < arr[r] && i < r)
            i++;
        while (arr[j] > arr[r] && j > -1)
            j--;
        if (i < j)
            swap(&arr[i++], &arr[j--]);
        else
            break;
    }
    swap(&arr[i], &arr[r]);
    return i;
}
void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pI = partition(arr, l, r);
        quickSort(arr, l, pI - 1);
        quickSort(arr, pI + 1, r);
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
    quickSort(arr, 0, n - 1);
    cout << "In sorted order: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}