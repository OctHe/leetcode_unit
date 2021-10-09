/*
 * Problem 54: Medium
 * Key words: Search; State machine
 * Link: https://leetcode.com/problems/spiral-matrix/
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

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> coordinate(2, 0);
        int rows = matrix.size(), columns = matrix[0].size();
        
        int direct = 0; //direct: right->down->left->up: 0->1->2->3

        vector<int> output;
        
        while(1)
        {
            int move = 0;

            switch(direct)
            {
            case 0:
                while(move++ < columns)
                    output.push_back(matrix[coordinate[0]][coordinate[1]++]);

                rows--;
                coordinate[0]++;
                coordinate[1]--;
                direct = 1;
                break;

            case 1:
                while(move++ < rows)
                    output.push_back(matrix[coordinate[0]++][coordinate[1]]);
                
                columns--;
                coordinate[0]--;
                coordinate[1]--;
                direct = 2;
                break;

            case 2:
                while(move++ < columns)
                    output.push_back(matrix[coordinate[0]][coordinate[1]--]);
                
                rows--;
                coordinate[0]--;
                coordinate[1]++;
                direct = 3;
                break;

            case 3:
                while(move++ < rows)
                    output.push_back(matrix[coordinate[0]--][coordinate[1]]);
                
                columns--;
                coordinate[0]++;
                coordinate[1]++;
                direct = 0;
                break;
            }

            if(output.size() == matrix.size() * matrix[0].size())
                break;
        }

        return output;
    }
    
};

class test_problem_54 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_54 );

        CPPUNIT_TEST( test_case_54 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_54();

};
