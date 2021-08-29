#include "MyUnitTests.h"

void test_problem_10_isMatch::test_case_10_complicate_case()
{
    CPPUNIT_ASSERT( s->isMatch("aab", "c*a*b") == true );
    CPPUNIT_ASSERT( s->isMatch("aaa", "ab*a*c*a") == true );

    CPPUNIT_ASSERT( s->isMatch("aaba", "ab*a*c*a") == false );
    CPPUNIT_ASSERT( s->isMatch("mississippi", "mis*is*p*.") == false );
}

void test_problem_10_isMatch::test_case_10_repeat_zero_time()
{

    CPPUNIT_ASSERT( s->isMatch("aaa", "ab*a") == false );
    CPPUNIT_ASSERT( s->isMatch("aaa", "ab*ac*a") == true );
}

void test_problem_10_isMatch::test_case_10_repeat_one_time_true_case()
{
    CPPUNIT_ASSERT( s->isMatch("aa", "a*") == true );
}

void test_problem_10_isMatch::test_case_10_dot_case()
{
    CPPUNIT_ASSERT( s->isMatch("a", ".*") == true );
    CPPUNIT_ASSERT( s->isMatch("ab", ".*") == true );
    CPPUNIT_ASSERT( s->isMatch("aaa", ".*") == true );

    CPPUNIT_ASSERT( s->isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s") == true );
}
