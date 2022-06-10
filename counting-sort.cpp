#include<fstream>
#include <iostream>
#include <vector>
using namespace std;

// Сортировка подсчетом
// Время работы:  O(n)
ifstream in("input.txt");
ofstream out("output.txt");

vector<int> countingSort(vector<int>& a, int k) {
    vector<int> c(k + 1, 0);
    vector<int> b(a.size(), 0);

    for (int i = 0; i < a.size(); i++)
        c[a[i]]++;

    for (int i = 1; i <= c.size(); i++)
        c[i] += c[i - 1];

    vector<int> result(a.size() + 1);
    for (int i = a.size() - 1; i >= 0; i--) {
        result[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    for (int i: result)
        cout << i << " ";
    cout << endl;
    return result;
}

int main() {
    int n, mx = 0;
    in >> n;

    vector<int> a(n, 0);
    vector<int> result(a.size() + 1);

    for (int i = 0; i < n; i ++) {
        in >> a[i];
        mx = max(a[i], mx);
    }

    result = countingSort(a, mx);
    cout << "aboba" << endl;

    for (int i = 1; i < result.size(); i++) {
        cout << result[i] << " ";
        out << result[i] << " ";
    }
}
