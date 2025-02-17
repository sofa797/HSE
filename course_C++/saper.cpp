#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <functional>
using namespace std;

struct Field {
    vector<vector<int>> field;
    vector<vector<bool>> opened;
    vector<vector<bool>> flags;
    int rows;
    int cols;
    int cntbmb;
};

struct car {
    int row;
    int col;
};

void clr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printp(const Field& game, const car& caret) {
    system("cls");
    cout << "    ";
    for (int i = 0; i < game.cols; i++) {
        clr(15);
        cout << " " << (i + 1 < 10 ? "  " : " ") << i + 1 << " ";
    }
    cout << endl;
    
    for (int i = 0; i < game.rows; i++) {
        clr(15);
        cout << (i + 1 < 10 ? "  " : " ") << i + 1 << "  ";
        for (int j = 0; j < game.cols; j++) {
            if (i == caret.row && j == caret.col) {
                clr(14);
                cout << "["; 
            } else {
                clr(7);
                cout << " ";
            }
            if (game.flags[i][j]) {
                clr(12);
                cout << " F ";
            } 
            else if (game.opened[i][j]) {
                if (game.field[i][j] == 'B') {
                    clr(4);
                    cout << " B ";
                } else {
                    clr(10);
                    cout << " " << game.field[i][j] << " ";
                }
            }
            else {
                clr(8);
                cout << " * ";
            }
            if (i == caret.row && j == caret.col) {
                clr(14);
                cout << "]";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}


void bombs(Field& game) {
    srand(time(0));
    int plcbmb = 0;
    while (plcbmb < game.cntbmb) {
        int r = rand() % game.rows;
        int c = rand() % game.cols;
        if (game.field[r][c] != 'B') {
            game.field[r][c] = 'B';
            plcbmb++;
        }
    }
}

void neighb(Field& game) {
    for (int i = 0; i < game.rows; i++) {
        for (int j = 0; j < game.cols; j++) {
            if (game.field[i][j] == 'B') {
                continue;
            }
            int bmb = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = i + dr, nc = j + dc;
                    if (nr >= 0 && nr < game.rows && nc >= 0 && nc < game.cols && game.field[nr][nc] == 'B') {
                        bmb++;
                    }
                }
            }
            game.field[i][j] = bmb;
        }
    }
}

void revcells(Field& game, int row, int col) {
    if (game.opened[row][col]) return;
    game.opened[row][col] = true;
    if (game.field[row][col] == 0) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nr = row + dr, nc = col + dc;
                if (nr >= 0 && nr < game.rows && nc >= 0 && nc < game.cols) {
                    revcells(game, nr, nc);
                }
            }
        }
    }
}

bool win(const Field& game) {
    int revcells = 0;
    int countbombs = 0;
    for (int i = 0; i < game.rows; i++) {
        for (int j = 0; j < game.cols; j++) {
            if (game.field[i][j] == 'B') countbombs++;
            if (game.opened[i][j] and game.flags[i][j] == false) revcells++;
        }
    }
    return revcells == game.rows * game.cols - countbombs;
}

bool botmove(Field& game) {
    for (int i = 0; i < game.rows; i++) {
        for (int j = 0; j < game.cols; j++) {
            if (game.opened[i][j] && game.field[i][j] > 0) {
                int unopened = 0, flagged = 0;
                vector<pair<int, int>> candidates;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        int nr = i + dr, nc = j + dc;
                        if (nr >= 0 && nr < game.rows && nc >= 0 && nc < game.cols) {
                            if (!game.opened[nr][nc]) {
                                unopened++;
                                candidates.push_back({nr, nc});
                            }
                            if (game.flags[nr][nc]) flagged++;
                        }
                    }
                }
                if (flagged == game.field[i][j]) {
                    for (auto [nr, nc] : candidates) {
                        revcells(game, nr, nc);
                        return true;
                    }
                }
                if (unopened == game.field[i][j] - flagged) {
                    for (auto [nr, nc] : candidates) {
                        game.flags[nr][nc] = true;
                        return true;
                    }
                }
            }
        }
    }
    vector<pair<int, int>> unop;
    for (int i = 0; i < game.rows; i++) {
        for (int j = 0; j < game.cols; j++) {
            if (!game.opened[i][j] && !game.flags[i][j]) {
                unop.push_back({i, j});
            }
        }
    }
    if (!unop.empty()) {
        auto [r, c] = unop[rand() % unop.size()];
        revcells(game, r, c);
        return true;
    }
    return false;
}

int main() {
    Field game;
    car caret = {0, 0};
    bool bot_enabled = false;

    cout << "enter number of rows: ";
    cin >> game.rows;
    cout << "enter number of columns: ";
    cin >> game.cols;
    cout << "enter number of bombs: ";
    cin >> game.cntbmb;
    
    game.field = vector<vector<int>>(game.rows, vector<int>(game.cols, '*'));
    game.opened = vector<vector<bool>>(game.rows, vector<bool>(game.cols, false));
    game.flags = vector<vector<bool>>(game.rows, vector<bool>(game.cols, false));
    bombs(game);
    neighb(game);

    while (true) {
        printp(game, caret);
        if (_kbhit()) {
            char command = _getch();
            if (command == 'w' && caret.row > 0) caret.row--;
            else if (command == 's' && caret.row < game.rows - 1) caret.row++;
            else if (command == 'a' && caret.col > 0) caret.col--;
            else if (command == 'd' && caret.col < game.cols - 1) caret.col++;
            else if (command == '\r' && !game.flags[caret.row][caret.col]) {
                if (game.field[caret.row][caret.col] == 'B') {
                    cout << "Oops, game over :(" << endl;
                    break;
                }
                revcells(game, caret.row, caret.col);
            }
            else if (command == 'f') {
                if (!game.opened[caret.row][caret.col]) {
                    game.flags[caret.row][caret.col] = true;
                }
            }
            else if (command == 'q') {
                cout << "you are left the game" << endl;
                break;
            }
            else if (command == 'b') botmove(game);
            if (win(game)) {
                cout << "Wow, you won!!!!!!" << endl;
                break;
            }
        }
        Sleep(100);
    }
    return 0;
}