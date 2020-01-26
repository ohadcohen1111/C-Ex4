#include <stdio.h>
#include "frequency.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function that returns a new Trie node
struct node* getNewTrieNode()
{
	struct node* Trie = (struct node*)malloc(sizeof(struct node));
    Trie->isLeaf = FALSE;
	for (int i = 0; i < NUM_LETTERS; i++)
    {
        Trie->count = 0;
		Trie->children[i] = NULL;
    }
	return Trie;
}

void insert(node *head, char* str)
{
	// start from root node
	node* curr = head;
	while (*str)
	{
		// create a new node if path doesn't exists
		if (curr->children[*str - 'a'] == NULL)
        {
			curr->children[*str - 'a'] = getNewTrieNode();
        }
		// go to next node
		curr = curr->children[*str - 'a'];

		// move to next character
		str++;
	}

	// mark current node as leaf
    curr->count++;
	curr->isLeaf = TRUE;
}


// Iterative function to search a string in Trie. It returns 1
// if the string is found in the Trie, else it returns 0
int search(node* head, char* str)
{
	// return 0 if Trie is empty
	if (head == NULL)
    {
		return 0;
    }
	node* curr = head;
	while (*str)
	{
		// go to next node
		curr = curr->children[*str - 'a'];

		// if string is invalid (reached end of path in Trie)
		if (curr == NULL)
        {
			return 0;
        }
		// move to next character
		str++;
	}
    return curr->isLeaf;
}

// function to check if current node is leaf node or not 
int isLeafNode(node* root) 
{ 
    return root->isLeaf != FALSE; 
}

// function to display the content of Trie 
void print(node* root, char* str) 
{
	display(root, str, 0, 0);
}

// function to display the content of Trie 
void printR(node* root, char* str) 
{
	display(root, str, 0, 1);
}

// function to display the content of Trie 
void display(node* root, char* str, int level, int isReverse) 
{ 
	if(root == NULL)
	{
		return;
	}
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
		printf("word: %s , count: %ld \n", str, root->count);
    } 
  
	if(isReverse == 1)
	{
		for (int i = NUM_LETTERS - 1; i >= 0; i--)
		{ 
			if (root->children[i])  
			{ 
				str[level] = i + 'a'; 
				display(root->children[i], str, level + 1, isReverse); 
			} 
		}
	}
	else
	{
		for (int i = 0; i < NUM_LETTERS; i++)
		{ 
			if (root->children[i])  
			{ 
				str[level] = i + 'a'; 
				display(root->children[i], str, level + 1, isReverse); 
			} 
		}
	}
}

int validCharacter(char c)
{
if(c >= 'a' && c <= 'z')
{
	return 1;
}
if(c >= 'A' && c <= 'Z')
{
	return 1;
}
return 0;
}

int endOfWord(char c)
{
	if(c == '\t' || c == '\n' || c == '\0' || c ==' ')
	{
		return 1;
	}
	return 0;
}

void freeNode(node* head)
{
	for(int i = 0; i < NUM_LETTERS; i++)
	{
		if(head->children[i] != NULL)
		{
		freeNode(head->children[i]);
		}
	}
	free(head);
}
