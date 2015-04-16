
struct node *newNode(int data);
struct node *insert(struct node *head, int data);
struct node *findTail(struct node *head);
void print(struct node *head);
int count(struct node *head);
struct node *insertFront(struct node *head3, int data);


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

//second way to insert
void insert1(struct node **head, int data)
{
	if(*head==NULL)
	{
		*head = newNode(data);
		return;
	}

	struct node *temp = *head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode(data);
}

struct node *findTail(struct node *head)
{
	struct node *temp = head;
	while(temp->next!=NULL)
		temp = temp->next;

	return temp;
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

int count(struct node *head)
{
	int count = 0;
	while(head!=NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

struct node *insertFront(struct node *head3, int data)
{
	struct node *temp = newNode(data);
	if(head3==NULL)
	{
		
		head3 = temp;
		return head3;	
	}	
	
	temp->next = head3;
	head3 = temp;
	return head3;

}

//usage inside main()
/*
	struct node *head = NULL;

	int i;
	for(i=0; i<5; i++)
	{
		int data;
		cin>>data;
		head = insert(head, data);
		// insert1(&head1, data);
	}	

	print(head);

*/