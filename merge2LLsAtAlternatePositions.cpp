#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct node *insert(struct node *head, int data)
{
	if(head==NULL)
		return newNode(data);

	struct node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;

	temp->next = newNode(data);
	return head;
}

struct node *findTail(struct node *head)
{
	struct node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;

	return temp;
}

struct node *delAndInsert(struct node *temp1, struct node *temp, struct node *even)
{
	temp1->next = temp->next;
	if(even==NULL)
	{
		temp->next = NULL;
		even = temp;
		return even;
	}

	temp->next = even;
	even = temp;

	return even;
}

void print(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{	
	struct node *head1 = NULL;
	struct node *head2 = NULL;

	int i;
	int n;
	cin>>n;
	int x;
	for(i=0; i<n; i++)
	{	
		cin>>x;
		head1 = insert(head1, x);
	}
	cin>>n;
	for(i=0; i<n; i++)
	{	
		cin>>x;
		head2 = insert(head2, x);
	}
	// print(head1);
	// print(head2);

	struct node *temp1 = head1;
	struct node *temp2 = head2;
	//struct node *temp3 = head2;

	while(temp1!=NULL && temp2!=NULL)
	{
		temp2 = head2->next;
		head2->next = temp1->next;
		temp1->next = head2;
		head2 = temp2;

		temp1 = temp1->next->next;
	}
	print(head1);
	print(head2);

	return 0;
}
