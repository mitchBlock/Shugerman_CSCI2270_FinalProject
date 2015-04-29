#ifndef GAME_H
#define GAME_H
#include <vector>
#include <cstddef>


struct tile
{
    char letter;
    tile* prev = NULL;
    tile* a;
    tile* b;
    tile* c;
    bool visited = false;
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
    protected:
    private:
        tile* board[4][4];
        std::vector<tile*> tails;
};


#endif // GAME_H
