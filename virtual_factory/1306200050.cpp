/////////////////////////////////////////
// Ertuğrul SOYLU
// 1306200050
// Date: 17/05/2021
// IDE: Visual Stuido Code
/////////////////////////////////////////
// M = operations_size
// N = orders_size
// Time complexity of my algorithm: O(N*M)
// Since it's too slow for 10^6 orders.txt input, i made a second algorithm for larger inputs.
// You can add brackets at the bottom of the code and disable first algorithm.
// Second algorithms time complexity: O(N*logN)
/////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

//global variables
vector<int> machine;
vector<vector<int>> durations;
vector<vector<int>> orders;
vector<queue<vector<int>>> vec;

string line_arranger(string line) {//removes blanks
    string new_line = "";
    for(int i = 0; i < line.length(); i++) if(line[i] != ' ') new_line += line[i];
    return new_line;
}
void design_schedule(ofstream &sch) {//makes schedule.txt file
    int curr_time = 0;
    sch << curr_time << ";" << orders[0][2] << ";" << orders[0][0] << ";" << orders[0][1] << ";0" << endl;
    curr_time += orders[0][4];
    for(int i = 1; i < orders.size(); i++) {
        int setup = durations[orders[i-1][2]-1][orders[i][2]-1];
        curr_time += setup;
        sch << curr_time << ";" << orders[i][2] << ";" << orders[i][0] << ";" << orders[i][1] << ";" << setup << endl;
        curr_time += orders[i][4];
    }
}
void order_arranger() {//this is the algorithm that makes faster delivery in common
    double scale = 50*machine.size();
    int index = -1, num = 100000000, index_o = 0, sum, curr_time = 0;
    for(int i = 0; i < vec.size(); i++) if(vec[i].front()[5] < num) {num = vec[i].front()[5]; index = i;}//pre-process
    orders.push_back(vec[index].front());
    curr_time += orders[index_o][4];
    vec[index].pop();
    while(true) {//mid process
        num = 100000000; index = orders[index_o][2]-1;
        if(none_of(vec.begin(), vec.end(), [](queue<vector<int>> q){return q.size();})) return;
        if(vec[index].size()) {
            for(int i = 0; i < vec.size(); i++)
                if(vec[i].size()) {
                    sum = durations[vec[i].front()[2]-1][orders[index_o][2]-1] + vec[i].front()[4];
                    if(sum > (vec[i].front()[3] - curr_time)/scale && vec[i].front()[3] - sum - curr_time < num)
                        {index = i; num = vec[i].front()[3] - sum - curr_time;}
                }
        }
        else
            for(int i = 0; i < vec.size(); i++)
                if(vec[i].size()) {
                    sum = durations[vec[i].front()[2]-1][orders[index_o][2]-1] + vec[i].front()[4];
                    if(vec[i].front()[3] - sum < num) 
                        {index = i; num = vec[i].front()[3] - sum;}
                }
        orders.push_back(vec[index].front());
        curr_time += orders[index_o][4] + durations[orders[index_o++][2]-1][orders[index_o][2]-1];
        vec[index].pop();
    }
}
int main() {
    ifstream opr("Operations.txt");//operations
    ifstream drt("SetupDuration.txt");//setup durations
    ifstream ord("Orders.txt");//orders
    ofstream sch("Schedule.txt", fstream::out);//schedule
    string line;
    while(getline(opr, line)) {//stores operations
        line = line_arranger(line);
        machine.push_back(stoi(line.substr(line.find(';')+1)));
    }
    durations.resize(machine.size(), vector<int>(machine.size()));
    while(getline(drt, line)) {//stores setup durations
        line = line_arranger(line) + ';';
        string str = "";
        vector<int> vec = {};
        for(auto c : line) {
            if(c != ';') str += c;
            else {
                vec.push_back(stoi(str));
                str = "";
            }
        }
        durations[vec[0]-1][vec[1]-1] = vec[2];
        durations[vec[1]-1][vec[0]-1] = vec[2];
    }
    while(getline(ord, line)) {//stores orders
        line = line_arranger(line) + ';';
        string str = "";
        vector<int> vec = {};
        for(auto c : line) {
            if(c != ';') str += c;
            else {
                vec.push_back(stoi(str));
                str = "";
            }
        }
        orders.push_back(vec);
    }
    for(int i = 0; i < orders.size(); i++) {//stores actual deadline of an orders (actual deadline = deadline - process time)
        orders[i].push_back(ceil(double(orders[i][1])/double(machine[orders[i][2]-1])));
        orders[i].push_back(orders[i][3] - orders[i][4]);
    }
    sort(orders.begin(), orders.end(), [](vector<int> a, vector<int> b) {return a[5] < b[5];});//sorts orders by their actual deadlines
    
    /////////////////////////////////////////Add brakets to downside for larger inputs (more than 10^4)
    vec.resize(machine.size());
    for(auto a : orders) vec[a[2]-1].push(a);
    orders.clear();
    order_arranger();
    /////////////////////////////////////////Add brakets to upside for larger inputs (MORE ATHAN 10^4)
    design_schedule(sch);
    return 0;
}