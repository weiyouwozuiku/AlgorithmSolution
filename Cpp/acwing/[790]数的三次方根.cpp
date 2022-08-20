//
// Created by king on 2021/4/12.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double x;
    scanf("%lf", &x);
    if (x < 0) {
        printf("-");
        x = -x;
    }
    double l = 0, r = max<int>(1,x), mid;
    while (r - l >= 1e-8) {
        mid = (r + l) / 2;
        if (mid * mid * mid > x) r = mid;
        else l = mid;
    }
    printf("%lf", mid);
    return 0;
}