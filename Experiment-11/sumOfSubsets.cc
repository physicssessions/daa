#include <bits/stdc++.h>
using namespace std;

int found = 0;

void PrintSubsetSum(int i, int n, vector<int> set, int targetSum, vector<int>& subset) {
    if (targetSum == 0) {
        found = 1;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << "]\n";
        return;
    }
    if (i == n) return;
    PrintSubsetSum(i + 1, n, set, targetSum, subset);
    if (set[i] <= targetSum) {
        subset.push_back(set[i]);
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);
        subset.pop_back();
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> subset, set;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        set.push_back(k);
    }
    cout << "Enter target sum: ";
    int targetSum;
    cin >> targetSum;

    PrintSubsetSum(0, n, set, targetSum, subset);
    if (found == 0) cout << "No Subset\n";
    return 0;
}

/*
Sample Output:
Enter number of elements: 5
Enter elements: 10 7 5 18 12
Enter target sum: 20
[ 10 5 5 ]
*/
