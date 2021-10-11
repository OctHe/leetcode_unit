#include "146_LRU_Cache.h"

void test_problem_146::test_case_146()
{

    LRUCache *lRUCache = new LRUCache(2);

    lRUCache->put(1, 1);                        // cache is {1=1}
    lRUCache->put(2, 2);                        // cache is {1=1, 2=2}
    CPPUNIT_ASSERT(lRUCache->get(1) == 1);      // returns 1
    lRUCache->put(3, 3);                        // evicts key 2, cache is {1=1, 3=3}
    CPPUNIT_ASSERT(lRUCache->get(2) == -1);     // returns -1 (not found)
    lRUCache->put(4, 4);                        // evicts key 1, cache is {4=4, 3=3}
    CPPUNIT_ASSERT(lRUCache->get(1) == -1);     // return -1 (not found)
    CPPUNIT_ASSERT(lRUCache->get(3));           // return 3
    CPPUNIT_ASSERT(lRUCache->get(4));           // return 4
}

CPPUNIT_TEST_SUITE_REGISTRATION(test_problem_146);

int main( int argc, char **argv)
{

    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest( registry.makeTest() );
    runner.run();

    return 0;
}
