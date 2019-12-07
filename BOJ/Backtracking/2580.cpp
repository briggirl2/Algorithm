#include <iostream>
#include <vector>
using namespace std;

int map[9][9], n;
bool findAns = false;
bool row[9][10] = {false, };
bool col[9][10] = {false, };
bool rec[3][3][10] = {false, };
vector<pair<int,int>> blank;

void dfs(int k);
int main() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                blank.push_back({i, j});
                n++;
            }
            else {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                rec[i/3][j/3][map[i][j]] = true;
            }
        }
    }
    dfs(0);
    return 0;
}

void dfs(int k) {
    if (k == n) {
        findAns = true;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) 
                cout << map[i][j] << " ";
            cout << "\n";
        }
        return;
    }

    int x = blank[k].first;
    int y = blank[k].second;
    for (int i=1; i<=9; i++) {
        if (findAns) return; 
        if (row[x][i] || col[y][i] || rec[x/3][y/3][i]) continue;
        row[x][i] = true;
        col[y][i] = true;
        rec[x/3][y/3][i] = true;
        map[x][y] = i;
        dfs(k+1);
        row[x][i] = false;
        col[y][i] = false;
        rec[x/3][y/3][i] = false;
    }
}