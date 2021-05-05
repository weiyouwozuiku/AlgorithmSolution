//
// Created by king on 2021/5/5.
//

#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6 + 10;
int e[N], head, tail;

void init() {
    head = 0;
    tail = -1;
}

void push(int x) {
    e[tail++] = x;
}

void pop() {
    ++head;
}

int query() {
    return e[head];
}

const char *empty() {
    return tail > head ? "NO" : "YES";
}

int main() {
    int n;
    scanf("%d", &n);
    char op[6];
    int x;
    while (n--) {
        scanf("%s", &op);
        if (!strcmp(op, "push")) {
            scanf("%d", &x);
            push(x);
        }
        if (!strcmp(op, "pop")) pop();
        if (!strcmp(op, "empty")) printf("%s\n", empty());
        if (!strcmp(op, "query")) printf("%d\n", query());
    }
    return 0;
}