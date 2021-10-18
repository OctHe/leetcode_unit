#include "394_Decode_String.h"

void test_problem_394::test_case_394()
{
    CPPUNIT_ASSERT(s->decodeString("3[a]2[bc]") == "aaabcbc");
    CPPUNIT_ASSERT(s->decodeString("3[a2[c]]") == "accaccacc");
    CPPUNIT_ASSERT(s->decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    CPPUNIT_ASSERT(s->decodeString("abc3[cd]xyz") == "abccdcdcdxyz");
    CPPUNIT_ASSERT(s->decodeString("10[leetcode]") == "leetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcodeleetcode");
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_394);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
