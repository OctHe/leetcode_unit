/*
 * Problem 121: Medium
 * Key words: Dynamic programming
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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
    int maxProfit(vector<int>& prices) 
    {

        int buy = prices[0], sell = prices[0];
        int profit = 0, best_profit = 0;
        
        // buy: the best buy day untill today
        // sell: sell it today
        // profit: the profit of sell it today
        // best_profit: the best profit until today
        for(int i = 1; i < prices.size(); i++)
        {
            sell = prices[i];
            profit = max(sell-buy, 0);
            buy = min(buy, sell);
            best_profit = max(best_profit, profit);
        }
        
        return best_profit;
    }
};

class test_problem_121 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_121 );

        CPPUNIT_TEST( test_case_121 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_121();

};
