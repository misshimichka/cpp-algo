#include<fstream>
#include <vector>
#include <iostream>
using namespace std;

// Стек

ifstream in("input.txt");
ofstream out("output.txt");


int main() {
    int n;
    string sign;
    int number;
    in >> n;

    vector<int> stack(0);

    for (int i = 0; i < n; i++) {
        in >> sign;
        if (equal(sign.begin(), sign.end(), "+")) {
            in >> number;
            stack.push_back(number);
        }
        else {
            int pop = stack[stack.size() - 1];
            stack.pop_back();
            out << pop << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}
