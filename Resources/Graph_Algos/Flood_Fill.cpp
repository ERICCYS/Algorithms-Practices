#include <bits/stdc++.h>
using namespace std;
#define M 8
#define N 8

void floodFillUntil(int screen[][N], int x, int y, int preC, int newC) {
    if (x >= M || x < 0 || y >= N || y < 0) 
        return;
    if (screen[x][y] != preC) 
        return ;
    screen[x][y] = newC;
    floodFillUntil(screen, x, y - 1, preC, newC);
    floodFillUntil(screen, x, y + 1, preC, newC);
    floodFillUntil(screen, x - 1, y, preC, newC);
    floodFillUntil(screen, x + 1, y, preC, newC);
    
}

void floodFill(int screen[][N], int x, int y, int newC) {
    int preC = screen[x][y];
    floodFillUntil(screen, x, y, preC, newC);
}

int main() {
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     };
    int x = 4, y = 4, newC = 3; 
    floodFill(screen, x, y, newC); 
  
    cout << "Updated screen after call to floodFill: \n"; 
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << screen[i][j] << " "; 
        cout << endl; 
    }
}