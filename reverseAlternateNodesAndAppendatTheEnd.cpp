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

void delAndInsert(struct node *temp1, struct node *temp, struct node *tail)
{
	temp1->next = temp->next;
	temp->next = tail->next;
	tail->next = temp;
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
	struct node *tail = findTail(head);

	int count = 1;
	struct node *temp = head;
	struct node *temp1 = head;
	while(temp!=tail)
	{
		//cout<<"Count is: "<<count<<endl;
		if(count%2==0)
		{
			struct node *temp2 = temp1;
			struct node *temp3 = temp;
			temp = temp->next;
			delAndInsert(temp2, temp3, tail);
			//print(head);
		}
		else
		{
			temp1 = temp;
			temp = temp->next;	
		}
		
		count++;
	}

	print(head);

	return 0;
}
