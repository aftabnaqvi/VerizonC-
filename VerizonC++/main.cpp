//
//  main.cpp
//  VerizonC++
//
//  Created by Syed Naqvi on 5/25/15.
//  Copyright (c) 2015 Naqvi. All rights reserved.

//  Verizon Interview Preparation
//

#include <iostream>
using namespace std;
#include <vector>


/* Function to reverse the linked list */
void reverseLInkedList() { 
    // Initialize current, previous and 
    // next pointers 
    Node* current = head; 
    Node* prev = NULL, 
    Node* next = NULL; 

    while (current != NULL) { 
        // Store next 
        next = current->next; 

        // Reverse current node's pointer 
        current->next = prev; 

        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    head = prev; 
} 


/* Link list node */
struct node
{
	int data;
	struct node* next;
};

/* This function detects the loop in the list
 If loop was there in the list then it returns 1,
 otherwise returns 0 */
bool detectLoop(struct node *list)
{
	node *slow = list;
	node *fast = list;
 
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast  = fast->next->next;
		
		/* If slow and fast meet at some point then there
		 is a loop */
		if (slow == fast)
		{
			return true;
		}
	}
 
	return false;
}

//remove duplicates from a sorted linked list: http://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/ [amazon asked me this]

void removeDuplicates(node* head){
    node* curr = head;
    if(curr == NULL)
        return;
    
    while (curr->next != NULL){
        if(curr->data == curr->next->data){
            // delete the node.
            node* temp = curr->next->next;
            delete curr->next->next;
            curr->next = temp;
        } else {
            curr = curr->next;
        }
    }
}

/* Function to get no of set bits in binary
 representation of passed binary no. */
