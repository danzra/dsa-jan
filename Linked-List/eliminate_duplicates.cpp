#define NULL 0
class node{
public:
	int data;
	node *next;
	node(int data)
	{
		this->data=data;
		next=NULL;
	}

};
#include<bits/stdc++.h>
using namespace std;
node *input()
{
	int data;
	cin>>data;
	node *head = NULL;
	node *tail = NULL;
	
	while(data!= -1)
	{
		node *newNode = new node(data);
		if(head==NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail=newNode;
		}
		cin>>data;

	}
	return head;
}
void print(node *head)
{
	if(head==NULL)
	{
		return;
	}
	cout<<head->data<<endl;
	print(head->next);

}
int length(node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	return 1 + length(head->next);

}
node *duplicate(node *head)
{
	node *temp =head;
	 if (head == NULL || head->next == NULL)
	 {
        return head;
	}
	while(temp!=NULL)
	{
		if(temp->data == temp->next->data)
		{
			temp->next = temp->next->next;
			

		}
		temp= temp->next;
	}
	return head;

}
int main()
{
	node *head = input();
	print(head);
	cout<<endl;
	//int count = length(head);
	//cout<<count;
	head = duplicate(head);
	print(head);

}