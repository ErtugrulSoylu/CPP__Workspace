#include <iostream>
#include <vector>
using namespace std;

vector<double> gauss_elimination(vector<vector<double>> &A, vector<double> b) {
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
    for(auto a : A) {
        for(auto b : a) cout << b << " ";
        cout << endl;
    }
    cout << endl;
    vector<double> res = gauss_elimination(A, b);
    for(auto a : A) {
        for(auto b : a) cout << b << " ";
        cout << endl;
    }
    cout << endl;
    for(auto a : res) cout << a << " ";
    return 0;
}