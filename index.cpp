#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
bool tie = false;
string n1, n2;

void functionOne() {
    cout << "  |      |" << endl;
    cout << " " << space[0][0] << "|  " << space[0][1] << "   | " << space[0][2] << endl;
    cout << "__|______|__" << endl;
    cout << "  |      |" << endl;
    cout << " " << space[1][0] << "|  " << space[1][1] << "   | " << space[1][2] << endl;
    cout << "__|______|__" << endl;
    cout << "  |      |" << endl;
    cout << " " << space[2][0] << "|  " << space[2][1] << "   | " << space[2][2] << endl;
    cout << "  |      |" << endl;
}

void functionTwo() {
    int digit;

    cout << ((token == 'x') ? n1 : n2) << ", please enter: ";
    cin >> digit;

    if (digit < 1 || digit > 9) {
        cout << "Invalid !!!" << endl;
        functionTwo();
        return;
    }

    if (digit == 1) { row = 0; column = 0; }
    else if (digit == 2) { row = 0; column = 1; }
    else if (digit == 3) { row = 0; column = 2; }
    else if (digit == 4) { row = 1; column = 0; }
    else if (digit == 5) { row = 1; column = 1; }
    else if (digit == 6) { row = 1; column = 2; }
    else if (digit == 7) { row = 2; column = 0; }
    else if (digit == 8) { row = 2; column = 1; }
    else if (digit == 9) { row = 2; column = 2; }

    if (space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    } else {
        cout << "There is no empty space! " << endl;
        functionTwo();
    }

    functionOne();
}

bool functionThree() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) ||
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }

    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) ||
        (space[0][2] == space[1][1] && space[0][2] == space[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != '0') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);

    cout << n1 << " is player 1, so they will play first." << endl;
    cout << n2 << " is player 2, so they will play second." << endl;

    while (!functionThree()) {
        functionOne();
        functionTwo();
    }

    if (tie) {
        cout << "It's a draw!" << endl;
    } else {
        cout << ((token == '0') ? n1 : n2) << " wins!" << endl;
    }

    return 0;
}
