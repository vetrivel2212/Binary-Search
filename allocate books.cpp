#include <bits/stdc++.h>
using namespace std;

bool countStudents(vector<int>& arr, int n, int m, int barrier) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > barrier) return false; // can't allocate this book to anyone

        if (pages + arr[i] <= barrier) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }
    return students <= m;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1; // Not enough books

    int low = *max_element(arr.begin(), arr.end()); // at least the largest book
    int high = accumulate(arr.begin(), arr.end(), 0); // all books in one go

    int res = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (countStudents(arr, n, m, mid)) {
            res = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1; // need bigger range
        }
    }

    return res;
}

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = arr.size();
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
