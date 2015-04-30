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

void game::defineBoard(vector<char> letters)
{
    int v = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            tile* root = new tile;
            root->letter = letters[v];
            root->visited = false;
            root->prev = NULL;
            board[i][j] = root;
            v++;
        }
    }

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
            root->visited = false;
            root->prev = NULL;
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

        tile* newTile = new tile;
        newTile->letter = board[i][j]->letter;
        newTile->prev = prev;

        if(prev != NULL)
        {
            if(prev->prev != NULL)
            {
               // if prefixDictionary::isPrefixPublic(newTile)
               // tails.push_back(newTile);
            }

        }

        if(i == 0 and j == 0) // top left corner
        {
            buildTree(newTile, 1, 0);
            buildTree(newTile, 0, 1);
            buildTree(newTile, 1 ,1);
        }
        else if(i == 0) // top
        {
            buildTree(newTile, i, j + 1);
            buildTree(newTile, i + 1, j + 1);
            buildTree(newTile, i + 1, j);
            buildTree(newTile, i + 1, j - 1);
            buildTree(newTile, i, j - 1);
        }
        else if(i == 0 and j == 3) // top right
        {
            buildTree(newTile, 0, 2);
            buildTree(newTile, 1, 2);
            buildTree(newTile, 1, 3);
        }
        else if(j == 3) //right
        {
            buildTree(newTile, i - 1, j);
            buildTree(newTile, i - 1, j - 1);
            buildTree(newTile, i, j - 1);
            buildTree(newTile, i + 1, j - 1);
            buildTree(newTile, i + 1, j);
        }
        else if(j == 3 and i == 3) //bottom right
        {
            buildTree(newTile, 2, 3);
            buildTree(newTile, 2, 2);
            buildTree(newTile, 3, 2);
        }
        else if(i == 3) // bottom
        {
            buildTree(newTile, i, j + 1);
            buildTree(newTile, i - 1, j + 1);
            buildTree(newTile, i - 1, j);
            buildTree(newTile, i - 1, j - 1);
            buildTree(newTile, i, j - 1);
        }
        else if(j == 0) // left
        {
            buildTree(newTile, i - 1, j);
            buildTree(newTile, i - 1, j + 1);
            buildTree(newTile, i, j + 1);
            buildTree(newTile, i + 1, j + 1);
            buildTree(newTile, i + 1, j);
        }
        else
        {
            buildTree(newTile, i - 1, j);
            buildTree(newTile, i - 1, j + 1);
            buildTree(newTile, i, j + 1);
            buildTree(newTile, i + 1, j + 1);
            buildTree(newTile, i + 1, j);
            buildTree(newTile, i + 1, j - 1);
            buildTree(newTile, i, j - 1);
            buildTree(newTile, i - 1, j - 1);
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
