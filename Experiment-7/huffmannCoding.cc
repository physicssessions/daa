#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode *l, MinHeapNode *r) {
        return (l->freq > r->freq);
    }
};

void printCodes(MinHeapNode *root, string str) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    char arr[n];
    int freq[n];
    cout << "Enter Characters: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter Frequencies: ";
    for (int i = 0; i < n; i++) cin >> freq[i];
    HuffmanCodes(arr, freq, n);
    return 0;
}

/*
Sample Output:
Enter number of characters: 6
Enter Characters: a b c d e f
Enter Frequencies: 5 9 12 13 16 45
f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
*/
