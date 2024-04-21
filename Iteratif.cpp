#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

long long pangkatIteratif(int n) {
    long long hsl = 1;
    for (int i = 0; i < n; i++) {
        hsl *= 2;
    }
    return hsl;
}

long long pangkatIteratifWhile(int n) {
    long long hsl = 1;
    int i = 1;
    while (i <= n) {
        hsl *= 2;
        i++;
    }
    return hsl;
}

long long pangkatIteratifDoWhile(int n) {
    long long hsl = 1;
    int i = 0;
    do {
        hsl *= 2;
        i++;
    } while (i < n);
    return hsl;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    int num1= 50;
    cout << "Hasil 2 pangkat " << num1 << " menggunakan Iterasi = " << pangkatIteratif(num1) << endl;
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time_taken *= 1e-9;
    cout <<"Running Time for Iterasi: "<< fixed << time_taken <<" detik." << endl;

    start = chrono::high_resolution_clock::now();
    int num2 = 50;
    cout << "Hasil 2 pangkat " << num2 << " menggunakan Iterasi = " << pangkatIteratifDoWhile(num2) << endl;
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time_taken *= 1e-9;
    cout <<"Running Time for Do-While: "<< fixed << time_taken <<" detik." << endl;

    start = chrono::high_resolution_clock::now();
    int num3 = 50;
    cout << "Hasil 2 pangkat " << num3 << " menggunakan Iterasi = " << pangkatIteratifWhile(num3) << endl;
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    time_taken *= 1e-9;
    cout <<"Running Time for While: "<< fixed << time_taken <<" detik." << endl;

}