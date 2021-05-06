#include <bits/stdc++.h>
using namespace std;
int visited[50][50];
int m, n;
vector<string> field(50);
bool dfs(int i, int j) {
    if(visited[i][j] || field[i][j] == '#') return false;
    else if(i == n-1 && j == m-1) return true;
    visited[i][j] = 1;
    bool possible = false;
    if(i < n-1) possible |= dfs(i+1, j);
    if(possible) return true;

    if(i > 0) possible |= dfs(i-1, j);
    if(possible) return true;

    if(j < m-1) possible |= dfs(i, j+1);
    if(possible) return true;

    if(j > 0) possible |= dfs(i, j-1);
    return possible;

}
 int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }

        bool check_possible;
        vector<pair<int, int>> good_indexes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                check_possible = true;
                if (field[i][j] == 'B') {
                    if (i < n - 1) {
                        if (field[i + 1][j] == 'G') {
                            check_possible = false;
                            break;
                        }
                        else if (field[i + 1][j] == '.') field[i + 1][j] = '#';
                    }
                    if (i > 0) {
                        if (field[i - 1][j] == 'G') {
                            check_possible = false;
                            break;
                        }
                        else if (field[i - 1][j] == '.') field[i - 1][j] = '#';
                    }
                    if (j < m - 1) {
                        if (field[i][j + 1] == 'G') {
                            check_possible = false;
                            break;
                        }
                        else if (field[i][j + 1] == '.') field[i][j + 1] = '#';
                    }
                    if (j > 0) {
                        if (field[i][j - 1] == 'G') {
                            check_possible = false;
                            break;
                        }
                        else if (field[i][j - 1] == '.') field[i][j - 1] = '#';
                    }
                } else if (field[i][j] == 'G') {
                    if (i < n - 1) if (field[i + 1][j] == 'G') continue;
                    if (j < m - 1) if (field[i][j + 1] == 'G') continue;
                    good_indexes.emplace_back(i, j);
                }
            }
            if (!check_possible) break;
        }
        if (!check_possible) {
            cout << "No" << endl;
            continue;
        }

        check_possible = true;
        for (auto const &s : good_indexes) {
            memset(visited, 0, sizeof(visited));
            if (!dfs(s.first, s.second)) {
                cout << "No" << endl;
                check_possible = false;
                break;
            }
        }
        if (check_possible) cout << "Yes" << endl;
    }
}

