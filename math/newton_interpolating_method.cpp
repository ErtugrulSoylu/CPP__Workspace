#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

float check;
vector<float> b;
float f(vector<float> vec, unordered_map<float, float> map) {
    if(vec.size() == 1) return map[vec[0]];
    vector<float> fh(vec.begin(), vec.end()-1);
    vector<float> lh(vec.begin()+1, vec.end());
    float res = (f(fh, map) - f(lh, map))/(vec[0] - vec[vec.size()-1]);
    if(vec[0] == check) b[vec.size()-1] = res;
    return res;
}
int main() {
    b.clear();
    vector<float> x = {0, 2, 3, 4, 5};
    vector<float> y = {1, 13, 73, 241, 601};
    unordered_map<float, float> map;
    for(int i = 0; i < x.size(); i++) map[x[i]] = y[i];
    b.resize(x.size());
    b[0] = y[0];
    check = x[0];
    f(x, map);
    for(auto a : b) cout << a << " ";
    return 0;
}