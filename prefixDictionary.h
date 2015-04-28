#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <string>
struct node
{
    std::string word;
    node* p;
    node* l;
    node* r;
};


class prefixDictionary
{
    public:
        prefixDictionary();
        virtual ~prefixDictionary();
        void addWord(std::string word);
        int isWord(node* root, std::string word);
    protected:
    private:
        node* root;
};

#endif // PREFIXDICTIONARY_H
