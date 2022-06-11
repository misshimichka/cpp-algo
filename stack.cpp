#include<fstream>
#include <vector>
#include <iostream>
using namespace std;

// Стек

ifstream in("input.txt");
ofstream out("output.txt");

int stack[1000000];
int top = 0;


bool is_empty(int s[]) {
    return top == 0;
}

void push(int n) {
    top++;
    stack[top] = n;
}

int pop() {
    int result = stack[top];
    stack[top] = 0;
    top--;
    return result;
}


int main() {
    int n;
    string sign;
    int number;
    in >> n;

    for (long i = 0; i < n; i++) {
        in >> sign;
        if (equal(sign.begin(), sign.end(), "+")) {
            in >> number;
            push(number);
        }
        else {
            out << pop() << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}
