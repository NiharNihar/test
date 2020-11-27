// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 


void insert2(struct TrieNode *root, string key)
{
	struct TrieNode *crawl = root;

	for (int i =0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (crawl->children[index] == NULL)
			crawl->children[index] = getNode();
		crawl = crawl->children[index];
	}
	crawl->isEndOfWord = true;
}

bool search2(struct TrieNode *root, string key)
{
	struct TrieNode *crawl;
	crawl = root;
	for(int i = 0; i < key.length(); i++) {
		if (crawl == NULL)
			return false;
		int index = key[i] - 'a';
		if (crawl->children[index] == NULL)
			return false;
		crawl =  crawl->children[index];
	}

	return (crawl != NULL && crawl->isEndOfWord);
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

// Driver 
int main() 
{ 
	// Input keys (use only 'a' through 'z' 
	// and lower case) 
	string keys[] = {"the", "a", "there", 
					"answer", "any", "by", 
					"bye", "their" }; 
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = getNode(); 

	// Construct trie 
	for (int i = 0; i < n; i++) 
		insert2(root, keys[i]); 

	// Search for different keys 
	search(root, "the")? cout << " [the] found\n" : 
						cout << "[the] not found\n"; 
	search(root, "these")? cout << " [these] found\n" : 
						cout << "[these] not found\n"; 
	search2(root, "answer")? cout << " [answer] found\n" : 
						cout << "[answer] not found\n"; 
	search2(root, "nihar")? cout << " [nihar] found\n" : 
						cout << "[nihar] not found\n"; 
	search2(root, "by")? cout << " [by] found\n" : 
						cout << "[by] not found\n"; 
	return 0; 
} 

