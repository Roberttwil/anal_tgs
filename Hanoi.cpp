#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

void hanoi(int n, char awal, char tengah, char akhir, int& totalLangkah) {
    if (n == 1) {
        totalLangkah++;
        return;
    }
    hanoi(n - 1, awal, akhir, tengah, totalLangkah);
    totalLangkah++;
    hanoi(n - 1, tengah, awal, akhir, totalLangkah);
}

int main() {
    int jumlah_cincin;
    cout << "Masukkan jumlah cincin: ";
    cin >> jumlah_cincin;

    int totalLangkah = 0;
    auto start = chrono::high_resolution_clock::now();

    hanoi(jumlah_cincin, 'A', 'B', 'C', totalLangkah);

    auto end = chrono::high_resolution_clock::now();

    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Total langkah yang dilakukan: " << totalLangkah << endl;
    cout << "Waktu eksekusi: " << fixed << setprecision(10) << time_taken << " detik" << endl;

    return 0;
}