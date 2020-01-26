#define NUM_LETTERS ((int)26)

typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
    char letter;
    long unsigned int count;
    int isLeaf;
    struct node* children[NUM_LETTERS];
} node;

struct node* getNewTrieNode();
void insert(node *head, char* str);
int search(node* head, char* str);
int isLeafNode(node* root); 
void display(node* root, char* str, int level, int isReverse);
int validCharacter(char c);
int endOfWord(char c);
void freeNode(node* head);
void print(node* root, char* str);
void printR(node* root, char* str);
