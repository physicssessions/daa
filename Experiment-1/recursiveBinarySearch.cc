#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>arr, int l, int r, int x) {
   while (l <= r) {
      int m = l + (r - l) / 2;
      if (arr[m] == x)
          return m;
      else if (arr[m] < x)
          l = m + 1;
      else
          r = m - 1;
   }
   return -1;
}

int main() {
    int n;
    cout << "Enter size of Array: ";
    cin >> n;
    cout << endl << "Enter elements: ";
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    cout << endl << "Enter element to be searched: ";
    int x;
    cin >> x;
    int ans = binarySearch(v, 0, n - 1, x);
    if (ans == -1)
        cout << "Element is not present in array" << endl;
    else
        cout << "Element is present at index " << ans << endl;
    return 0;
}

/*
Sample Output:
Enter size of Array: 5
Enter elements: 10 20 30 40 50
Enter element to be searched: 30
Element is present at index 2
*/