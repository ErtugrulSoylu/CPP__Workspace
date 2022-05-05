
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double f1(double x) {
    double y = 4*pow(x,3)+5*pow(x,2)+x-2;
    return y;
}
double f2(double x) {
    double y = pow(x,2)/(2*pow(x,3)+3);
    return y;
}
double f3(double x) {
    double y = 2*pow(x,2)*exp(-x);
    return y;
}
double riemman_left_sum(int N, double x1, double x2, double (*f)(double x)) {
    double sum = 0;
    double interval = (x2 - x1)/N;
    int i = 0;
    for(double x = x1; x < x2; x+=interval, i++) {
        double y = f(x);
        double area = y*interval;
        sum += area;
        // printf("x%d: %f\tf(x%d): %f\tarea: %f\tsum: %f\n", i, x, i, y, area, sum);
    }
    return sum;
}
double trapezoidal_sum(int N, double x1, double x2, double(*f)(double x)) {
    double sum = 0;
    double interval = (x2-x1)/N;
    int i = 0;
    for(double x = x1; x < x2; x+=interval, i++) {
        double y1 = f(x);
        double y2 = f(x+interval);
        double h = (y1 + y2)/2;
        double area = h*interval;
        sum += area;
        // printf("x%d: %f\tf(x%d): %f\tarea: %f\tsum: %f\n", i, x, i, y1, area, sum);
    }
    return sum;
}
double simpsons_sum(int N, double x1, double x2, double (*f)(double x)) {
    double sum = 0;
    double interval = (x2 - x1)/N;
    int i = 0;
    for(double x = x1; x < x2; x+=interval, i++) {
        double y1 = f(x);
        double y2 = f(x+interval/2);
        double y3 = f(x+interval);
        double area = interval/6*(y1 + 4*y2+ y3);
        sum += area;
        // printf("x%d: %f\tf(x%d): %f\tarea: %f\tsum: %f\n", i, x, i, y1, area, sum);
    }
    return sum;
}
void table(double x1, double x2, double(*f)(double)) {

}
int main() {
    vector<double> vals = {2504/3, 1.506418, 3.047586};
    vector<int> intervals = {2,5,10,50,100};
    vector<vector<double>> riemman(3);
    vector<vector<double>> trapezoidal(3);
    vector<vector<double>> simpsons(3);
    for(auto N : intervals) {
        riemman[0].push_back(riemman_left_sum(N, 1, 5, &f1));
        trapezoidal[0].push_back(trapezoidal_sum(N, 1, 5, &f1));
        simpsons[0].push_back(simpsons_sum(N, 1, 5, &f1));
    }
    for(auto N : intervals) {
        riemman[1].push_back(riemman_left_sum(N, 2, 20, &f2));
        trapezoidal[1].push_back(trapezoidal_sum(N, 2, 20, &f2));
        simpsons[1].push_back(simpsons_sum(N, 2, 20, &f2));
    }
    for(auto N : intervals) {
        riemman[2].push_back(riemman_left_sum(N, 0, 4, &f3));
        trapezoidal[2].push_back(trapezoidal_sum(N, 0, 4, &f3));
        simpsons[2].push_back(simpsons_sum(N, 0, 4, &f3));
    }
    cout << "riemman: \tf1\t\t\t\t\t\tf2\t\t\t\t\t\tf3\n";
    for(int i = 0; i < intervals.size(); i++) {
        for(int j = 0; j < riemman.size(); j++) {
            printf("N = %d: %f\terror value: %f\t\t", intervals[i], riemman[j][i], abs(vals[j] - riemman[j][i]));
        }
        cout << endl;
    }
    cout << "trapezoidal: \tf1\t\t\t\t\t\tf2\t\t\t\t\t\tf3\n";
    for(int i = 0; i < intervals.size(); i++) {
        for(int j = 0; j < trapezoidal.size(); j++) {
            printf("N = %d: %f\terror value: %f\t\t", intervals[i], trapezoidal[j][i], abs(vals[j] - trapezoidal[j][i]));
        }
        cout << endl;
    }
    cout << "simpsons: \tf1\t\t\t\t\t\tf2\t\t\t\t\t\tf3\n";
    for(int i = 0; i < intervals.size(); i++) {
        for(int j = 0; j < riemman.size(); j++) {
            printf("N = %d: %f\terror value: %f\t\t", intervals[i], simpsons[j][i], abs(vals[j] - simpsons[j][i]));
        }
        cout << endl;
    }
    return 0;
}