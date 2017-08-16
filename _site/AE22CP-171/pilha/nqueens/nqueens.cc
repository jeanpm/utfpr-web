#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;


struct xy
{
    int i, j;
};

bool** newgrid(const int DIM)
{
    bool** grid = (bool**) malloc(sizeof(bool*) * DIM);
    for (int i = 0; i < DIM; i++) 
    {
        grid[i] = (bool*) malloc(sizeof(bool) * DIM);
        memset(grid[i], false, sizeof(bool) * DIM);
    }
    return grid;
}

int update(xy* free, bool** grid, const int DIM)
{
    int size = 0;
    for (int i = 0; i < DIM; i++) 
    {
        for (int j = 0; j < DIM; j++)
        {
            if (!grid[i][j]) {
                free[size].i = i;
                free[size++].j = j;
            }
        }
    }
    return size;
}

void occupy(xy pos, bool** grid, bool** board, const int DIM)
{
    grid[pos.i][pos.j] = true;
    board[pos.i][pos.j] = true;
    for (int j = 0; j < DIM; j++)
        grid[pos.i][j] = true;

    for (int i = 0; i < DIM; i++)
        grid[i][pos.j] = true;

    for (int i = 0; (pos.i + i) < DIM && (pos.j + i) < DIM; i++)
        grid[pos.i + i][pos.j + i] = true;
    
    for (int i = 0; (pos.i - i) >= 0 && (pos.j - i) >= 0; i++)
        grid[pos.i - i][pos.j - i] = true;
    
    for (int i = 0; (pos.i + i) < DIM && (pos.j - i) >=0; i++)
        grid[pos.i + i][pos.j - i] = true;
    
    for (int i = 0; (pos.i - i) >= 0 && (pos.j + i) < DIM; i++)
        grid[pos.i - i][pos.j + i] = true;
}

void printgrid(bool** grid, const int DIM)
{
    printf("\n");
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++)
            printf("%3c", grid[i][j] ? 'x' : '-');
        printf("\n");
    }
}


int main(int argc, char** argv) 
{
    srand(time(NULL));
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int DIM = 8;

    if (argc > 1)
        DIM = atoi(argv[1]);

    bool** grid  = newgrid(DIM);
    bool** board = newgrid(DIM);
    
    xy free[DIM * DIM];

    int seq[DIM];

    int size; 
    int nqueens = 0;
    do {
        size = update(free, grid, DIM);
        //xy pos = (size <= 1) ? free[0] : free[rand() % size];
        xy pos = free[0];
        seq[nqueens] = pos.j;
        occupy(pos, grid, board, DIM);
        nqueens++;
    } while (size -1 > 0);
    
//    printgrid(board, DIM);
    printf("%d\n", nqueens);
    for (int i = 0; i < nqueens; i++)
        printf("%d ", seq[i] + 1);
    return 0;
}

