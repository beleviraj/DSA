#include <iostream>
using namespace std;
void getSubset(int S[], int solution[], int n) {
    cout << "Subset found: { ";
    for (int i = 0; i < n; ++i) {
        if (solution[i] == 1) {
            cout << S[i] << " ";
        }
    }
    cout << "}" << endl;
}
void SubsetSum(int S[], int solution[], int n, int target, int currentSum, int currentIndex) {
    if (currentSum == target) {
        getSubset(S, solution, n);
        return;
    }
    if (currentIndex >= n || currentSum > target) {
        return;
    }
    solution[currentIndex] = 1;
    SubsetSum(S, solution, n, target, currentSum + S[currentIndex], currentIndex + 1);
    solution[currentIndex] = 0;
    SubsetSum(S, solution, n, target, currentSum, currentIndex + 1);
}
void SumOfSubsets(int S[], int n, int target) {
    int solution[n] = {0};
    SubsetSum(S, solution, n, target, 0, 0);
}
int main() {
    int S[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(S) / sizeof(S[0]);
    int target = 9;
    SumOfSubsets(S, n, target);
    return 0;
}