int countSetBits(unsigned int n)
{
	unsigned int count = 0;
	while(n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}

void reverse (std::string& data){
	
	string::iterator itStart = data.begin();
	string::iterator itEnd = data.end()-1;
	
	char temp;
	for(; itStart != itEnd; itStart++, itEnd--){
		temp = *itStart;
		*itStart = *itEnd;
		*itEnd = temp;
	}
}

int countWords(string& words){
    int length = words.length();
    if(length == 0)
        return 0;
    
    int i = 0;
    while(words[i] == ' ')
        ++i;
    
    while(words[length--] == ' ')
        --length;
    int count = 0;
    
    while(words[i] != '\0'){
        if( (words[i] != ' ')  && ((words[i+1] == ' ') || (words[i+1] == '\0')) )
            ++count;
        ++i;
    }
    
    return count;
}

void reverse (string::iterator wordStart, string::iterator wordEnd){
	char temp;
	for(; wordStart < wordEnd; wordStart++, wordEnd--){
		temp = *wordStart;
		*wordStart = *wordEnd;
		*wordEnd = temp;
	}
}

void reverseWordsInString (std::string& data){
	
	string::iterator it = data.begin();
	string::iterator itWordStart = data.begin();
	
	for(; it<=data.end(); it++){
		if( it == data.end() || *it == ' '){
			reverse(itWordStart, it-1);
			itWordStart = it + 1;
		}
	}
}

void reverse (char* word, int start, int end){
	for(; start < end; start++, end--){
		char temp = word[start];
		word[start] = word[end];
		word[end] = temp;
	}
}

//void reverse(char *str, int start, int end)
//{
//	char c = str[start];
//	str[start] = str[end];
//	str[end] = c;
//	
//	start++;
//	end--;
//	if (start < end)
//		reverse(str, start, end);
//}

void reverseWordsInString(char *data)
{
	size_t length = strlen(data);
	int index = 0;
	int start = 0;
	
	while(index <= length){
		if(data[index] == '\0' || data[index]== ' '){
			reverse(data, start, index-1);
			start = index+1;
		}
		index++;
	}
}

bool checkPalindrome(char* data){
	int index = 0;
	int endIndex = (int)strlen(data)-1;
	while(index < endIndex){
		if(data[index] != data[endIndex])
			return false;
		index++;
		endIndex--;
	}
	return true;
}

long Atoi(char* data){
	
	short negative = 1;
	long value = 0;
	if(data[0] == '-'){
		negative = -1;
		data++;
	}
	
	if(data[0] == '+')
		data++;
	
	while(*data != '\0'){
		if(*data>='0' && (*data)<='9'){
			value = value*10 + *data-'0';
			data++;
		} else {
			// found invalid character - return 0
			return 0;
		}
	}
	
	return negative*value;
}


#include <typeinfo> // For std::bad_cast
#include <iostream> // For std::cout, etc.

class A
{
public:
	// Since RTTI is included in the virtual method table there should be at least one virtual function.
	virtual void foo(){}
	
	// other members...
};

class B : public A
{
public:
	void methodSpecificToB()
	{
		cout<<"methodSpecificToB"<<endl;
	}
	
	// other members...
};

void my_function(A& my_a)
{
	try
	{
		B& my_b = dynamic_cast<B&>(my_a);
		my_b.methodSpecificToB();
	}
	catch (std::bad_cast e)
	{
		std::cout << "This object is not of type B" << std::endl;
	}
}

void my_function1(A* my_a)
{
	B* my_b = dynamic_cast<B*>(my_a);
	
	if (my_b != NULL)
		my_b->methodSpecificToB();
	else
		std::cout << "This object is not of type B" << std::endl;
}

void displayBits(int value)
{
	/* define display mask */
	unsigned displayMask = 1 << 31;
	
	cout<<"mask: "<<displayMask<<endl;
	
	cout<<value<<" = ";
	
	/* loop through bits */
	for (int x = 0; x < 32; x++)
	{
		if (x%8 == 0){
			cout<<" ";
		}
		
		cout<< (value & displayMask ? '1':'0');
		value <<= 1;
	}
	cout<<endl;
}

bool Number(char* data, int index)
{
	if(strlen(data) == 0)
		return false;
	
	if(data[index] == '\0')
		return true;
	
	if(data[index] <= '0' || data[index] >= '9')
		return false;
	
	return Number(data, ++index);
}

// print the number using putchar
void PrintNum(int n)
{
	if(n == 0)
		return;
	
	PrintNum(n/10);
	putchar('0' + n%10);
}

void Num(int nNum)
{
	if(nNum	== 0)
		return;
	
	Num(nNum/10);
	
	cout<<nNum%10;
}

void Num2Bin(int nNum)
{
	if(nNum == 0)
		return;
	
	Num2Bin(nNum/2);
	
	cout<<nNum%2;
}

int Fib(int num){
	int f0 = 0;
	int f1 = 1;
	int f = 0;
	cout<<f0<<" "<<f1<<" ";
	for(int i=1; i<num; i++){
		f = f0 + f1;
		f0 = f1;
		f1 = f;
		cout<<f<<" ";
	}
	return f;
}

int fib(int n){
	if(n<2){
		return 1;
	}
	
	return fib(n-1) + fib(n-2);
}

int max(int x,int y)
{
	int X = ((x-y)&(-(x<y)));
	return(x-X);
}

void showNumbers(int n){
    for(int i=0; i<n; i++)
        cout<<i<<endl;
}

bool isEmailValid(const char* email){
    if(email == NULL)
        return false;
    
    if(!isalpha(email[0]))
        return false;
    
    int atIndex = 0;
    int dotIndex = 0;
    int index = 0;
    while(email[index] != '\0'){
        if(email[index] == '@'){
            atIndex = index;
        }
        
        if(email[index] == '.'){
                dotIndex = index;
        }
        
        //email++;
        index++;
    }
    
    if( (atIndex == 0 || dotIndex == 0) || dotIndex < atIndex){
        return false;
    }
    
    return (dotIndex<index-1);
}

#include <map>
map<char, bool> myMap;

bool isValidChar(char value){
    
    
    return true;
}

// two sum.. problem...
class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> res;
        std::map<int, int> numsMap;
        
        auto size = nums.size();
        for(int i=0; i<size; ++i){
            auto it = numsMap.find(nums[i]);
            if( it != numsMap.end()){
                res.push_back(min(i, it->second));
                res.push_back(max(i, it->second));
                return res;
            } else {
                numsMap.insert(std::make_pair(target-nums[i], i));
            }
        }
        
        return res;
    }
    

