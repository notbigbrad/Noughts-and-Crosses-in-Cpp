#include <iostream>
#include <string>

using namespace std;

//2D array set out in form grid[y][x]
string grid[3][3] = {
    {"#", "#", "#"},
    {"#", "#", "#"},
    {"#", "#", "#"}
};
int xvalue = 0;
bool win = false;
string winner = "#";
int yvalue = 0;
string player = "X";

int displaygrid() {
    system("cls");
    cout << "Naughts and crosses\n";
    cout << "y\n";
    cout << "3 " << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << "\n";
    cout << "2 " << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << "\n";
    cout << "1 " << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << "\n";
    cout << "x 1 2 3\n";
    return 0;
}

int input() {
    cout << "\nPlayer " << player << " where do you want to go? x:";
    cin >> xvalue;
    while(xvalue > 3 || xvalue < 1) {
        cout << "Out of range, 1-3, x:";
        cin >> xvalue;
    }
    cout << "y:";
    cin >> yvalue;
    while(yvalue > 3 || yvalue < 1) {
        cout << "Out of range, 1-3, y:";
        cin >> yvalue;
    }
    cout << "\n";
    if(grid[yvalue - 1][xvalue - 1] != "#") {
        cout << "This is already taken!\n";
        input();
        return 0;
    }
    grid[yvalue - 1][xvalue - 1] = player;
    if(player == "X") {
        player = "O";
    }else if(player == "O") {
        player = "X";
    }
    return 0;
}

int verify() {
    //cout << "verifying";
    for(int checklinex = 0; checklinex < 3; checklinex++) {
        //cout << "\nin da loop\n" << checklinex << "\n";
        string checking;
        int d;
        for(checking = grid[checklinex][0], d = 0; grid[checklinex][d] == checking && d <= 2; d++) {
            //cout << grid[checklinex][d];
            //cout << "checking line:" << checklinex << " d value =" << d+1 << " Player in question:" << checking << " y\n";
            if(checking == "#") {
                //cout << "line :" << checklinex << " at 0 is #\n";
                break;
            }
            if(d == 2 && checking != "#") {
                win = true;
                winner = checking;
                return win;
            }
        }
    }
    for(int checkliney = 0; checkliney < 3; checkliney++) {
        string checking;
        int d;
        for(checking = grid[0][checkliney], d = 0; grid[d][checkliney] == checking && d <= 2; d++) {
            if(checking == "#") {
                break;
            }
            if(d == 2 && checking != "#") {
                win = true;
                winner = checking;
                return win;
            }
        }
    }
    if (grid[1][1] != "#") {
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            win = true;
            winner = grid[1][1];
            return win;
        } else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            win = true;
            winner = grid[1][1];
            return win;
        }
    }
}

int main() {
    int i = 0;
    while(win != true && i < 9) {
        i++;
        displaygrid();
        input();
        verify();
    }
    displaygrid();
    if(winner == "#") {
        cout << "Nobody won the game!\n";
    }else{
        cout << winner << " won the game!\n";
    }
}