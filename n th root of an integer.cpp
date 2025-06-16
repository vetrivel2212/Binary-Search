#include <iostream>
using namespace std;

double power(double x, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
        ans *= x;
    }
    return ans;
}

double nthRoot(int x, int n) {
    double low = 0;
    double high = x;
    double eps = 1e-6;  // precision level

    while ((high - low) > eps) {
        double mid = (low + high) / 2.0;
        double res = power(mid, n);

        if (res < x)
            low = mid;
        else
            high = mid;
    }

    return low; // or high — both are nearly equal
}

int main() {
    int x = 2;
    int n = 2;
    cout << "The " << n << "-th root of " << x << " is approximately: " << nthRoot(x, n) << endl;
    return 0;
}
