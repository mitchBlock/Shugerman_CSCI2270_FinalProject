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
        void addWordPublic(std::string word);
        int isWordPublic(std::string word);

    protected:
    private:
        void addWord(node* root, node* z);
        int isWord(node* root, std::string word);
        node* root;
};

#endif // PREFIXDICTIONARY_H
