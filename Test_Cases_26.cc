#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "MyUnitTests.h"

void test_problem_26_removeDuplicates::test_case_26_common_vectors()
{
    vector< vector<int> > in_vec = {
        {1, 1, 2}, 
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
  };

    vector< vector<int> > res = {
        {1, 2},
        {0, 1, 2, 3, 4}
    };

    for(unsigned i = 0; i < in_vec.size(); i++)
    {
        int n = s->removeDuplicates(in_vec[i]);

        CPPUNIT_ASSERT( n == res[i].size() );
        for(unsigned j = 0; j < res[i].size(); j++)
            CPPUNIT_ASSERT( res[i][j] == in_vec[i][j] );
    }
}

void test_problem_26_removeDuplicates::test_case_26_empty_vector()
{
    vector<int> in_vec = {};
    vector<int> res = {};
    int n = s->removeDuplicates(in_vec);

    CPPUNIT_ASSERT(n == res.size());
    CPPUNIT_ASSERT(in_vec == res);

}
        
