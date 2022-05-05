#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<double> gauss_elimination(vector<vector<double>> A, vector<double> b) {
    vector<double> res(A.size());
    for(int i = 0; i < A.size(); i++) A[i].push_back(b[i]);
    double scale;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i+1; j < A.size(); j++) {
            for(int k = i; k < A.size(); k++)
                if(A[k][i] > 0) {swap(A[i], A[k]); break;}
            if(A[i][i] == 0) continue;
            scale = A[i][i]/A[j][i];
            for(int k = i; k <= A.size(); k++) A[j][k]-=A[i][k]/scale;
        }
    }
    for(int i = A.size()-1; i >= 0; i--) {
        double sum = 0;
        for(int j = A.size()-1; j > i; j--) {
            sum += A[i][j]*res[j];
        }
        res[i] = (A[i].back()-sum)/A[i][i];
    }
    return res;
}
double error(vector<double> A, vector<double> B) {
    double err = 0;
    for(int i = 0; i < A.size(); i++)
        err = err > abs(A[i] - B[i]) ? err : abs(A[i] - B[i]);
    return err;
}
vector<vector<double>> gauss_seidel(vector<vector<double>> A, vector<double> b) {
    vector<double> actual_res = gauss_elimination(A, b);
    vector<vector<double>> res;
    vector<double> tmp(A.size(), 0);
    res.push_back(tmp);
    for(int i = 0; i < A.size(); i++) A[i].push_back(b[i]);
    while(error(tmp, actual_res) > 0.0001) {
        for(int i = 0; i < A.size(); i++) {
            double sum = 0;
            for(int j = A.size()-1; j >= 0; j--) 
                if(j != i) sum+=A[i][j]*tmp[j];
            tmp[i] = (A[i].back()-sum)/A[i][i];
        }
        res.push_back(tmp);
    }
    return res;
}
int main() {
    vector<vector<double>> A = {
        {15,8,7,5,2},
        {4,13,8,4,4},
        {10,2,12,1,8},
        {1,4,1,9,9},
        {4,7,3,2,14},
    };
    vector<double> b = {
        2,
        9,
        6,
        6,
        10
    };
    vector<vector<double>> res = gauss_seidel(A, b);
    cout << "Iteration steps:\nXi=\t";
    for(int i = 1; i <= res[0].size(); i++) cout << "X" << i << "\t";
    cout << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << i << ")" << "\t";
        for(auto a : res[i]) cout << a << "\t";
        cout << endl;
    }
    return 0;
}