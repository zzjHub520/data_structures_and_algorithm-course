#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m, n;
struct Node {
    int row;
    int col;
};
vector<Node> now_path;
void FindPath(int **matrix, int x, int y, vector<Node> &v) {
    matrix[x][y] = 1;
    now_path.push_back({x, y});
    if (x == m - 1 && y == n - 1) {
        if (v.empty() || now_path.size() < v.size()) { //能保证多条路径时，为最短路径
            v = now_path;
        }
    } else {
        if (x < m - 1 && matrix[x + 1][y] == 0) {
            FindPath(matrix, x + 1, y, v);
        }
        if (x >= 1 && matrix[x - 1][y] == 0) {
            FindPath(matrix, x - 1, y, v);
        }
        if (y < n - 1 && matrix[x][y + 1] == 0) {
            FindPath(matrix, x, y + 1, v);
        }
        if (y >= 1 && matrix[x][y - 1] == 0) {
            FindPath(matrix, x, y - 1, v);
        }
    }
    matrix[x][y] = 0;
    now_path.pop_back();
}

void Show(const Node &no) {
    cout << '(' << no.row << ',' << no.col << ')' << endl;
}

int main() {
    int temp[5][5] = {{0, 1, 0, 0, 0},
                      {0, 1, 0, 1, 0},
                      {0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 0},
                      {0, 0, 0, 1, 0}};

    cin >> m >> n;
    int **maze = new int *[m];
    for (int i = 0; i < m; ++i) {
        maze[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
        }
    }
    vector<Node> vec;
    now_path.clear();
    FindPath(maze, 0, 0, vec);
    for_each(vec.begin(), vec.end(), Show);

    for (int i = 0; i < m; ++i)
        delete[] maze[i];
    delete[] maze;

    return 0;
}