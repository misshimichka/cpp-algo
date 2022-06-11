#include<fstream>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

// Очередь

ifstream in("input.txt");
ofstream out("output.txt");

int queue[1000001];
int top = 0;
int head = 1;
int tail = 1;


void enqueue(int n) {
    queue[tail] = n;
    if (tail == 1000000)
        tail = 1;
    else
        tail++;
}

int dequeue() {
    int x = queue[head];
    if (head == 1000000)
        head = 1;
    else
        head++;
    return x;
}


int main() {
    int n;
    string s1;
    string s2 = "+";
    int number;
    in >> n;

    for (long i = 0; i < n; i++) {
        in >> s1;
        if (s1 == s2) {
            in >> number;
            enqueue(number);
        }
        else {
            out << dequeue() << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}
