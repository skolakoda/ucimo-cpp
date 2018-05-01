// https://github.com/hasit/gameoflife
// za linux
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#define LIVE 79
#define DEAD 46

#define GNUM 40

using namespace std;

class GameOfLife
{
  private:
    char grid[GNUM][GNUM];
    char temp[GNUM][GNUM];

  public:
    GameOfLife();
    void print();
    void nextgen();
    int neighbours(int, int);
    void setcell(int, int, int);
    void initpattern();
    void copytogrid();
};

GameOfLife::GameOfLife()
{
    for (int i = 0; i < GNUM; i++)
    {
        for (int j = 0; j < GNUM; j++)
        {
            grid[i][j] = DEAD;
            temp[i][j] = DEAD;
        }
    }
}

void GameOfLife::print()
{
    for (int i = 0; i < GNUM; i++)
    {
        for (int j = 0; j < GNUM; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

void GameOfLife::nextgen()
{
    for (int i = 0; i < GNUM; i++)
    {
        for (int j = 0; j < GNUM; j++)
        {
            if (grid[i][j] == LIVE)
            {
                if (neighbours(i, j) < 2)
                {
                    setcell(i, j, 0);
                }
                else if (neighbours(i, j) > 3)
                {
                    setcell(i, j, 0);
                }
                else
                {
                    setcell(i, j, 1);
                }
            }
            else
            {
                if (neighbours(i, j) == 3)
                {
                    setcell(i, j, 1);
                }
                else
                {
                    setcell(i, j, 0);
                }
            }
        }
    }
    copytogrid();
}

void GameOfLife::copytogrid()
{
    for (int i = 0; i < GNUM; i++)
    {
        for (int j = 0; j < GNUM; j++)
        {
            grid[i][j] = temp[i][j];
        }
    }
}

int GameOfLife::neighbours(int x, int y)
{
    int count = 0;

    if (grid[x - 1][y - 1] == LIVE)
    {
        count += 1;
    }
    if (grid[x - 1][y] == LIVE)
    {
        count += 1;
    }
    if (grid[x - 1][y + 1] == LIVE)
    {
        count += 1;
    }
    if (grid[x][y - 1] == LIVE)
    {
        count += 1;
    }
    if (grid[x][y + 1] == LIVE)
    {
        count += 1;
    }
    if (grid[x + 1][y - 1] == LIVE)
    {
        count += 1;
    }
    if (grid[x + 1][y] == LIVE)
    {
        count += 1;
    }
    if (grid[x + 1][y + 1] == LIVE)
    {
        count += 1;
    }

    return (count);
}

void GameOfLife::setcell(int x, int y, int f)
{
    if (f == 1)
    {
        temp[x][y] = LIVE;
    }
    else
    {
        temp[x][y] = DEAD;
    }
}

void GameOfLife::initpattern()
{
    //Glider gun
    grid[5][1] = LIVE;
    grid[6][1] = LIVE;
    grid[5][2] = LIVE;
    grid[6][2] = LIVE;

    grid[5][11] = LIVE;
    grid[6][11] = LIVE;
    grid[7][11] = LIVE;
    grid[4][12] = LIVE;
    grid[8][12] = LIVE;
    grid[3][13] = LIVE;
    grid[9][13] = LIVE;
    grid[3][14] = LIVE;
    grid[9][14] = LIVE;
    grid[6][15] = LIVE;
    grid[4][16] = LIVE;
    grid[8][16] = LIVE;
    grid[5][17] = LIVE;
    grid[6][17] = LIVE;
    grid[7][17] = LIVE;
    grid[6][18] = LIVE;

    grid[3][21] = LIVE;
    grid[4][21] = LIVE;
    grid[5][21] = LIVE;
    grid[3][22] = LIVE;
    grid[4][22] = LIVE;
    grid[5][22] = LIVE;
    grid[2][23] = LIVE;
    grid[6][23] = LIVE;
    grid[1][25] = LIVE;
    grid[2][25] = LIVE;
    grid[6][25] = LIVE;
    grid[7][25] = LIVE;

    grid[3][35] = LIVE;
    grid[4][35] = LIVE;
    grid[3][36] = LIVE;
    grid[4][36] = LIVE;
}

int main()
{
    GameOfLife game;
    game.initpattern();

    while (1)
    {
        game.print();
        game.nextgen();
        cout << "\r\x1b[40A" << flush;
        usleep(75000);
    }

    return 0;
}
