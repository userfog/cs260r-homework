#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sat_ops.h"

void bin(myuint num){
    myuint i = 0;
    printf("\nnum: %llu\n", num);
    int j = 0;
    int ls = sizeof(myuint)*8-1;
    for(i = 1 << ls; i > 0; i = i / 2){
        j += 1;
        ((unsigned long long)num & i) ? printf("1") : printf("0");
    } 
    printf("\n%d\n", j); 
}

long long umax[5] = {UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX, ULLONG_MAX};
long long max[5] = {CHAR_MAX, SHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX};
long long min[5] = {CHAR_MIN, SHRT_MIN, INT_MIN, LONG_MAX, LLONG_MIN};


/** Return the value of @x + @y using saturating unsigned addition. */
myuint sat_unsigned_add(myuint x, myuint y){
    if(x > (umax[ARITHTYPE] - y)){
        return umax[ARITHTYPE];
    }
    return x + y;
}
/*myuint sat_unsigned_add(myuint x, myuint y){
    unsigned long long ls = sizeof(myuint)*8-1;
    myuint highest_order = (myuint) pow((unsigned long long) 2, ls);
    myuint sum = 0;
    myuint carry = (x & y) << 1;
    sum = x ^ y;
    
    if((x & y & highest_order) || (x & carry & highest_order) || (y & carry & highest_order)){
        printf("Max");
        return umax[ARITHTYPE];
    }
    else if(sum & carry){
        return sat_unsigned_add(sum, carry); 
    }
    else{
        printf("Norm\n");
        return sum ^ carry;
    }
}*/

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

mysint sat_signed_arith(mysint x, mysint y, myuint highest){
    myuint sum = 0;
    myuint carry = (x & y) << 1;
    sum = x ^ y;
    
    if((x & y & highest) || (x & carry & highest) || (y & carry & highest)){
        printf("Max");
        return max[ARITHTYPE];
    }
    else if(sum & carry){
        return sat_signed_arith(sum, carry, highest); 
    }
    else{
        printf("Norm\n");
        return sum ^ carry;
    }
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

/*mysint sat_signed_add(mysint x, mysint y)
{
    unsigned long long ls = sizeof(myuint)*8-1;
    myuint is_neg = (myuint) pow((unsigned long long) 2, ls);
    myuint highest = (myuint) pow((unsigned long long) 2, ls-1);
    if(((x & is_neg) == 0) && ((y & is_neg) == 0))
    {

        return sat_signed_arith(x, y, highest);
    }
    else if((x & is_neg) && (y & is_neg))
    {
        if(x == min[ARITHTYPE] || y == min[ARITHTYPE])
        {
            return min[ARITHTYPE];
        }

        x = neg(x);
        y = neg(y);

        mysint m = sat_signed_arith(x, y,highest); 
        if(m == max[ARITHTYPE]){
            return min[ARITHTYPE];
        }
        else{
            return neg(m);
        }
    }
    else
    {
        mysint m = x + y;
        return m;
    }
}*/


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
/*mysint sat_signed_sub(mysint x, mysint y){
    if(y == min[ARITHTYPE] && x >= 0){
        return max[ARITHTYPE];
    }

    if(y < 0 && x < 0){
        return x - y; 
    } 

    if( y > 0 && x > 0){
        return x - y;
    }

    return sat_signed_add(x, neg(y));

}*/
