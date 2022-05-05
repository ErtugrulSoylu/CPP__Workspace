#include <iostream>
using namespace std;

double sqrt(double num) {
    double left = 0, right = num-0.00001, mid;
    while(left <= right) {
        mid = left+(right-left)/2;
        if(mid*mid < num) left = mid+0.00001;
        else right = mid-0.00001;
    }
    return mid;
}

int main() {
    double num = 150;
    cout << sqrt(num);
}