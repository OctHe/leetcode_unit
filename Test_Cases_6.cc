#include "MyTestCases.h"

void test_problem_6_convert::test_case_6_common_strings()
{
    CPPUNIT_ASSERT( s->convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CPPUNIT_ASSERT( s->convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CPPUNIT_ASSERT( s->convert("A", 1) == "A");
}
