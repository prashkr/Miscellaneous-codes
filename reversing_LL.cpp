#include <iostream>
#include <cstdlib>
using namespace std;
#include "LinkedList.h"  //linked list functions


int carry = 0;

struct node *reverse(struct node *t1, struct node *t2)
{	
	if(t2->next==NULL)
	{
		t2->next = t1;
		return t2;
	}
	struct node *head = reverse(t2, t2->next);
	t2->next = t1;
	if(t1==t2)
		t2->next = NULL;

	return head;
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
	head1 = reverse(head1, head1);
	head2 = reverse(head2, head2);

	
	print(head1);
	print(head2);

	return 0;
}
