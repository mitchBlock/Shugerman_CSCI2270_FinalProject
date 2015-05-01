#include "prefixDictionary.h"
#include <iostream>
#include <string>

using namespace std;

prefixDictionary::prefixDictionary()
{
    root = NULL;
}

prefixDictionary::~prefixDictionary()
{
    delete root;
}

void prefixDictionary::addWord(string word)
{
    node* z = new node;
    z->word = word;
    z->l = NULL;
    z->r = NULL;

    node* x = root;
    node* p = NULL;

    if (root == NULL)
    {
        root = z;
        root->p = NULL;
    }
    else
    {
        while(x != NULL)
        {
            p = x;
            if(word.compare(x->word) < 0)
            {
                x = x->l;
            }
            else
            {
                x = x->r;
            }
        }
        z->p = p;
        if(word.compare(p->word) < 0)
        {
            p->l = z;
        }
        else
        {
            p->r = z;
        }
    }
}

bool prefixDictionary::isPrefixPublic(string word)
{
    return isPrefix(root,word);
}

bool prefixDictionary::isPrefix(node* subTree, string word)
{
    if (subTree == NULL)
    {
        return false;
    }


    if(word.length() < subTree->word.length())
    {
        string nodePrefix = subTree->word.substr(0,word.length());
        if(nodePrefix == word)
        {
            return true;
        }
    }

    if(word.compare(subTree->word) < 0)
    {
        return isPrefix(subTree->l, word);
    }

    if(word.compare(subTree->word) > 0)
    {
        return isPrefix(subTree->r, word);
    }
}

bool prefixDictionary::isWordPublic(string word)
{
    return isWord(root, word);
}

bool prefixDictionary::isWord(node* subTree, string word)
{
    if (subTree == NULL)
    {
        return false;
    }

    if (subTree->word == word)
    {
        return true;
    }

    if(word.compare(subTree->word) < 0)
    {
        return isWord(subTree->l, word);
    }

    if(word.compare(subTree->word) > 0)
    {
        return isWord(subTree->r, word);
    }

}
