#include "33_Search_in_Rotated_Sorted_Array.h"

void test_problem_33::test_case_33()
{
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    CPPUNIT_ASSERT(s->search(nums1, 0) == 4);
    CPPUNIT_ASSERT(s->search(nums1, 3) == -1);

    vector<int> nums2 = {1, 3};
    CPPUNIT_ASSERT(s->search(nums2, 3) == 1);

    vector<int> nums3 = {3, 5, 1};
    CPPUNIT_ASSERT(s->search(nums3, 3) == 0);

    vector<int> nums4 = {5, 1, 3};
    CPPUNIT_ASSERT(s->search(nums4, 3) == 2);

}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_33);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
