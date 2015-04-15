#include <iostream>
#include <cstdlib>
using namespace std;
#include "LinkedList.h"  //linked list functions


int carry = 0;

struct node *reverse(struct node *t1, struct node *t2, int len)
{	
	if(len<2)
		return t1;
	if(t2->next==NULL)
	{
		t2->next = t1;
		return t2;
	}
	struct node *head = reverse(t2, t2->next, len);
	t2->next = t1;
	if(t1==t2)
		t2->next = NULL;

	return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
	if(head==NULL)
	{
		return newNode(data);
	}
	struct node *temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode(data);
	return head;

}

struct node *sum(struct node *head1, struct node *head2)
{
	struct node *head3 = NULL;
	int carry = 0;
	while(head1!=NULL)
	{
		int temp = (head1->data + head2->data + carry);
		//cout<<"Summming "<<head1->data<<" and " <<head2->data<<" = "<<temp<<endl;
		carry = temp/10;
		head3 = insertAtEnd(head3, temp%10);
		head1 = head1->next;
		head2 = head2->next;
	}
	if(carry>0)
		head3 = insertAtEnd(head3, carry);

	return head3;
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
	head1 = reverse(head1, head1, len1);
	head2 = reverse(head2, head2, len2);

	if(len1>len2)
	{
		int i=0;
		while(i<(len1-len2))
		{
			head2 = insertAtEnd(head2, 0);
			i++;
		}
	}

	if(len1<len2)
	{
		int i=0;
		while(i<(len2-len1))
		{
			head1 = insertAtEnd(head1, 0);
			i++;
		}
	}
	
	struct node *head3 = NULL;
	head3 = sum(head1, head2);
	// print(head1);
	// print(head2);
	// print(head3);
	int len3 = count(head3);
	cout<<"Final sum"<<endl;
	head3 = reverse(head3, head3, len3);
	
	print(head3);

	return 0;
}
