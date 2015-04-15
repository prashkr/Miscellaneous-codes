#include <iostream>
#include <cstdlib>
using namespace std;
#include "LinkedList.h"  //linked list functions


int carry = 0;

struct node *sum(struct node *head1, struct node *head2, struct node *head3)
{
	if(head1==NULL || head2==NULL)
		return NULL;
	head3 = sum(head1->next, head2->next, head3);
	int temp = (head1->data + head2->data + carry);
	carry = temp/10;
	int data = temp%10;

	//struct node *node = newNode(data);
	return head3 = insertFront(head3, data);
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
	int len1 = count(head1);
	int len2 = count(head2);

	

	if(len1>len2)
	{
		int i=0;
		while(i<(len1-len2))
		{
			//temp1 = temp->next;
			head2 = insertFront(head2, 0);
			i++;
		}
			
	}
	else if(len2>len1)
	{
		int i=0;
		while(i<(len2-len1))
		{
			//temp2 = temp->next;
			head1 = insertFront(head1, 0);
			i++;
		}
	}
	print(head1);
	print(head2);
	//correct till this point

	struct node *temp1 = head1;
	struct node *temp2 = head2;
	static struct node *head3 = NULL;
	//static int carry=0;
	head3 = sum(temp1, temp2, head3);
	if(carry!=0)
		head3 = insertFront(head3, carry);

	print(head3);
	return 0;
}
