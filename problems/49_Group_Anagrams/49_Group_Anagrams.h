/*
 * Problem 49: Medium
 * Key words: Unordered_multiset; Unordered_multimap
 * Link: https://leetcode.com/problems/group-anagrams/
 */
#include <iostream>
#include <climits>
#include <vector>
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
    vector<vector<string>> groupAnagrams_multiset(vector<string>& strs)
    {
        vector< vector<string> > group;
        vector< unordered_multiset<char> > alphabat;

        for(unsigned i = 0; i < strs.size(); i++)
        {
            int exist_group_ite = 0;
            unordered_multiset<char> str_set;

            // Get the alphabat of this string
            for(unsigned j = 0; j < strs[i].size(); j++)
                str_set.insert(strs[i][j]);

            // Check whether the str is in an existed group.
            for(exist_group_ite = 0; exist_group_ite < group.size(); exist_group_ite++)
                if(alphabat[exist_group_ite] == str_set)
                    break;

            if(exist_group_ite == group.size())
            {
                // Add string into a new group
                group.push_back(vector<string>(1, strs[i]));
                alphabat.push_back(str_set);
            }
            else
                // Add string into an existing group
                group[exist_group_ite].push_back(strs[i]);
            
            // Clear the alphabat of this string
            str_set.clear();
        }

        return group;
    }
    
    vector<vector<string>> groupAnagrams_map(vector<string>& strs)
    {
        unordered_map< string, vector<string> > strs_map;
        vector< vector<string> > ret;

        for(unsigned i = 0; i < strs.size(); i++)
        {
            string str = strs[i];

            sort(str.begin(), str.end());

            strs_map[str].push_back(strs[i]);
        }

        for(unordered_map< string, vector<string> >::iterator i = strs_map.begin(); i != strs_map.end(); i++)
            ret.push_back(i->second);

        return ret;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        
        return groupAnagrams_multiset(strs);
        // return groupAnagrams_map(strs);
    }
};

class test_problem_49 : public CppUnit::TestFixture  
{
    private:
        Solution *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_49 );

        CPPUNIT_TEST( test_case_49 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() { s = new Solution(); }
        void tearDown() { delete s; }

        // Test cases
        void test_case_49();

};
