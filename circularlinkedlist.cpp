#include <iostream>
using namespace std;
class node
{

public:
	int info;
	node *next;
	node(int val)
	{

		info = val;
		next = NULL;
	}
};
class CircularLinkedList
{
private:
	node *head;
	int length;
	// int pos; // Not required here

public:
	CircularLinkedList()
	{
		head = NULL;
		length = 0;
		// pos = 0;
	}
	void insert(int val)
	{
		node *n = new node(val);
		if (head == NULL)
		{
			n->next = n;
			head = n;
		}
		else
		{
			node *curr = head;
			//	node*curr1=head;
			while (curr->next != head)
			{
				curr = curr->next;
			}

			curr->next = n;
			n->next = head;
			head = n; 
		}
		length++;
	}
	void insertatpos(int val, int pos)
	{
		
		node *n = new node(val);

		node *curr = head;
		for (int i = 1; i < (pos-1); i++)
			curr = curr->next;
		
		n->next = curr->next;
		curr->next = n;

		length++;

		
	}
	
	void insertatstart(int val){
		
	
		node *n = new node(val);
		node*curr=head;
		while(curr->next!=head){
			
			curr=curr->next;
		}
		n->next=head;
		head=n;
	curr->next=n;
		length ++;
	}

	void printlist()
	{
		node *curr = head;
		do
		{

			cout << curr->info << "--->";
			curr = curr->next;
		} while (curr != head); 
		cout << endl;
	}
};
int main()
{
	CircularLinkedList obj;
	obj.insert(2);
	obj.insert(3);
	obj.insert(4);
	cout<<"list";
	obj.printlist();
	obj.insertatpos(5, 4);
	obj.insertatpos(8, 5);
	obj.printlist();
	cout<<"insertion at first"<<endl;
	obj.insertatstart(2);
	obj.printlist();
	
	return 0;
}
