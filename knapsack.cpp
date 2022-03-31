// Задача о рюкзаке без цены
// by misshimichka


#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n, W;
    cin >> W >> n;
    vector <int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    vector <vector <int> > dp(n + 1, vector<int> (W+ 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (w[i] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int w = W; w >= 0; w--) {
        if (dp[n][w] == 1) {
            cout << w << endl;
            return 0;
        }
    }
}
