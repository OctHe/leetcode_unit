#include "4_Median_of_Two_Sorted_Arrays.h"

void test_problem_4::test_case_4_common_vectors()
{
    vector< vector<int> > nums1 = {{1,3}, {1, 2}};
    vector< vector<int> > nums2 = {{2}, {3, 4}};

    vector<double> res = {2.0, 2.5};

    for(unsigned i = 0; i < nums1.size(); i++)
        CPPUNIT_ASSERT_DOUBLES_EQUAL(res[i], s->findMedianSortedArrays(nums1[i], nums2[i]), 0.01);
}

void test_problem_4::test_case_4_empty_nums1()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1};

    double res = 1.0;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(res, s->findMedianSortedArrays(nums1, nums2), 0.01);
}

void test_problem_4::test_case_4_empty_nums2()
{
    vector<int> nums1 = {2};
    vector<int> nums2 = {};

    double res = 2.0;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(res, s->findMedianSortedArrays(nums1, nums2), 0.01);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_4);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
