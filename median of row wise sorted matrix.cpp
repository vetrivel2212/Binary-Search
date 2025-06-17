#include <bits/stdc++.h>
using namespace std;

int upperbound(vector<int>& row, int x) {
    int low = 0, high = row.size() - 1;
    int ans = row.size(); // if all values <= x, return size
    while (low <= high) {
        int mid = (low + high) / 2;
        if (row[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int blackbox(vector<vector<int>>& matrix, int m, int n, int mid) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        count += upperbound(matrix[i], mid);
    }
    return count;
}

int median(vector<vector<int>>& matrix, int m, int n) {
    int low = INT_MAX;
    int high = INT_MIN;

    for (int i = 0; i < m; i++) {
        low = min(matrix[i][0], low);
        high = max(matrix[i][n - 1], high);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int small_equals = blackbox(matrix, m, n, mid);
        if (small_equals <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
