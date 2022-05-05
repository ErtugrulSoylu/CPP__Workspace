#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void move(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_sudoku(int sudoku[]) {
	for (int i = 0; i < 81; i++) {
		move((i % 9) * 2, i / 9);
		cout << sudoku[i];
	}
}

int main() {
	bool 
	done = false,
	available = true,
	error = false;
	
	int
	sudoku[81] = {0},
	curr_element = 0;
	
	vector<int> immortal_elements;
	
	while(true) {
		int element;
		int number;
		
		cin >> element;
		if(element == 0) {
			break;
		}
		immortal_elements.push_back (element - 1);
		cin >> number;
		sudoku[element - 1] = number;
		cout << endl << endl;
	}
	system("CLS");
	
	draw_sudoku(sudoku);
	
	while(!done) {
		while(!error) {
			available = true;
			for(int i = 0; i < immortal_elements.size(); i++) {
				if(curr_element == immortal_elements[i]) {
					if(curr_element != 80) {
						curr_element++;
						available = false;
						break;
					} else {
						available = false;
						error = true;
						done = true;
						break;
					}
				}
			}
			if(available) {
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 3; j++) {
						if(curr_element - curr_element%27 + curr_element%9 - curr_element%3 + i + j * 9 != curr_element && sudoku[curr_element - curr_element%27 + curr_element%9 - curr_element%3 + i + j * 9] == sudoku[curr_element]) {
							available = false;
							if(sudoku[curr_element] >= 9) {
								error = true;
							}
							break;
						}
					}
				}
				for(int i = 0; i < 9; i++) {
					if(i != curr_element % 9 && sudoku[curr_element] == sudoku[curr_element - curr_element % 9 + i]) {
						available = false;
						if(sudoku[curr_element] >= 9) {
							error = true;
						}
						break;
					}
					if(i != curr_element / 9 && sudoku[curr_element] == sudoku[curr_element % 9 + i * 9]) {
						available = false;
						if(sudoku[curr_element] >= 9) {
							error = true;
						}
						break;
					}
				}
				if(!available && sudoku[curr_element] != 9) {
					sudoku[curr_element]++;
				}
			}
			if(available) {
				move((curr_element % 9) * 2, curr_element / 9);
				cout << sudoku[curr_element];
				curr_element++;
				if(curr_element == 81) {
					error = true;
					done = true;
				}
			}
		}
		
		if(!done) {
			sudoku[curr_element] = 0;
			move((curr_element % 9) * 2, curr_element / 9);
			cout << 0;
			curr_element--;
		} else {
			break;
		}
		
		while(error) {
			available = true;
			for(int i = 0; i < immortal_elements.size(); i++) {
				if(curr_element == immortal_elements[i]) {
					curr_element--;
					available = false;
					break;
				}
			}
			if(available) {
				if(sudoku[curr_element] < 9) {
					sudoku[curr_element]++;
				} else {
					sudoku[curr_element] = 0;
					move((curr_element % 9) * 2, curr_element / 9);
					cout << 0;
					curr_element--;
					available = false;
				}
			}
			if(available) {
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 3; j++) {
						if(curr_element - curr_element%27 + curr_element%9 - curr_element%3 + i + j * 9 != curr_element && sudoku[curr_element - curr_element%27 + curr_element%9 - curr_element%3 + i + j * 9] == sudoku[curr_element]) {
							available = false;
							break;
						}
					}
				}
				for(int i = 0; i < 9; i++) {
					if(i != curr_element % 9 && sudoku[curr_element] == sudoku[curr_element - curr_element % 9 + i]) {
						available = false;
						break;
					}
					if(i != curr_element / 9 && sudoku[curr_element] == sudoku[curr_element % 9 + i * 9]) {
						available = false;
						break;
					}
				}
			}
			if(available) {
				move((curr_element % 9) * 2, curr_element / 9);
				cout << sudoku[curr_element];
				curr_element++;
				error = false;
			}
		}
	}
	return 0;
}
