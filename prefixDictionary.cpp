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

void prefixDictionary::addWord(string word)
{
    node* newNode = new node;
    newNode->word = word;

    newNode->l = NULL;
    newNode->r = NULL;

    node* tracer = root;
    node* parent = NULL;

    while(tracer != NULL)
    {
        parent = tracer;

        if(word.compare(tracer->word) < 0)
           {
               tracer = tracer->l;
           }
        else
            {
                tracer = tracer->r;
            }
    }

    newNode->p = parent;

    if (parent == NULL)
    {
        root = newNode;
    }

    else
    {
        if (word.compare(tracer->word) < 0)
        {
            parent->l = newNode;
        }

        if (word.compare(tracer->word) > 0)
        {
            parent->r = newNode;
        }
    }
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
