#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<vector<int>> rec(int n, vector<int> vec) {
	vector<vector<int>> res;
	if(n == 1)
		for(auto a : vec) res.push_back({a});
	else
		for(int i = 0; i <= vec.size()-n; i++) {
			vector<vector<int>> tmp_res = rec(n-1, vector<int>(vec.begin()+i+1, vec.end()));
			for(int i = 0; i < tmp_res.size(); i++) tmp_res[i].push_back(vec[i]);
			res.insert(res.end(), tmp_res.begin(), tmp_res.end());
			tmp_res.clear();
		}
	return res;
}
vector<vector<int>> subsequences(vector<int> vec) {
	vector<vector<int>> res;
	for(int i = 1; i <= vec.size(); i++){
		vector<vector<int>> tmp_res = rec(i, vec);
		res.insert(res.end(), tmp_res.begin(), tmp_res.end());
	}
	return res;
}
int main() {
	vector<vector<int>> vec = subsequences({1,2,3,4,5,6});
	for(auto a : vec) {
		for(auto b : a) cout << b << " ";
		cout << endl;
	}
	cout << endl << vec.size();
	return 0;
}