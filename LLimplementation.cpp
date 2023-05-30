#include<iostream>
using namespace std;
class node{
	public:
		node*next;
		int info;
		node(int val){
			info=val;
			next=NULL;
			
			
		}
};
class LinkedList{
	private:
	node*head;
	int length;
	int pos;
	
	public:
		LinkedList(){
			head=NULL;
			length=0;
			pos=0;
		
			
		}
	
	void insert(int val,int pos){
		node*n=new node(val);
	if(pos==1){
				n->next=head;
				head=n;
				
			}
			else{
			
			node*temp=head;
			
			for(int i=1; i<pos-1; i++){
				temp=temp->next;
				
			}
			n->next=temp->next;
				temp->next=n;
		
		
	}
	length++;
}

	void printinglist(){
		node*temp=head;
while(temp!=NULL){
			cout<<temp->info<<"--> ";
			temp=temp->next;
			
		}
}
int maxprofit(){
	node*curr=head;
	while(curr->next!=NULL){
		if(curr->info-curr->next->info>curr->info){
			return (curr->info-curr->next->info);
		}
	}
}		
};
int main(){
LinkedList e1,e2;
	e1.insert(1,44);
	e1.insert(2,30);
	e1.insert(3,24);
	e1.insert(4,32);
	e1.insert(5,35);


	cout<<"list is"<<endl;
 e1.printinglist();
//	cout<<endl;
e1.maxprofit();

}
