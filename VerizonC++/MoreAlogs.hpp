//
//  MoreAlogs.hpp
//  VerizonC++
//
//  Created by Aftab Naqvi on 10/2/17.
//  Copyright © 2017 Naqvi. All rights reserved.
//

#ifndef MoreAlogs_hpp
#define MoreAlogs_hpp

#include <stdio.h>
#include <vector>
//Fibonacci (iterative and recursive) [https://www.codeproject.com/Articles/21194/Iterative-vs-Recursive-Approaches]
//Factorial (iterative and recursive) [https://www.codeproject.com/Articles/21194/Iterative-vs-Recursive-Approaches]
//Count the number of 1 bits in a 16/32/64 bit number [https://stackoverflow.com/questions/33826507/counting-number-of-1-bits-in-c-negative-number]

int fibn(int number);
int fibRecursive(int number);

int fac(int number);
int factorial(int number);

int countBits(int number);

std::unique_ptr<std::vector<int>> getTwoMinimum(const std::vector<int> &vec);
#endif /* MoreAlogs_hpp */
