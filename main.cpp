#include <iostream>

#include <fstream>
#include "game.h"
#include "prefixDictionary.h"

using namespace std;

int main()
{
    game boggle;
    boggle.fillBoard();
    boggle.printBoard();

    prefixDictionary english;


    ifstream words("wordsEn.txt");
    string in_word;
    while(getline(words,in_word))
    {
        english.addWordPublic(in_word);

    }

    boggle.buildTree(NULL, 1, 1);
    boggle.printPath();

/*


    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            buildTree(board, NULL, i, j);
        }
    }


*/



}
