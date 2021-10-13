/*
 * Problem 189: Easy/Medium/Hard
 * Key words:
 * Link: 
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

    // Time limit exceeded
    void rotate_recursive(vector<int>& nums, int k)
    {
        if(nums.size() == 0 || k == 0) return;
        
        if(k == 1)
        {
            int temp = nums[nums.size()-1];
            for(int i = nums.size()-1; i > 0; i--)
                nums[i] = nums[i-1];
            
            nums[0] = temp;
            
            return;
        }
        
        rotate_recursive(nums, 1);
        rotate_recursive(nums, k-1);
    }

    void rotate_new_vector(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int> new_nums(nums.begin(), nums.end());

        for(int i = 0, j = k; i < n; i++, j++)
            nums[j % n] = new_nums[i];
        
    }
    
    void rotate_reverse(vector<int>& nums, int k) 
    {
        // k = k % nums.size();
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }


    void rotate(vector<int>& nums, int k)
    {

        // rotate_recursive(nums, k);
        // rotate_new_vector(nums, k);
        rotate_reverse(nums, k);
    }
    
};

class test_problem_189 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_189 );

        CPPUNIT_TEST( test_case_189 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_189();

};
