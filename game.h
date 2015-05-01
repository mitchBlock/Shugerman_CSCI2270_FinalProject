#ifndef GAME_H
#define GAME_H
#include <vector>
#include <cstddef>
#include <string>
#include "prefixDictionary.h"


struct tile
{
    char letter;
    tile* prev;
    tile* a;
    tile* b;
    tile* c;
    bool visited;
};


class game
{
    public:
        game(prefixDictionary* dict);
        virtual ~game();
        void fillBoard();
        void printBoard();
        void defineBoard(std::vector<char> letters);
        void buildTree(tile* prev, int i, int j);
    protected:
    private:
        prefixDictionary* english;
        tile* board[4][4];
        std::string buildWord(tile* letter);
        std::vector<std::string> words;
};



#endif // GAME_H
