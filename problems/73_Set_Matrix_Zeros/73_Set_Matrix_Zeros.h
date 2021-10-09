/*
 * Problem 73: Medium
 * Key words: Matrix; Search
 * Link: https://leetcode.com/problems/set-matrix-zeroes/
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

    /*
     * 1. matrix[0][:] saves the state of each row.
     * 2. matrix[:][0] saves the state of each column
     *      except column 0, because matrix[0][0] is
     *      used by the rows.
     * 3. We use an extra variable col0 to indicate 
     *      the state of column 0
     * 4. We do not need to treat row 0 or column 0 as
     *      special cases, because we will access the
     *      elements of row 0 and column 0 before we 
     *      change the state, and the states of them 
     *      will be saved in matrix[0][0] and col0
     */
    void setZeroes(vector<vector<int>>& matrix)
    {
        int col0 = 1;
        int rows = matrix.size(), columns = matrix[0].size();

        for (int i = 0; i < rows; i++) 
        {
            if (matrix[i][0] == 0) col0 = 0;

            for (int j = 1; j < columns; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows -1; i >= 0; i--) 
        {
            for (int j = columns - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
    
};

class test_problem_73 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_73 );

        CPPUNIT_TEST( test_case_73 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_73();

};
