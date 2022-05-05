#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> subsequences(vector<int> vec) {
    if(vec.size() == 1) return {vec};
    int num = vec[0];
    vector<vector<int>> res = subsequences(vector<int>(vec.begin()+1, vec.end()));
    int size = res.size();
    for(int i = 0; i < size; i++) {res.push_back(res[i]); res[i].push_back(num);}
    res.push_back({num});
    return res;
}
static bool cmp(vector<int> a, vector<int> b) {return a.size() < b.size();}
int main() {
    vector<int> vec = {1,2,3,4,5,6,7};
    vector<vector<int>> res = subsequences(vec);
    cout << res.size();
    // sort(res.begin(), res.end(), cmp);
    for(auto a : res) {
        for(auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}