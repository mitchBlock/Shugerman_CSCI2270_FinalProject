#include "prefixDictionary.h"
#include <iostream>
using namespace std;

prefixDictionary::prefixDictionary()
{
    root = NULL;
}

prefixDictionary::~prefixDictionary()
{
    //dtor
}
void::prefixDictionary::addWordPublic(string word)
{
    node* z = new node;
    addWord(root, z);
}
void prefixDictionary::addWord(node* root, node* z)
{
    node* x = root;
    node* p = NULL;
    while(x != NULL)
    {
        p = x;
        if(z->word.compare(x->word) < 0)
        {
            x = x->l;
        }
        else
        {
            x = x->r;
        }
    }
    z->p = p;
    if(p == NULL)
    {
        root = z;
    }
    else if(z->word.compare(x->word) < 0)
    {
        p->l = z;
    }
    else
    {
        p->r = z;
    }
}

int prefixDictionary::isWordPublic(string word)
{
    return isWord(root, word);
}

int prefixDictionary::isWord(node* subTree, string word)
{
    if (subTree == NULL)
    {
        return -1;
    }

    else if (subTree->word == word)
    {
        return 1;
    }

    else if(word.size() < subTree->word.size())
    {
        string nodePrefix = subTree->word.substr(0,word.size());
        if(nodePrefix == word)
        {
            return 0;
        }
    }

    else if(word.compare(subTree->word) < 0)
    {
        isWord(subTree->l, word);
    }

    if(word.compare(subTree->word) > 0)
    {
        isWord(subTree->r, word);
    }

}
