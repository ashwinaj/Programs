#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>

using namespace std;

#define ARRAY_SIZE(a) sizeof (a)/sizeof(a[0])

struct trieNode
{
    std::string definition;
    struct trieNode* children[26];
};


struct Trie
{
    struct trieNode* root;

};


bool insert(struct Trie* node, std::string key, std::string definition)
{
    // Error checks

    //See if the key exist and if not add it to the trie
    struct trieNode* temp = node->root;
    int length = key.length();

    for(int i=0;i<length;i++)
    {
        int index = key[i] - 'a' ;
        if(!temp->children[index])
        {
            // Create new node
            struct trieNode* newNode = new trieNode();
            for(int k=0;k<26;k++)
                newNode->children[k] = NULL;
           
            temp->children[index] = newNode;
        }

        temp = temp->children[index];
    }

    // We've reached the lst level leaf node, add the definition here
    temp->definition.assign(definition);

    return true ;
}

int search(Trie *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trieNode *pCrawl;
 
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = key[level] - 'a';
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    if(pCrawl != NULL)
    {
        cout<< "Definition: "<<pCrawl->definition<<endl;
        return 1;
    }
    else
        return 0;
}

void initialize(Trie *pTrie)
{
    pTrie->root = new trieNode();
    for(int k=0;k<26;k++)
        pTrie->root->children[k] = NULL;
    pTrie->root->definition.assign( "");
}

int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the" , "a", "there", "answer" , "any", "by", "bye" , "their"};
    Trie trie;
 
    char output[][32] = {"Not present in trie" , "Present in trie"};
 
    initialize(&trie);
 
    // Construct trie
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        std::string str;
        str.assign( "Whatever");
        str.push_back((i+ 'a'));
        //cout<<"Entering:"<<str<<endl;
        insert(&trie, keys[i],str);
    }
 
    // Search for different keys
    printf( "%s --- %s\n", "the" , output[search(&trie, "the")] );
    printf( "%s --- %s\n", "these" , output[search(&trie, "these")] );
    printf( "%s --- %s\n", "their" , output[search(&trie, "their")] );
    printf( "%s --- %s\n", "thaw" , output[search(&trie, "thaw")] );
 
    getchar();
    return 0;

}
