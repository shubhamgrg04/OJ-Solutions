#include <iostream>
#include <queue>

using namespace std;

const int NMAX = 1000;
const int MMAX = 1000;
int n,m;
int input[NMAX][MMAX];
bool visited[NMAX][MMAX];

struct Cell {
    int x;
    int y;
    int rem;
};

bool operator <(const Cell &cell1, const Cell &cell2) {
    return cell1.rem<cell2.rem;
}

Cell make_cell(int x, int y, int rem) {
    Cell cell;
    cell.x = x;
    cell.y = y;
    cell.rem = rem;
    return cell;
}

void visitCell (int x, int y, int rem, priority_queue<Cell>& q) {
    if (x>=0 && y>=0 && x<n && y<m && input[x][y] > -1){
        q.push(make_cell(x, y, rem));
    }
}

void bfs() {
    priority_queue<Cell> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (input[i][j] > 0) {
                q.push(make_cell(i,j,input[i][j]));
            }
        }
    while(!q.empty()){
        int x = q.top().x;
        int y = q.top().y;
        int rem = q.top().rem;
        q.pop();
        if (!visited[x][y] && rem > 0) {
            visitCell(x+1, y, rem-1, q);
            visitCell(x, y+1, rem-1, q);
            visitCell(x-1, y, rem-1, q);
            visitCell(x, y-1, rem-1, q);
        }
        visited[x][y] = true;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++){
                cin >> input[i][j];
                visited[i][j] = false;
            }

        bfs();

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++){
                if (input[i][j] < 0) cout << "B";
                else if (!visited[i][j]) cout << "N"; 
                else  cout << "Y";
            }
            cout << endl;
        }
    }
    return 0;
}