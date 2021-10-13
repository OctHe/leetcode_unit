/*
 * Problem 198: Medium
 * Key words: Dynamic programming; Two pointers
 * Link: https://leetcode.com/problems/house-robber/
 */
#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

using namespace std;

class Solution 
{

public:

    int rob_two_pointers(vector<int>& nums)
    {
        /*
         * pre: we must to stole room i
         * cur: we have stolen room i-1, so we 
         *      cannot stole this room
         * 
         * pre: the max money up to i-1
         * cur: the max money up to i
         */
        int pre = 0, cur = 0, max_money = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            max_money = max(pre + nums[i], cur);
            pre = cur;
            cur = max_money;
        }
        return max_money;

    }

    /*
     * Traveral: 
     * 1: 1
     * 2: 1;                                2
     * 3: 1->3;                             2
     * 4: 1->3;                 1->4;       2->4;
     * 5: 1->3->5;              1->4;       2->4;       2->5
     * 6: 1->3->5;  1->3->6;    1->4->6;    2->4->6;    2->5
     */
    int rob_dp(vector<int>& nums)
    {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> money(nums.size(), 1);
        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);
        money[2] = max(money[0] + nums[2], money[1]);

        for(unsigned i = 3; i < nums.size(); i++)
        {
            money[i] = max(money[i-3], money[i-2]) + nums[i];
            money[i] = max(money[i-1], money[i]);
        }

        return *(money.end()-1);
    }

    int rob(vector<int>& nums)
    {
        // return rob_dp(nums);
        return rob_two_pointers(nums);
    }
    
};

class test_problem_198 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_198 );

        CPPUNIT_TEST( test_case_198 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_198();

};
