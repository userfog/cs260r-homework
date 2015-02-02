#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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
