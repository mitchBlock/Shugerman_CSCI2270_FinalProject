#include "game.h"
#include <random>
#include <chrono>
#include <iostream>

using namespace std;


game::game()
{
    //ctor
}

game::~game()
{
    //dtor
}


void game::fillBoard()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    uniform_int_distribution<int> distribution(0,25);
    default_random_engine generator(seed);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int randInt = distribution(generator);
            char randChar = 'a' + randInt;
            tile* root = new tile;
            root->letter = randChar;
            board[i][j] = root;
        }
    }
}

void game::printBoard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<<board[i][j]->letter<<"|";
        }
        cout<<endl;
    }

}

void game::buildTree(tile* prev, int i, int j)
{
    if(board[i][j]->visited == false)
    {
        board[i][j]->visited = true;

        tile* newTile;
        newTile = new tile;
        newTile->letter = board[i][j]->letter;
        newTile->prev = prev;

        if(prev!= NULL)
        {
            tails.push_back(newTile);
        }

        if(i > 0)
        {
            i--;
            buildTree(newTile, i, j);
        }
        if(i < 3)
        {
            i++;
            buildTree(newTile, i, j);
        }
        if(j > 0)
        {
            j--;
            buildTree(newTile, i, j);
        }
        if(j < 3)
        {
            j++;
            buildTree(newTile, i, j);
        }
    }
}

void game::printPath()
{
    cout<<tails.size()<<endl;
    for(int i = 0; i < 3; i++)
    {
        tile* x = tails[i];
        while(x != NULL)
        {
            cout<<x->letter;
            x = x->prev;
        }
        cout<<endl;
    }

}
