#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Solutions.h"

class test_problem_4_findMedianSortedArrays : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( test_problem_4_findMedianSortedArrays );

        // Add unit tests into the suite
        CPPUNIT_TEST( test_case_4_common_vectors );
        CPPUNIT_TEST( test_case_4_empty_nums1 );
        CPPUNIT_TEST( test_case_4_empty_nums2 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_4_common_vectors();
        void test_case_4_empty_nums1();
        void test_case_4_empty_nums2();

};

class test_problem_10_isMatch : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( test_problem_10_isMatch );

        // Add unit tests into the suite
        CPPUNIT_TEST( test_case_10_complicate_case );
        CPPUNIT_TEST( test_case_10_repeat_zero_time );
        CPPUNIT_TEST( test_case_10_repeat_one_time_true_case );
        CPPUNIT_TEST( test_case_10_dot_case );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_10_complicate_case();
        void test_case_10_repeat_zero_time();
        void test_case_10_repeat_one_time_true_case();
        void test_case_10_dot_case();

};

class test_problem_26_removeDuplicates : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( test_problem_26_removeDuplicates );

        // Add unit tests into the suite
        CPPUNIT_TEST( test_case_26_common_vectors );
        CPPUNIT_TEST( test_case_26_empty_vector );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_26_common_vectors();
        void test_case_26_empty_vector();

};

class test_problem_36_isValidSudoku : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( test_problem_36_isValidSudoku );

        // Add unit tests into the suite
        CPPUNIT_TEST( test_case_36 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_36();

};

class test_problem_37_solveSudoku : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( test_problem_37_solveSudoku );

        // Add unit tests into the suite
        CPPUNIT_TEST( test_case_37_single_array );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_37_single_array();
};

class test_problem_53_maxSubArray : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( test_problem_53_maxSubArray );

        // Add unit tests into the suite
        CPPUNIT_TEST( test_case_53_common_vector );
        CPPUNIT_TEST( test_case_53_one_element );
        CPPUNIT_TEST( test_case_53_all_elements );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_53_common_vector();
        void test_case_53_one_element();
        void test_case_53_all_elements();

};