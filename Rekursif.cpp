#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long xPangkatn(int x, int n){
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        return x * xPangkatn(x, n - 1);
    }
    else
    {
        return 1 / x * xPangkatn(x, n + 1);
    }
}

int main(){
    long long x;
    int n;
    cout << "Masukkan Angka X: ";
    cin >> x;
    cout << "Masukkan Angka N: ";
    cin >> n;

    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    
    long long hasil = xPangkatn(x,n);
    cout << "Hasil " << x << " Pangkat " << n << " Memakai Rekursif: " << hasil << endl;
    auto end = high_resolution_clock::now();
    double time_taken = duration_cast<nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Hasil Running Time: " << fixed << time_taken << " Detik" << endl;

}