#include "5_Longest_Palindromic_Substring.h"

void test_problem_5::test_case_5()
{

    CPPUNIT_ASSERT( s->longestPalindrome("babad") == "bab" ||  s->longestPalindrome("babad") == "aba" );
    CPPUNIT_ASSERT( s->longestPalindrome("abbd") == "bb" );
    CPPUNIT_ASSERT( s->longestPalindrome("a") == "a" );
    CPPUNIT_ASSERT( s->longestPalindrome("ac") == "a" ||  s->longestPalindrome("ac") == "c" );
    CPPUNIT_ASSERT( s->longestPalindrome("ccc") == "ccc" );
    CPPUNIT_ASSERT( s->longestPalindrome("aaaaa") == "aaaaa" );
    CPPUNIT_ASSERT( s->longestPalindrome("aacabdkacaa") == "aca" );

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_5);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
