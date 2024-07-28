#include <iostream>
#include <unordered_map>
using namespace std;

void calculateFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    for (auto it : freq) {
        cout << it.first << " occurs " << it.second << " times" << endl;
    }
}

int main() {
    int arr[] = {10, 20, 20, 10, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    calculateFrequency(arr, n);
    return 0;
}
