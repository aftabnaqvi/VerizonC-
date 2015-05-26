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

int main(int argc, const char * argv[]) {
	string str = "Hello Jee";
	reverseWordsInString(const_cast<char*>(str.c_str()));
	cout<<str<<endl;
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
