//
//  MoreAlogs.cpp
//  VerizonC++
//
//  Created by Aftab Naqvi on 10/2/17.
//  Copyright © 2017 Naqvi. All rights reserved.
//

#include "MoreAlogs.hpp"
#include <iostream>

using namespace std;

int fibn(int number){
    
    int f = 0;
    int f1 = 0;
    int f2 = 1;
    
    
    for(int i=0; i<number; i++){
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    
    return f;
}

int fibRecursive(int number){
    if(number < 2){
        return 1;
    }
    
    return fibRecursive(number-2) + fibRecursive(number-1);
}

int fac(int number){
    int res = 1;
    for(int i=1; i<=number; i++){
        res *= i;
    }
    
    return res;
}

int factorial(int number){
    if(number == 1)
        return 1;
    
    return number * factorial(number-1);
}

int countBits(int number){
    
    int count = 0;
    while(number!=0){
        count += number & 1;
        number >>= 1;
    }
    return count;
}

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

std::unique_ptr<std::vector<int>> getTwoMinimum(const std::vector<int> &vec){
    if(vec.size() < 2){
        return nullptr;
    }
    
    std::unique_ptr<std::vector<int>> res(new vector<int>);
    int min1 = vec[0];
    int min2 = vec[1];
    if (min2 < min1){
        min1 = vec[1];
        min2 = vec[0];
    }
    
    for (int i = 2; i < vec.size(); i++){
        if (vec[i] < min1){
            min2 = min1;
            min1 = vec[i];
        }
        else if (vec[i] < min2){
            min2 = vec[i];
        }
    }
    
    res->push_back(min1);
    res->push_back(min2);
    
    return res;
}
