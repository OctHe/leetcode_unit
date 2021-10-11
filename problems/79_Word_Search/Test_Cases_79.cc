#include "79_Word_Search.h"

void test_problem_79::test_case_79()
{
    vector< vector<char> > board = 
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    CPPUNIT_ASSERT(s->exist(board, "ABCCED") == true);
    CPPUNIT_ASSERT(s->exist(board, "ABCB") == false);

    board = 
    {
        {'A', 'B'},
        {'C', 'D'}
    };
    CPPUNIT_ASSERT(s->exist(board, "CDBA") == true);

    board = 
    {
        {'C', 'A', 'A'},
        {'A', 'A', 'A'},
        {'B', 'C', 'D'}
    };
    CPPUNIT_ASSERT(s->exist(board, "AAB") == true);
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_79);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
