#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream inp("inp.txt");
    string line;
    int line_to_change;
    cout << "type what line to change: ";
    cin >> line_to_change;
    ofstream tmp("tmp.txt");
    for (int i = 0; i < line_to_change - 1 && getline(inp, line); i++)
        tmp << line << endl;
    if (!getline(inp, line)) {
        cout << "input too long!";
        tmp.close();
        remove("tmp.txt");
    }
    else {
        tmp << "line changed" << endl;
        while(getline(inp, line)) {
            tmp << line << endl;
        }
        inp.close();
        tmp.close();
        remove("inp.txt");
        rename("tmp.txt", "inp.txt");
    }
    return 0;
}