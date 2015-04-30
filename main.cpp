#include <iostream>
#include <fstream>
#include "game.h"
#include "prefixDictionary.h"

using namespace std;

int main()
{
    prefixDictionary english;
    game boggle;
    boggle.fillBoard();

    ifstream words("wordsEn.txt");
    string in_word;

    while(getline(words,in_word))
    {
        if(in_word.length() > 2, in_word.length() < 17)
        {
            english.addWord(in_word);
        }
    }
    int choice;
    do
    {
        cout<<"Menu"<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"1. Generate new game board (random letters)"<<endl;
        cout<<"2. Define new game board (enter letters)"<<endl;
        cout<<"3. Print game board"<<endl;
        cout<<"4. Print possible words"<<endl;
        cout<<"5. Quit"<<endl;


        cin >> choice;
        if(choice == 1)
        {
            boggle.fillBoard();
            boggle.printBoard();
        }
        if(choice == 2)
        {
            cout<<"Please enter one letter at a time, followed by the enter key."<<endl;
            cout<< "The letters will be stored left to right, top to bottom"<<endl;
            vector<char> letters;
            for(int i = 0; i < 16; i++)
            {
                char letter;
                cin >> letter;
                letters.push_back(letter);
            }
            cout<<endl;
            boggle.defineBoard(letters);
            boggle.printBoard();
        }
        if(choice == 3)
        {
            boggle.printBoard();
        }
        if(choice == 4)
        {
            boggle.buildTree(NULL, 1, 1);
            boggle.printPath();
        }

    }while(choice != 5);


}
