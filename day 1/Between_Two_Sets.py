#!/bin/python3

import math
import os
import random
import re
import sys
from functools import reduce
import math 

def getTotalX(a, b):
    lcm_a = reduce(lambda x,y: x*y//math.gcd(x,y), a)  # Calculating the lcm for array a
    gcd_b = reduce(math.gcd, b)  # Calculating the GCD for array b
    return (sum(gcd_b%x==0 for x in range(lcm_a,gcd_b+gcd_b,lcm_a)))
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()

#The reduce(fun,seq) function is used to apply a particular function passed in its argument to all of the 
#list elements mentioned in the sequence passed along.This function is defined in “functools” module.

# python code to demonstrate working of reduce() 

# importing functools for reduce() 
#import functools 

# initializing list 
#lis = [ 1 , 3, 5, 6, 2, ] 

# using reduce to compute sum of list 
#print ("The sum of the list elements is : ",end="") 
#print (functools.reduce(lambda a,b : a+b,lis)) 

# using reduce to compute maximum element from list 
#print ("The maximum element of the list is : ",end="") 
#print (functools.reduce(lambda a,b : a if a > b else b,lis)) 
