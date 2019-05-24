#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct nodel
{
	int data;
	struct nodel* link;
};
int count = 0;
int countl = 0; 
void append(int);
struct nodel* searchl(int);
void displayl();
struct node* insert(struct node*,int);
struct node* search(struct node*,int);
void display(struct node*);
struct node* getnewnode(struct node *,int data);
struct nodel* rootl = NULL;
int main()
{
	struct node* root = NULL;
	
	struct node* temp = NULL;
	struct nodel* templ = NULL;
	int ch;
	int data;
	while(1)
	{
		printf("\n\tOperations on tree\n");
		printf("\t  1.Insert\n");
		printf("\t  2.Search\n");
		printf("\t  3.Display\n");
		printf("\t  4.Exit\n");
		
		printf("\n  Enter your choice \t");
		scanf("%d",&ch);
		
		switch (ch)
		{
			case 1: printf("\n Enter the data to be inserted\t");
					scanf("%d",&data);
					root = insert(root,data);
					append(data);
					printf("\n Element  inserted\n");
					break;
					
			case 2: printf("\n Enter the data to be searched\t");
					scanf("%d",&data);
					temp = search(root,data);
					if(temp == NULL)
					{
						printf("\n Element not found\n");
					}
					else
					{
						printf("\n Element found\n");
					}
					templ = searchl(data);
					if(temp == NULL)
					{
						printf("\n Element not found\n");
					}
					else
					{
						printf("\n Element found\n");
					}
					printf(" \n\n No of passes required to search the element in binary search tree = %d\n",count);
					printf("\n No of passes required to search the element in linked list  = %d\n\n",countl);
					break;
			case 3: 
					printf("\n  Elements in tree are :\n");
					display(root);
					displayl();
					break;
			case 4: exit(0);
					break;
					
			default: printf("\n Invalid choice\n");
					break;
		}
	}
}

struct node* insert(struct node* root,int data)
{
	if(root == NULL)
	{
		root = getnewnode(root,data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
		return root;
	}
	else
	{
		root->right = insert(root->right,data);
		return root;
	}
	
}

struct node* search(struct node* root,int data)
{

	if(root == NULL || root->data == data)
	{
	}
	else if(data < root->data)
	{
		root = search(root->left,data);
		count++;
	}
	else
	{ 
		root = search(root->right,data);
		count++;
	}
	
	return root;
}

void display(struct node* root)
{
	printf("\n  %d",root->data);
	if(root->left)
	{
		display(root->left);
	}
	if(root->right)
	{
		display(root->right);
	}
}

struct node* getnewnode(struct node* root,int data)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void append(int data)
{
	struct nodel* temp;
	temp = (struct nodel*)malloc(sizeof(struct nodel));
	temp->data = data;
	temp->link = NULL;
	if(rootl == NULL)
	{
		rootl = temp;	
	}
	else
	{
		struct nodel* p;
		p = rootl;
		while(p->link!=NULL)
		{
			p = p->link;
		}
		p->link = temp; 		
	}
}

struct nodel* searchl(int data)
{
	struct nodel* temp;
	temp = rootl;
	while(temp != NULL)
	{
		countl++;
		if(temp->data == data)
		{
			return temp;
			temp = temp->link; 
		}
		else
		{
			temp = temp->link;
		}
	}
	if(temp = NULL)
	{
		return temp;
	}
}
	
void displayl()
{
	struct nodel* temp;
	temp = rootl;
	printf("\n  Elements in the linked list are :\n");
	while(temp != NULL)
	{
		printf("\n  %d",temp->data);
		temp = temp->link;
	}		
}
