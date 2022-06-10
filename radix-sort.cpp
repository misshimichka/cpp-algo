#include<fstream>
#include <iostream>
#include <vector>
using namespace std;

// Цифровая сортировка
// Время работы:  O(n)
ifstream in("input.txt");
ofstream out("output.txt");

const int c = (1<<16); // 65536 (сдвинули 2^16 на 1 влево)

vector<int> radixSort(vector<int>& a) {
    int n = a.size();
    vector<int> b[c];

    for (int i = 0; i < n; i++)
        b[a[i] % c].push_back(a[i]);

    int k = 0;
    for (int i = 0; i < c; i++) {
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];
        b[i].clear();
    }

    for (int i = 0; i < n; i++)
        b[a[i]/c].push_back(a[i]);

    k = 0;
    for (int i = 0; i < c; i++)
        for (size_t j = 0; j < b[i].size(); j++)
            a[k++] = b[i][j];

    return a;
}

int main() {
    int n;
    in >> n;

    vector<int> a(n, 0);
    vector<int> result(a.size() + 1);

    for (int i = 0; i < n; i ++) {
        in >> a[i];
    }

    result = radixSort(a);

    for (int i = 0; i < result.size(); i++) {
        out << result[i] << " ";
    }
}
