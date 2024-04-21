#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    int temp;
    cout << "Banyaknya isi array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    int x;
    cout << "Mencari nomor dalam array: ";
    cin >> x;
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    int index = linearSearch(arr, n, x);
    if (index == -1)
        cout << "Element tidak dalam array!" << endl;
    else
        cout << "Element ditemukan dalam index ke-" << index << endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Running Time: " << fixed << time_taken << " detik.";
}