// max profit in stocks..
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = 100000;
        
        for(int i=0; i<prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        
        return maxPro;
    }

};

#include "MoreAlogs.hpp"

int main(int argc, const char * argv[]) {
    
    vector<int> input;
    input.push_back(2);
    input.push_back(9);
    input.push_back(5);
    input.push_back(3);
    input.push_back(1);
    input.push_back(-1);
    input.push_back(100);
    input.push_back(4);
    
    unique_ptr<vector<int>> data;
    
    data = getTwoMinimum(input);
    
    if(data != nullptr)
        for(auto i : *data){
            cout<<"min: "<<i<<endl;
        }
    
    cout<<fibRecursive(5)<<endl;
    cout<<fibn(5)<<endl;
    
    cout<<fac(5)<<endl;
    cout<<factorial(5)<<endl;
    
    cout<<countBits(7)<<endl;
    
//    myMap['%'] = 0;
//    myMap['#'] = 0;
//    myMap['%'] = 0;
//    myMap['%'] = 0;
//    
//    char data[100] = "aft.ab@aftab.com";
//    bool res = isEmailValid(data);
//    cout<<"email: "<<res<<endl;
//    
//    
//	string str = "Hello Jee";
//	reverseWordsInString(const_cast<char*>(str.c_str()));
//	cout<<str<<endl;
//	int num = 15;
//	while(num != 0){
//		num >>= 1;
//		cout<<num<<endl;;
//	}
//
//
//	num = 1;
//	while(num != 0){
//		num <<= 1;
//		cout<<num<<endl;;
//	}

//	 num = 5;
//	while(num != 0){
//		num >>= 2;
//		cout<<num<<endl;;
//	}
//
//	num = 5;
//	while(num != 0){
//		num <<= 1;
//		cout<<num<<endl;;
//	}

//	uint8_t option1 = 0x01; // hex for 0000 0001
//	uint8_t option2 = 0x02; // hex for 0000 0010
//	uint8_t option3 = 0x04; // hex for 0000 0100
//	uint8_t option4 = 0x08; // hex for 0000 1000
//	uint8_t option5 = 0x10; // hex for 0001 0000
//	uint8_t option6 = 0x20; // hex for 0010 0000
//	uint8_t option7 = 0x40; // hex for 0100 0000
//	uint8_t option8 = 0x80; // hex for 1000 0000
//
//	uint8_t myflags; // byte-size value to hold some combination of the above 8 options
//
////	cout<<"option1: "<<option1<<endl;
////	cout<<"option2: "<<option2<<endl;
////	cout<<"option3: "<<option3<<endl;
////	cout<<"option4: "<<option4<<endl;
////	cout<<"option5: "<<option5<<endl;
////	cout<<"option6: "<<option6<<endl;
////	cout<<"option7: "<<option7<<endl;
////	cout<<"option8: "<<option8<<endl;
////
////	cout<<"myflags: "<<myflags<<endl;
//
//
//	myflags |= option4 | option5; // turn option 4 on.
//
//
//
//
//	if( (myflags & option5)  &&  (myflags & option4 ))
//		cout<< "option4 and 5flag in ON"<<endl;
//	else
//		cout<< "option4 flag in OFF"<<endl;
//
//
//	myflags &= ~option1 & ~~option3; // turn option 1 && 3 off.
//	if( (myflags & option1))
//		cout<< "option1 in ON"<<endl;
//	else
//		cout<< "option1 flag in OFF"<<endl;
//
//
//	cout<<"myflags: "<<myflags<<endl;



//myflags |= option4 | option5; // turn options 4 and 5 on.

//
//	unique_ptr<Thing> p1(new Thing(1)); // p1 owns the Thing
//	unique_ptr<Thing> p2; // p2 owns nothing
//
//
//
//
//
//	// invoke move assignment explicitly
//	p2 = std::move(p1); // now p2 owns it, p1 owns nothing
//
//		p2->doSomething();
//
//
//	// invoke move construction explicitly
//	unique_ptr<Thing> p3(std::move(p2)); // now p3 owns it, p2 and p1 own nothing
//
//	if(p2)
//		p2->doSomething();
//	p3->doSomething();
//
//
//
//	if([](int i, int j){cout<<"i= "<<i<<"\n j= "<<j << endl; return 2*i == j; }(2,3))
//		cout << "It's true!" << endl;
//	else
//		cout << "It's false!" << endl;
//
//
	cout << "This lambda returns " <<
	[] (int x, int y) -> int {
		if(x > 5)
			return x + y;
		else if (y < 2)
			return x - y;
		else
			return x * y;
	}(5, 9)<< endl;
	return 0;
}





