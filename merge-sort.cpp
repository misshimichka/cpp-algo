#include<iostream>
#include <vector>
using namespace std;

// Сортировка слиянием
// Время работы:  O(n logn)

vector<int> merge(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector<int> c(0);
    while (i < n || j < m) {
        if ((a[i] <= b[j] && i < n) || j == m) {
            c.push_back(a[i]);
            i++;
        }
        else {
            c.push_back(b[j]);
            j++;
        }
    }
    return c;
}

vector<int> merge_sort(vector<int>& a) {
    int n = a.size();
    if (n == 1)
        return a;
    vector<int> l(begin(a), begin(a) + n / 2);
    vector<int> r(begin(a) + n / 2, end(a));
    l = merge_sort(l);
    r = merge_sort(r);
    return merge(l, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i ++)
        cin >> numbers[i];
    vector<int> result(n);
    result = merge_sort(numbers);

    for (auto i: result) {
        cout << i << " ";
    }
}
