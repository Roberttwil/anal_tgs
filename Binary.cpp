#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

int cariBiner(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x) {
            return m;
        }
        if (arr[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main(void) {
    int n;
    int temp;
    cout << "Banyaknya isi array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    int x;
    cout << "Mencari nomor dalam array: ";
    cin >> x;
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    int result = cariBiner(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element tidak ada dalam array!" << endl;
    else
        cout << "Element berada dalam index ke-" << result << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Running Time: " << fixed << time_taken << " detik.";
}