#include <iostream>
#include <random>
#include <chrono>
#include "prefixDictionary.h"
#include <fstream>

using namespace std;

struct tile
{
    char letter;
    tile* prev = NULL;
    tile* a;
    tile* b;
    tile* c;
    bool visited = false;
};


void buildTree(tile* board[4][4], tile* prev, int i, int j)
{
    if(board[i][j]->visited == false)
    {
        board[i][j]->visited = true;

        tile* newTile;
        if (prev == NULL)
        {
            newTile = board[i][j];
        }
        else
        {
            newTile = new tile;
            newTile->letter = board[i][j]->letter;

            if(prev->prev != NULL)
            {
                t
            }

        }

        if(i > 0)
        {
            i--;
            buildTree(board, newTile, i, j);
        }
        if(i < 3)
        {
            i++;
            buildTree(board, newTile, i, j);
        }
        if(j > 0)
        {
            j--;
            buildTree(board, newTile, i, j);
        }
        if(j < 3)
        {
            j++;
            buildTree(board, newTile, i, j);
        }
    }
}

vector<tile*> buildTreeHolder(tile* board[4][4], int i, int j)
{
    vector<tile*> tails;
    buildTree(board, NULL, i , i);
}

void fillBoard(tile* board[4][4])
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

void printBoard(tile* board[4][4])
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

int main()
{
    tile* board[4][4];
    fillBoard(board);
    printBoard(board);

    prefixDictionary english;

  /*  ifstream words("wordsEn.txt");
    if(!words.is_open())
    {
        cout<< "Hi"<<endl;
    }
    string in_word;
    while(getline(words,in_word))
    {
        english.addWord(in_word);
        cout<<'hi'<<endl;
    }


    english.addWord("hello");
    english.addWord("bargain");
    english.addWord("jello");


    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            buildTree(board, NULL, i, j);
        }
    }
 */
    vector<tile*> tails;
    buildTreeHolder(board, 1, 1);

   // cout<<tails.size()<<endl;

}
