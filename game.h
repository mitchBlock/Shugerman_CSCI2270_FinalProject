#ifndef GAME_H
#define GAME_H
#include <vector>
#include <cstddef>


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
        game();
        virtual ~game();
        void fillBoard();
        void printBoard();
        void buildTree(tile* prev, int i, int j);
        void printPath();
        void defineBoard(std::vector<char> letters);
    protected:
    private:
        tile* board[4][4];
        std::vector<tile*> tails;
};



#endif // GAME_H
