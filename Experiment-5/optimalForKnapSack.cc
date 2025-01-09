#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mx;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the maximum capacity: ";
    cin >> mx;

    vector<int> w, p;
    vector<double> d;
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        w.push_back(k);
    }
    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        p.push_back(k);
    }

    for (int i = 0; i < n; i++) {
        d.push_back(p[i] / (w[i] * 1.0));
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[i] < d[j]) {
                swap(d[i], d[j]);
                swap(w[i], w[j]);
                swap(p[i], p[j]);
            }
        }
    }

    double profit = 0;
    for (int i = 0; i < n; i++) {
        if (mx < w[i]) {
            profit += mx * d[i];
            break;
        } else {
            profit += p[i];
            mx -= w[i];
        }
    }

    cout << "Maximum Profit is " << profit << endl;
    return 0;
}

/*
Sample Output:
Enter number of elements: 3
Enter the maximum capacity: 50
Enter weights: 10 20 30
Enter profits: 60 100 120
Maximum Profit is 240
*/
