#ifndef LIST
#define LIST

/**
 * struct Node - A new struct type defining a node in a linked list.
 *
 * @dir: A directory path.
 * @next: A pointer to another struct Node.
 */
struct Node
{
	char* dir;
	struct Node* next;
};
typedef struct Node Node;


Node* insertNewNode(Node** head, char* dir);

void deallocateList(Node* head);

Node* buildPathList(char* paths);

#endif

