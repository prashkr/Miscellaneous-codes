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
	struct node *head = NULL;

	int i;
	int n;
	cin>>n;
	int x;
	for(i=0; i<n; i++)
	{	
		cin>>x;
		head = insert(head, x);
	}
	struct node *even = NULL;
	struct node *temp = head;
	struct node *temp1 = head;
	int count = 1;
	while(temp!=NULL)
	{
		if(count%2==0)
		{
			struct node *temp2 = temp1;
			struct node *temp3 = temp;
			temp = temp->next;
			even = delAndInsert(temp2, temp3, even);
		}
		else
		{
			temp1 = temp;
			temp = temp->next;
		}
		count++;
	}
	struct node *tail = findTail(head);
	tail->next = even;
	print(head);

	return 0;
}
