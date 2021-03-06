/*
 * Problem 4 (Hard)
 * Key words: Sorting array
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

#include <climits>

class Solution 
{

public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        
        int m = nums1.size();
        int n = nums2.size();

        if( (m+n) % 2 ) return kthElement(nums1, nums2, (m+n-1) / 2);

        int a = kthElement(nums1, nums2, (m+n) / 2 - 1);
        int b = kthElement(nums1, nums2, (m+n) / 2);

        return (a + b) / 2.0;
    }


    // ****************************************************************
    //                          Helper functions
    // ****************************************************************
    // kth element: Find the kth elements in two vectors. The first index starts from 0
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int m = nums1.size(), n = nums2.size();
        int low = max(0, k + 1 - n), high = min(m, k + 1);
        
        // Array visualization
        // ---------A     C---------
        // ---------B     D---------
        int A, B, C, D;

       // x means the index of nums1
       // x + y == k
        int x, y; 

        while(1)
        {
            x = (low + high) / 2;
            y = k + 1 - x;  // x + y == k

            // INT_MAX and INT_MIN are used for special case
            // For example, if m == 0, then A == INT_MIN
            A = ( x == 0 ) ? INT_MIN : nums1[x - 1];
            B = ( y == 0 ) ? INT_MIN : nums2[y - 1];
            C = ( x == m ) ? INT_MAX : nums1[x];
            D = ( y == n ) ? INT_MAX : nums2[y];


            if( A <= D && B <= C)
            {
                // x, y is the target
                break;
            }
            else if (A > D)
                high = x;
            else
                low = x + 1;

        }

        // Find the max value from x and y
        // INT_MIN is used for special case
        int a = (x > 0) ? nums1[x - 1] : INT_MIN;
        int b = (y > 0) ? nums2[ y - 1] : INT_MIN;
        return max(a, b);

    }
    
};

class test_problem_4 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_4 );

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
