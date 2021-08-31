#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Solutions.h"

class test_problem_4_findMedianSortedArrays : public CppUnit::TestFixture  
{
    private:
        Solution *s;

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_4_common_vectors();
        void test_case_4_empty_nums1();
        void test_case_4_empty_nums2();

        // Test Suite
        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_4" );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_4_findMedianSortedArrays>( 
                                        "test_common_vectors", 
                                        &test_problem_4_findMedianSortedArrays::test_case_4_common_vectors ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_4_findMedianSortedArrays>( 
                                        "test_empty_nums1", 
                                        &test_problem_4_findMedianSortedArrays::test_case_4_empty_nums1 ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_4_findMedianSortedArrays>( 
                                        "test_empty_nums2", 
                                        &test_problem_4_findMedianSortedArrays::test_case_4_empty_nums2 ) );
            return suiteOfTests;
        }
};

class test_problem_10_isMatch : public CppUnit::TestFixture  
{
    private:
        Solution *s;

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_10_complicate_cases();
        void test_case_10_repeat_zero_time();
        void test_case_10_repeat_one_time();
        void test_case_10_dot_cases();

        // Test Suite
        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_10" );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_10_isMatch>( 
                                        "test_complicate_cases", 
                                        &test_problem_10_isMatch::test_case_10_complicate_cases ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_10_isMatch>( 
                                        "test_star_repeats_zero_time", 
                                        &test_problem_10_isMatch::test_case_10_repeat_zero_time ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_10_isMatch>( 
                                        "test_star_repeats_one_time", 
                                        &test_problem_10_isMatch::test_case_10_repeat_one_time ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_10_isMatch>( 
                                        "test_dot_cases", 
                                        &test_problem_10_isMatch::test_case_10_dot_cases ) );
            return suiteOfTests;
        }
};

class test_problem_26_removeDuplicates : public CppUnit::TestFixture  
{
    private:
        Solution *s;

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_26_common_vectors();
        void test_case_26_empty_vector();

        // Test Suite
        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_26" );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_26_removeDuplicates>( 
                                        "test_common_vectors", 
                                        &test_problem_26_removeDuplicates::test_case_26_common_vectors ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_26_removeDuplicates>( 
                                        "test_empty_vector", 
                                        &test_problem_26_removeDuplicates::test_case_26_empty_vector ) );
            return suiteOfTests;
        }

};

class test_problem_36_isValidSudoku : public CppUnit::TestFixture  
{
    private:
        Solution *s;

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_36();

        // Test Suite
        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_36" );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_36_isValidSudoku>( 
                                        "test_true_and_false", 
                                        &test_problem_36_isValidSudoku::test_case_36 ) );
            return suiteOfTests;
        }
};

class test_problem_37_solveSudoku : public CppUnit::TestFixture  
{
    private:
        Solution *s;

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_37_single_array();

        // Test Suite
        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_37" );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_37_solveSudoku>( 
                                        "test_single_array", 
                                        &test_problem_37_solveSudoku::test_case_37_single_array ) );
            return suiteOfTests;
        }
};

class test_problem_53_maxSubArray : public CppUnit::TestFixture  
{
    private:
        Solution *s;

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_53_common_vector();
        void test_case_53_one_element();
        void test_case_53_all_elements();

        // Test Suite
        static CppUnit::Test *suite()
        {
            CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "test_Problem_53" );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_53_maxSubArray>( 
                                        "test_common_vector", 
                                        &test_problem_53_maxSubArray::test_case_53_common_vector ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_53_maxSubArray>( 
                                        "test_one_element", 
                                        &test_problem_53_maxSubArray::test_case_53_one_element ) );
            suiteOfTests->addTest( new CppUnit::TestCaller<test_problem_53_maxSubArray>( 
                                        "test_all_elements", 
                                        &test_problem_53_maxSubArray::test_case_53_all_elements ) );
            return suiteOfTests;
        }
};