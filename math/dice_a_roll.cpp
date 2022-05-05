#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int height_of_graph(int dice[6]) {
    int largest_number = dice[0];
    for(int i = 0; i < 5; i++) {
        if(dice[i] < dice[i+1]) {
            largest_number = dice[i+1];
        }
    }
    return largest_number;
}
int main() {
    int dice[6] = {0};
    srand (time(NULL));
    for(int i = 0; i < 10000; i++) {
        switch (rand() % 6 + 1) {
            case 1: dice[0]++;
            break;
            case 2: dice[1]++;
            break;
            case 3: dice[2]++;
            break;
            case 4: dice[3]++;
            break;
            case 5: dice[4]++;
            break;
            case 6: dice[5]++;
            break;
        }        
    }
    for (int i = 0; i < 6; i++) {
        dice[i]*= .01;
    }
    for(int i = 0; i < height_of_graph(dice); i++) {
        for(int j = 0; j < 6; j++) {
            if(height_of_graph(dice) - i <= dice[j]) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    for(int i = 0; i < 6; i++) {
        cout << i + 1 << " ";
    }
    cin.get();
    return 0;
}