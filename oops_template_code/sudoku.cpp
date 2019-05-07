#include<bits/stdc++.h>
using namespace std;

class Sudoku {
private:
	int a[9][9];

public:
	void input() {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				cin >> a[i][j];
			}
		}
	}

	bool isPossible(int row, int col, int val) {
		for(int i=0;i<9;i++) {
			if(a[row][i] == val) {
				return false;
			}
		}
		for(int i=0;i<9;i++) {
			if(a[i][col] == val) {
				return false;
			}
		}
		//submatrix
		int topleftrow = (row/3)*3;
		int topleftcol = (col/3)*3;
		for(int i=topleftrow;i<=topleftrow+2;i++) {
			for(int j=topleftcol;j<=topleftcol+2;j++) {
				if(a[i][j] == val) {
					return false;
				}
			}
		}
		return true;
	}

	bool solution(int row, int col, int val) {
		if(!isPossible(row, col, val)) {
			return false;
		}
		a[row][col] = val;
		int startrow = -1, startcol = -1;
		for(int i=row; i<9; i++) {
			for(int j=((i==row)?col:0); j<9; j++) {
				if(a[i][j] == 0) {
					startrow = i;
					startcol = j;
					break;
				}	
			}
			if(startrow != -1 && startcol != -1) {
				break;
			}
		}
		if(startrow == -1 && startcol == -1) {
			return true;
		}
		for(int i=1;i<=9;i++) {
			if(solution(startrow, startcol, i)) {
				return true;
			}
		}
		a[row][col] = 0;
		return false;
	}


	void solve() {
		int startrow = -1, startcol = -1;
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				if(a[i][j] == 0) {
					startrow = i;
					startcol = j;
					break;
				}
			}
			if(startrow != -1 && startcol != -1) {
				break;
			}
		}
		if(startrow == -1 && startcol == -1) { //already solved
			return;
		}

		for(int i=1;i<=9;i++) {
			if(solution(startrow, startcol, i)) {
				return;
			}
		}

	}

	void print() {
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	int t;
	cin >> t;
	while(t--) {
		Sudoku s;
		s.input();
		s.solve();
		s.print();
	}
}