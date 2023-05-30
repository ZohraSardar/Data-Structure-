#include<iostream>
using namespace std;
class ArrayList{
	private:
	int*arr;
	int*new_arr;
	int*new_curr;
	int*curr;
	int length;
	int pos;
	public:
		ArrayList(int size){
			arr=new int[size];
			//new_arr=new int[size];
			
			curr=arr;
			//new_curr=new_arr;
			length=0;
			pos=0;
		}
		
		void printlist(){ 			// printlist
			
		if (length > 0) {
            curr=arr;
            for (int i= 0; i < length; i++)
                cout << *curr++<<endl;
        }
        else cout << "Array is Empty" << endl;
    }
    
     
	 void insert(int val){ 			//insert value
	 	curr = arr;
	 	curr = curr + length; 	//tail
            *curr = val;
            length++;
            
	 }
	 
	 
	 

	
	
};
int main(){
ArrayList * l1 = new ArrayList(4);
ArrayList l2(4);

   
 l1->insert(55);
 l1->insert(55);
 l1->insert(9);
 l1->insert(6);
 
 l1->printlist();
 

		
		
		}
		
