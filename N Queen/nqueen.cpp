#include <iostream>
#include <cmath>
using namespace std;

const int n = 4;
int v[n];  

bool place(int k, int l) {
    for (int i = 0; i < k; i++) {
        if (v[i] == l || abs(v[i] - l) == abs(i - k)) {
            return false;
        }
    }
    return true;
}
void Nqueens(int k) {
    if (k == n) {
        for (int j = 0; j < n; j++) {
            cout << v[j]+1<< " ";
        }
        cout << endl;
        return;
    }
    for (int c = 0; c < n; c++) {
        if (place(k, c)) {
            v[k] = c;
            Nqueens(k + 1);
        }
    }
}
int main() {
    Nqueens(0);
    return 0;
}