//#include <iostream>
//#include <string.h>
//using namespace std;
//
//char* reverse(char *data){
//    int start = 0;
//    int end = strlen(data)-1;
//    
//    while (start<end){
//        char temp = data[start];
//        data[start++] = data[end];
//        data[end--] = temp;
//        
//    }
//    
//    return data;
//}
//
//char* reverse(char *data, int start, int end){
//    if(start>=end)
//        return data;
//    
//    while (start<end){
//        char temp = data[start];
//        data[start++] = data[end];
//        data[end--] = temp;
//    }
//    
//    return data;
//}
//
//void reverseWordsInString(char* data){
//    int wStart = 0;
//    int index = 0;
//    int length = strlen(data);
//    
//    while(index <= length ){
//        if(data[index] == ' ' || data[index] == NULL){
//            reverse(data, wStart, index-1);
//            wStart = index+1;
//        }
//        
//        index++;
//    }
//}
//
//int countBits(int num){
//    int count = 0;
//    
//    while(num > 0){
//        count += num & 1;
//        num >>= 1;
//    }
//    
//    return count;
//}
//
//bool isPalindrome(char* data){
//    int length = strlen(data)-1;
//    cout<<"length = " << length <<endl;
//    for(int i=0; i<=length/2; i++){
//        if(data[i] != data[length-i])
//            return false;
//    }
//    
//    return true;
//}
//
//// /* Link list node */
//// struct node
//// {
////     int data;
////     struct node* next;
//// };
//
//// /* The function removes duplicates from a sorted list */
//// void removeDuplicates(struct node* head)
//// {
////     /* Pointer to traverse the linked list */
////     struct node* current = head;
//
////     /* Pointer to store the next pointer of a node to be deleted*/
////     struct node* next_next;
//
////     /* do nothing if the list is empty */
////     if (current == NULL)
////       return;
//
////     /* Traverse the list till last node */
////     while (current->next != NULL)
////     {
////       /* Compare current node with next node */
////       if (current->data == current->next->data)
////       {
////           /* The sequence of steps is important*/
////           next_next = current->next->next;
////           free(current->next);
////           current->next = next_next;
////       }
////       else /* This is tricky: only advance if no deletion */
////       {
////           current = current->next;
////       }
////     }
//// }
//
//node* reverse(node* head){
//    node* curr = head;
//    node* next = NULL;
//    node* prev = NULL;
//    
//    while(curr != NULL){
//        next = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = next;
//    }
//    
//    return prev;
//}
//
//
//bool isEmailValid(const char* email){
//    if(email == NULL)
//        return false;
//    
//    if(!isalpha(email[0]))
//        return false;
//    
//    int atIndex = 0;
//    int dotIndex = 0;
//    int index = 0;
//    while(email != NULL){
//        if(*email == '@'){
//            atIndex = index;
//        }
//        
//        if(*email == '.'){
//            dotIndex = index;
//            if(dotIndex < atIndex)
//                return false;
//        }
//        
//        
//        index++;
//    }
//    
//    if( (atIndex == 0 || dotIndex == 0) || dotIndex < atIndex){
//        return false;
//    }
//    
//    return (dotIndex<index-1);
//}



