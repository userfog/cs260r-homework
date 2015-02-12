/*
Author: Zachary Fogelson
Class: CS260r
Instructor: Eddie Kohler
Date: 2/2/2015


Notes:

To see all of my code / revisions please visit: 
https://github.com/userfog/cs260r-homework

Citation: 
I was going about this assignment all wrong until reading
the Understanding Integer Overflow in C/C++ paper and
seeing its insight that all overflows can be detected
prior to running the code. So, thanks to them for
their insight. 

Further Work:
If I were to continue working on this I think it would be
helpful to turn this code into macros / change my if syntax
to be more concise.

I look forward to seeing other peoples' submissions.

*/


#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "sat_ops.h"

unsigned long long umax[5] = {UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX};
long long max[5] = {CHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX};
long long min[5] = {CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MIN, LLONG_MIN};

/** Return the value of @x + @y using saturating unsigned addition. */
myuint sat_unsigned_add(myuint x, myuint y){
    if(x > (umax[ARITHTYPE] - y)){
        return umax[ARITHTYPE];
    }
    return x + y;
}

/** Return the value of @x - @y using saturating unsigned subtraction. */
myuint sat_unsigned_sub(myuint x, myuint y){
    if(y > x){
        return 0;
    } 
    return x - y;
}

mysint neg(mysint x){
    return (~x+1);
}


/** Return the value of @x + @y using saturating signed addition. */
mysint sat_signed_add(mysint x, mysint y){
    if((x > 0) && (y > 0) && (x > (max[ARITHTYPE] - y))){
        return max[ARITHTYPE];
    }
    if((x < 0) && (y < 0) && (x < (min[ARITHTYPE] - y))){
        return min[ARITHTYPE];
    }
    return x + y;
}

/** Return the value of @x - @y using saturating signed subtraction. */
mysint sat_signed_sub(mysint x, mysint y){
    if(y == min[ARITHTYPE] && x >= 0){
        return max[ARITHTYPE];
    } 
    if((y < 0 && x < 0) || (y > 0 && x > 0)){
        return x - y; 
    } 
    return sat_signed_add(x, neg(y));
}

int main(int argc, char *argv[]){
	
	myuint ans = sat_unsigned_add((myuint)atoi(argv[1]), (myuint)atoi(argv[2]));
	printf("%d", ans);	
}
