#include "minunit/minunit.h"
#include "sat_ops.h"
#include <limits.h>

static int foo = 0;
static int bar = 0;
//static double dbar = 0.1;

void test_setup() {
	foo = 7;
	bar = 4;
}

void test_teardown() {
	// Nothing
}

#if ARITHTYPE == 0
MU_TEST(test_max_uadd_char){
	mu_assert(sat_unsigned_add(UCHAR_MAX, UCHAR_MAX) == UCHAR_MAX, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_simple_uadd_char){
	mu_assert(sat_unsigned_add(1,1) == 2, "Unsigned Add: UCHAR_MAX x 2");
}


MU_TEST(test_barely_uadd_char){
	mu_assert(sat_unsigned_add(192,64) == UCHAR_MAX, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_barely2_uadd_char){
	mu_assert(sat_unsigned_add(224,32) == UCHAR_MAX, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_barely3_uadd_char){
	mu_assert(sat_unsigned_add(1,255) == UCHAR_MAX, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_over_uadd_char){
	mu_assert(sat_unsigned_add(130,130) == UCHAR_MAX, "Unsigned Add: UCHAR_MAX x 2");
}

#endif


#if ARITHTYPE == 1
MU_TEST(test_max_uadd_char){
	mu_assert(sat_unsigned_add(UCHAR_MAX, UCHAR_MAX) == UCHAR_MAX*2, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_max_uadd_short){
	mu_assert(sat_unsigned_add(USHRT_MAX, USHRT_MAX) == USHRT_MAX, "Unsigned Add: SHRT_MAX x 2");
}


MU_TEST(test_barely_uadd_ll){
	mu_assert(sat_unsigned_add(65535,1) == USHRT_MAX, "Unsigned Add: ULLONG_MAX x 2");
}


MU_TEST(test_max_add_ll){
	mu_assert(sat_unsigned_add(21845,43690) == USHRT_MAX, "Signed Add: LLONG_MAX x 2");
}

MU_TEST(test_negs_add_ll){
	mu_assert(sat_signed_add(16383,16387) == SHRT_MAX, "Signed Add: Smaller than LLONG_MIN");
}

MU_TEST(test_min_add_ll){
	mu_assert(sat_signed_add(SHRT_MIN,SHRT_MIN) == SHRT_MIN, "Signed Add: LLONG_MIN x 2");
}


MU_TEST(test_exceed_add_ll){
	mu_assert(sat_signed_add(SHRT_MIN,1) == -SHRT_MAX, "Signed Add: Bigger than LLONG_MIN");
}

MU_TEST(test_min_max_add_ll){
	mu_assert(sat_signed_add(SHRT_MIN,SHRT_MAX) == -1, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_neg_max_add_ll){
	mu_assert(sat_signed_add(SHRT_MAX,-SHRT_MAX) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_0_min_sub_ll){
	mu_assert(sat_signed_sub(0,SHRT_MIN) == SHRT_MAX, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_0_max_sub_ll){
	mu_assert(sat_signed_sub(0,SHRT_MAX) == -SHRT_MAX, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_min_0_add_ll){
	mu_assert(sat_signed_sub(SHRT_MIN, 0) == SHRT_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_min_sub_ll){
	mu_assert(sat_signed_sub(SHRT_MIN,SHRT_MIN) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_max_sub_ll){
	mu_assert(sat_signed_sub(SHRT_MAX,SHRT_MAX) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}


#endif

#if ARITHTYPE == 2
MU_TEST(test_max_uadd_char){
	mu_assert(sat_unsigned_add(UCHAR_MAX, UCHAR_MAX) == UCHAR_MAX*2, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_max_uadd_short){
	mu_assert(sat_unsigned_add(USHRT_MAX, USHRT_MAX) == USHRT_MAX*2, "Unsigned Add: SHRT_MAX x 2");
}

MU_TEST(test_max_uadd_int){
	mu_assert(sat_unsigned_add(UINT_MAX, UINT_MAX) == UINT_MAX, "Unsigned Add: UINT_MAX x 2");
}

MU_TEST(test_barely_uadd_ll){
	mu_assert(sat_unsigned_add(4294967294, 2) == UINT_MAX, "Unsigned Add: ULLONG_MAX x 2");
}


MU_TEST(test_max_add_ll){
	mu_assert(sat_signed_add(INT_MAX,INT_MAX) == INT_MAX, "Signed Add: INT_MAX x 2");
}

MU_TEST(test_negs_add_ll){
	mu_assert(sat_signed_add(-22738,-45631) == -68369, "Signed Add: Smaller than INT_MIN");
}

MU_TEST(test_min_add_ll){
	mu_assert(sat_signed_add(INT_MIN,INT_MIN) == INT_MIN, "Signed Add: INT_MIN x 2");
}

MU_TEST(test_exceed_add_ll){
	mu_assert(sat_signed_add(-2147483647,-2) == INT_MIN, "Signed Add: Bigger than INT_MIN");
}

MU_TEST(test_min_max_add_ll){
	mu_assert(sat_signed_add(INT_MAX,INT_MIN) == -1, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_neg_max_add_ll){
	mu_assert(sat_signed_add(2147483647,-2147483647) == 0, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_0_min_sub_ll){
	mu_assert(sat_signed_sub(0,INT_MIN) == INT_MAX, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_0_max_sub_ll){
	mu_assert(sat_signed_sub(0,INT_MAX) == -INT_MAX, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_min_0_add_ll){
	mu_assert(sat_signed_sub(INT_MIN, 0) == INT_MIN, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_min_sub_ll){
	mu_assert(sat_signed_sub(INT_MIN,INT_MIN) == 0, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_max_sub_ll){
	mu_assert(sat_signed_sub(INT_MAX,INT_MAX) == 0, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_neg_max_minus_1){
	mu_assert(sat_signed_sub(-INT_MAX,1) == INT_MIN, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_minus_1_max){
	mu_assert(sat_signed_sub(-1,INT_MAX) == INT_MIN, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_int_min_12){
	mu_assert(sat_signed_sub(12,(INT_MIN+11)) == INT_MAX, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_barely){
	mu_assert(sat_signed_sub(-1,INT_MAX) == INT_MIN, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_barely_not){
	mu_assert(sat_signed_sub(-1,(INT_MAX-1)) == INT_MIN+1, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_min_2){
	mu_assert(sat_signed_sub(INT_MIN,-2) == INT_MIN+2, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_2){
	mu_assert(sat_signed_sub(INT_MIN,2) == INT_MIN, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_alot){
	mu_assert(sat_signed_sub(INT_MIN, INT_MIN) == 0, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_min_max){
	mu_assert(sat_signed_sub(INT_MIN, INT_MAX) == INT_MIN, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_max_min){
	mu_assert(sat_signed_sub(INT_MAX, INT_MIN) == INT_MAX, "Signed Add: INT_MAX + INT_MIN");
}

MU_TEST(test_sub_max_max){
	mu_assert(sat_signed_sub(INT_MAX, INT_MAX) == 0, "Signed Add: INT_MAX + INT_MIN");
}
#endif

#if ARITHTYPE == 3
MU_TEST(test_max_uadd_char){
	mu_assert(sat_unsigned_add(UCHAR_MAX, UCHAR_MAX) == UCHAR_MAX*2, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_max_uadd_short){
	mu_assert(sat_unsigned_add(USHRT_MAX, USHRT_MAX) == USHRT_MAX*2, "Unsigned Add: SHRT_MAX x 2");
}

MU_TEST(test_max_uadd_int){
	mu_assert(sat_unsigned_add(ULONG_MAX, ULONG_MAX) == ULONG_MAX, "Unsigned Add: ULONG_MAX x 2");
}

MU_TEST(test_barely_uadd_ll){
	mu_assert(sat_unsigned_add(4294967294, 2) == ULONG_MAX, "Unsigned Add: ULLONG_MAX x 2");
}


MU_TEST(test_max_add_ll){
	mu_assert(sat_signed_add(LONG_MAX,LONG_MAX) == LONG_MAX, "Signed Add: LONG_MAX x 2");
}

MU_TEST(test_negs_add_ll){
	mu_assert(sat_signed_add(-22738,-45631) == -68369, "Signed Add: Smaller than LONG_MIN");
}

MU_TEST(test_min_add_ll){
	mu_assert(sat_signed_add(LONG_MIN,LONG_MIN) == LONG_MIN, "Signed Add: LONG_MIN x 2");
}

MU_TEST(test_exceed_add_ll){
	mu_assert(sat_signed_add(-2147483647,-2) == LONG_MIN, "Signed Add: Bigger than LONG_MIN");
}

MU_TEST(test_min_max_add_ll){
	mu_assert(sat_signed_add(LONG_MAX,LONG_MIN) == -1, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_neg_max_add_ll){
	mu_assert(sat_signed_add(2147483647,-2147483647) == 0, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_0_min_sub_ll){
	mu_assert(sat_signed_sub(0,LONG_MIN) == LONG_MAX, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_0_max_sub_ll){
	mu_assert(sat_signed_sub(0,LONG_MAX) == -LONG_MAX, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_min_0_add_ll){
	mu_assert(sat_signed_sub(LONG_MIN, 0) == LONG_MIN, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_min_sub_ll){
	mu_assert(sat_signed_sub(LONG_MIN,LONG_MIN) == 0, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_max_sub_ll){
	mu_assert(sat_signed_sub(LONG_MAX,LONG_MAX) == 0, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_neg_max_minus_1){
	mu_assert(sat_signed_sub(-LONG_MAX,1) == LONG_MIN, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_minus_1_max){
	mu_assert(sat_signed_sub(-1,LONG_MAX) == LONG_MIN, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_int_min_12){
	mu_assert(sat_signed_sub(12,(LONG_MIN+11)) == LONG_MAX, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_barely){
	mu_assert(sat_signed_sub(-1,LONG_MAX) == LONG_MIN, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_barely_not){
	mu_assert(sat_signed_sub(-1,(LONG_MAX-1)) == LONG_MIN+1, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_min_2){
	mu_assert(sat_signed_sub(LONG_MIN,-2) == LONG_MIN+2, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_2){
	mu_assert(sat_signed_sub(LONG_MIN,2) == LONG_MIN, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_alot){
	mu_assert(sat_signed_sub(LONG_MIN, LONG_MIN) == 0, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_min_max){
	mu_assert(sat_signed_sub(LONG_MIN, LONG_MAX) == LONG_MIN, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_max_min){
	mu_assert(sat_signed_sub(LONG_MAX, LONG_MIN) == LONG_MAX, "Signed Add: LONG_MAX + LONG_MIN");
}

MU_TEST(test_sub_max_max){
	mu_assert(sat_signed_sub(LONG_MAX, LONG_MAX) == 0, "Signed Add: LONG_MAX + LONG_MIN");
}
#endif

#if ARITHTYPE == 4
MU_TEST(test_max_uadd_char){
	mu_assert(sat_unsigned_add(UCHAR_MAX, UCHAR_MAX) == UCHAR_MAX*2, "Unsigned Add: UCHAR_MAX x 2");
}

MU_TEST(test_max_uadd_short){
	mu_assert(sat_unsigned_add(USHRT_MAX, USHRT_MAX) == USHRT_MAX*2, "Unsigned Add: SHRT_MAX x 2");
}

MU_TEST(test_max_uadd_int){
        unsigned long long expected = UINT_MAX;
        expected+=expected;
        unsigned long long got = sat_unsigned_add(UINT_MAX, UINT_MAX);
	mu_assert(got == expected, "Unsigned Add: UINT_MAX x 2");
}

MU_TEST(test_max_uadd_l){
        unsigned long long expected = ULONG_MAX;
        expected+=expected;
        unsigned long long got = sat_unsigned_add(ULONG_MAX, ULONG_MAX);
	mu_assert(expected == got, "Unsigned Add: ULONG_MAX x 2");
}

MU_TEST(test_max_uadd_ll){
	mu_assert(sat_unsigned_add(ULLONG_MAX, ULLONG_MAX) == ULLONG_MAX, "Unsigned Add: ULLONG_MAX x 2");
}

MU_TEST(test_barely_uadd_ll){
	mu_assert(sat_unsigned_add(4611686018427387904, 13835058055282163712) == ULLONG_MAX, "Unsigned Add: ULLONG_MAX x 2");
}


MU_TEST(test_max_add_ll){
	mu_assert(sat_signed_add(LLONG_MAX,LLONG_MAX) == LLONG_MAX, "Signed Add: LLONG_MAX x 2");
}

MU_TEST(test_negs_add_ll){
	mu_assert(sat_signed_add(-22738,-45631) == -68369, "Signed Add: Smaller than LLONG_MIN");
}

MU_TEST(test_min_add_ll){
	mu_assert(sat_signed_add(LLONG_MIN,LLONG_MIN) == LLONG_MIN, "Signed Add: LLONG_MIN x 2");
}

MU_TEST(test_exceed_add_ll){
	mu_assert(sat_signed_add(-9223372036854775807,-2000) == LLONG_MIN, "Signed Add: Bigger than LLONG_MIN");
}

MU_TEST(test_min_max_add_ll){
	mu_assert(sat_signed_add(LLONG_MAX,LLONG_MIN) == -1, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_neg_max_add_ll){
	mu_assert(sat_signed_add(2147483647,-2147483647) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_0_min_sub_ll){
	mu_assert(sat_signed_sub(0,LLONG_MIN) == LLONG_MAX, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_0_max_sub_ll){
	mu_assert(sat_signed_sub(0,LLONG_MAX) == -LLONG_MAX, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_min_0_add_ll){
	mu_assert(sat_signed_sub(LLONG_MIN, 0) == LLONG_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_min_sub_ll){
	mu_assert(sat_signed_sub(LLONG_MIN,LLONG_MIN) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_max_sub_ll){
	mu_assert(sat_signed_sub(LLONG_MAX,LLONG_MAX) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_neg_max_minus_1){
	mu_assert(sat_signed_sub(-LLONG_MAX,1) == LLONG_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_minus_1_max){
	mu_assert(sat_signed_sub(-1,LLONG_MAX) == LLONG_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_int_min_12){
	mu_assert(sat_signed_sub(12,(LLONG_MIN+11)) == LLONG_MAX, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_barely){
	mu_assert(sat_signed_sub(-1,LLONG_MAX) == LLONG_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_barely_not){
	mu_assert(sat_signed_sub(-1,(LLONG_MAX-1)) == LLONG_MIN+1, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_min_2){
	mu_assert(sat_signed_sub(LLONG_MIN,-2) == LLONG_MIN+2, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_2){
	mu_assert(sat_signed_sub(LLONG_MIN,2) == LLONG_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_alot){
	mu_assert(sat_signed_sub(LLONG_MIN, LLONG_MIN) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_min_max){
	mu_assert(sat_signed_sub(LLONG_MIN, LLONG_MAX) == LLONG_MIN, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_max_min){
	mu_assert(sat_signed_sub(LLONG_MAX, LLONG_MIN) == LLONG_MAX, "Signed Add: LLONG_MAX + LLONG_MIN");
}

MU_TEST(test_sub_max_max){
	mu_assert(sat_signed_sub(LLONG_MAX, LLONG_MAX) == 0, "Signed Add: LLONG_MAX + LLONG_MIN");
}

#endif

MU_TEST_SUITE(test_suite) {

#if ARITHTYPE == 0
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_max_uadd_char);
        MU_RUN_TEST(test_simple_uadd_char);
        MU_RUN_TEST(test_barely_uadd_char);
        MU_RUN_TEST(test_barely2_uadd_char);
        MU_RUN_TEST(test_barely3_uadd_char);

        MU_RUN_TEST(test_over_uadd_char);
#endif

#if ARITHTYPE == 1
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

 	MU_RUN_TEST(test_max_uadd_char);
 	MU_RUN_TEST(test_max_uadd_short);
 	MU_RUN_TEST(test_barely_uadd_ll);
 	MU_RUN_TEST(test_max_add_ll);
	MU_RUN_TEST(test_negs_add_ll);
	MU_RUN_TEST(test_min_add_ll); 
        MU_RUN_TEST(test_exceed_add_ll);
	MU_RUN_TEST(test_min_max_add_ll);
	MU_RUN_TEST(test_neg_max_add_ll);
	MU_RUN_TEST(test_0_min_sub_ll);
	MU_RUN_TEST(test_0_max_sub_ll);
	MU_RUN_TEST(test_min_0_add_ll);
	MU_RUN_TEST(test_min_sub_ll);
	MU_RUN_TEST(test_max_sub_ll);
#endif

#if ARITHTYPE == 3
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_max_uadd_char);

	MU_RUN_TEST(test_max_uadd_short);

        MU_RUN_TEST(test_max_uadd_int);

        MU_RUN_TEST(test_barely_uadd_ll);
        
        MU_RUN_TEST(test_min_max_add_ll);
        
        MU_RUN_TEST(test_neg_max_add_ll);
        
        MU_RUN_TEST(test_min_add_ll);
        
        MU_RUN_TEST(test_negs_add_ll);

        MU_RUN_TEST(test_max_add_ll);
        
        MU_RUN_TEST(test_exceed_add_ll);
        
        MU_RUN_TEST(test_0_min_sub_ll);

        MU_RUN_TEST(test_0_max_sub_ll); 

        MU_RUN_TEST(test_min_0_add_ll);

        MU_RUN_TEST(test_min_sub_ll);

        MU_RUN_TEST(test_max_sub_ll);
        
        MU_RUN_TEST(test_neg_max_minus_1);

        MU_RUN_TEST(test_minus_1_max);
        MU_RUN_TEST(test_int_min_12);
        MU_RUN_TEST(test_sub_barely);
        MU_RUN_TEST(test_sub_barely_not);
        MU_RUN_TEST(test_sub_min_2);
        MU_RUN_TEST(test_sub_2);
        MU_RUN_TEST(test_sub_alot);
        MU_RUN_TEST(test_sub_min_max);
        MU_RUN_TEST(test_sub_max_min);
        MU_RUN_TEST(test_sub_min_max);
        MU_RUN_TEST(test_sub_max_max);
#endif


#if ARITHTYPE == 2
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_max_uadd_char);

	MU_RUN_TEST(test_max_uadd_short);

        MU_RUN_TEST(test_max_uadd_int);

        MU_RUN_TEST(test_barely_uadd_ll);
        
        MU_RUN_TEST(test_min_max_add_ll);
        
        MU_RUN_TEST(test_neg_max_add_ll);
        
        MU_RUN_TEST(test_min_add_ll);
        
        MU_RUN_TEST(test_negs_add_ll);

        MU_RUN_TEST(test_max_add_ll);
        
        MU_RUN_TEST(test_exceed_add_ll);
        
        MU_RUN_TEST(test_0_min_sub_ll);

        MU_RUN_TEST(test_0_max_sub_ll); 

        MU_RUN_TEST(test_min_0_add_ll);

        MU_RUN_TEST(test_min_sub_ll);

        MU_RUN_TEST(test_max_sub_ll);
        
        MU_RUN_TEST(test_neg_max_minus_1);

        MU_RUN_TEST(test_minus_1_max);
        MU_RUN_TEST(test_int_min_12);
        MU_RUN_TEST(test_sub_barely);
        MU_RUN_TEST(test_sub_barely_not);
        MU_RUN_TEST(test_sub_min_2);
        MU_RUN_TEST(test_sub_2);
        MU_RUN_TEST(test_sub_alot);
        MU_RUN_TEST(test_sub_min_max);
        MU_RUN_TEST(test_sub_max_min);
        MU_RUN_TEST(test_sub_min_max);
        MU_RUN_TEST(test_sub_max_max);
#endif

#if ARITHTYPE == 4
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_max_uadd_char);

	MU_RUN_TEST(test_max_uadd_short);

        MU_RUN_TEST(test_max_uadd_int);

	MU_RUN_TEST(test_max_uadd_l);

        MU_RUN_TEST(test_max_uadd_ll);

        MU_RUN_TEST(test_barely_uadd_ll);
        
        MU_RUN_TEST(test_min_max_add_ll);
        
        MU_RUN_TEST(test_neg_max_add_ll);
        
        MU_RUN_TEST(test_min_add_ll);
        
        MU_RUN_TEST(test_negs_add_ll);

        MU_RUN_TEST(test_max_add_ll);
        
        MU_RUN_TEST(test_exceed_add_ll);
        
        MU_RUN_TEST(test_0_min_sub_ll);

        MU_RUN_TEST(test_0_max_sub_ll); 

        MU_RUN_TEST(test_min_0_add_ll);

        MU_RUN_TEST(test_min_sub_ll);

        MU_RUN_TEST(test_max_sub_ll);
        
        MU_RUN_TEST(test_neg_max_minus_1);

        MU_RUN_TEST(test_minus_1_max);
        MU_RUN_TEST(test_int_min_12);
        MU_RUN_TEST(test_sub_barely);
        MU_RUN_TEST(test_sub_barely_not);
        MU_RUN_TEST(test_sub_min_2);
        MU_RUN_TEST(test_sub_2);
        MU_RUN_TEST(test_sub_alot);
        MU_RUN_TEST(test_sub_min_max);
        MU_RUN_TEST(test_sub_max_min);
        MU_RUN_TEST(test_sub_min_max);
        MU_RUN_TEST(test_sub_max_max);
#endif
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
