#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Solutions.h"

class MySolutionTest : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        CPPUNIT_TEST_SUITE( MySolutionTest );

        // Add your own unit tests into the suite
        CPPUNIT_TEST( test_case_4_common_vectors );
        CPPUNIT_TEST( test_case_4_empty_nums1 );
        CPPUNIT_TEST( test_case_4_empty_nums2 );

        CPPUNIT_TEST( test_case_26_common_vectors );
        CPPUNIT_TEST( test_case_26_empty_vector );

        CPPUNIT_TEST( test_case_36_true_case );
        CPPUNIT_TEST( test_case_36_false_case );

        CPPUNIT_TEST( test_case_37_single_case );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp()
        {
          s = new Solution();
        }

        void tearDown() 
        {
            delete s;
        }

        // Test cases
        void test_case_4_common_vectors();
        void test_case_4_empty_nums1();
        void test_case_4_empty_nums2();
        
        void test_case_26_common_vectors();
        void test_case_26_empty_vector();
        
        void test_case_36_true_case();
        void test_case_36_false_case();

        void test_case_37_single_case();

};

