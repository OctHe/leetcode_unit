#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "MyUnitTests.h"

void MySolutionTest::test_case_4_common_vectors()
{
    vector< vector<int> > nums1 = {{1,3}, {1, 2}};
    vector< vector<int> > nums2 = {{2}, {3, 4}};

    vector<double> res = {2.0, 2.5};

    for(unsigned i = 0; i < nums1.size(); i++)
        CPPUNIT_ASSERT_DOUBLES_EQUAL(res[i], s->findMedianSortedArrays(nums1[i], nums2[i]), 0.01);
}

void MySolutionTest::test_case_4_empty_nums1()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1};

    double res = 1.0;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(res, s->findMedianSortedArrays(nums1, nums2), 0.01);
}

void MySolutionTest::test_case_4_empty_nums2()
{
    vector<int> nums1 = {2};
    vector<int> nums2 = {};

    double res = 2.0;

    CPPUNIT_ASSERT_DOUBLES_EQUAL(res, s->findMedianSortedArrays(nums1, nums2), 0.01);
}
