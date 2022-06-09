#include <iostream>
#include <vector>
using namespace std;

// Сортировка вставками

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 2; j <= n; j++) {
        int i = j - 1;
        while (i > 0 && a[i] > a[i + 1]) {
            swap(a[i], a[i + 1]);
            i -= i;
        }
    }
    for (auto i: a) {
        cout << i << " ";
    }
    return 0;
}
