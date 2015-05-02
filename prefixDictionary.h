#ifndef PREFIXDICTIONARY_H
#define PREFIXDICTIONARY_H
#include <string>
struct node
{
    std::string word;
    node* p;
    node* l;
    node* r;
    ~node()
    {
        delete l;
        l = NULL;
        delete r;
        r = NULL;
    }
};


class prefixDictionary
{
    public:
        prefixDictionary();
        virtual ~prefixDictionary();
        void addWord(std::string word);
        bool isWordPublic(std::string word);
        bool isPrefixPublic(std::string word);
        node* getRoot();

    protected:
    private:
        bool isWord(node* root, std::string word);
        bool isPrefix(node* root, std::string word);
        node* root;
};

#endif // PREFIXDICTIONARY_H
