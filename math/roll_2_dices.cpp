#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int height_of_graph(int dice[11]) {
    int largest_number = dice[0];
    for(int i = 0; i < 10; i++) {
        if(dice[i] < dice[i+1]) {
            largest_number = dice[i+1];
        }
    }
    return largest_number;
}
int main() {
    int dice[11] = {0};
    srand (time(NULL));
    for(int i = 0; i < 10000; i++) {
        switch ((rand() % 6 + 1) + (rand() % 6 + 1)) {
            case 2: dice[0]++;
            break;
            case 3: dice[1]++;
            break;
            case 4: dice[2]++;
            break;
            case 5: dice[3]++;
            break;
            case 6: dice[4]++;
            break;
            case 7: dice[5]++;
            break;
            case 8: dice[6]++;
            break;
            case 9: dice[7]++;
            break;
            case 10: dice[8]++;
            break;
            case 11: dice[9]++;
            break;
            case 12: dice[10]++;
            break;
        }        
    }
    for (int i = 0; i < 11; i++) {
        dice[i]*= .01;
    }
    for(int i = 0; i < height_of_graph(dice); i++) {
        for(int j = 0; j < 11; j++) {
            if(height_of_graph(dice) - i <= dice[j]) {
                cout << "*  ";
            } else {
                cout << "   ";
            }
        }
        cout << "\n";
    }
    cout << "2  3  4  5  6  7  8  9  10 11 12";
    return 0;
}