/*
 * Problem 146: Medium
 * Key words: unordered_map; list (double list)
 * Link: https://leetcode.com/problems/lru-cache/
 */
#include <iostream>
#include <climits>
#include <vector>
#include <list>
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

class LRUCache 
{
private:
    int capacity;
    list< pair<int, int> > cache;
    unordered_map< int, list< pair<int, int> >::iterator > cache_pointers;
    
public:

    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
       if(cache_pointers.find(key) == cache_pointers.end())
            return -1;

        // Update the cache
        cache.splice(cache.begin(), cache, cache_pointers[key]);

        return cache_pointers[key]->second;
    }
    
    void put(int key, int value) 
    {
        if(cache_pointers.find(key) == cache_pointers.end())
        {
            // Remove the least recently used pair
            if(cache.size() == capacity)
            {
                // The erased key is cache.back(), which
                // is the last element of the list
                cache_pointers.erase(cache.back().first);
                cache.pop_back();
            }

            // Insert a new key-value pair into the list
            cache.push_front(pair<int, int>{key, value});

            // Insert an iterator into the map
            cache_pointers[key] = cache.begin();
        }
        else
        {
            // Update the cache
            // The element at cache_pointers[key] will be transfered into 
            // cache before cache.begin()
            // The process costs constant complexity
            cache.splice(cache.begin(), cache, cache_pointers[key]);

            // Update an old key-value pair
            cache_pointers[key]->second = value;
        }

    }
    
};

class test_problem_146 : public CppUnit::TestFixture  
{
    private:
        LRUCache *s;

        // Test suite
        CPPUNIT_TEST_SUITE( test_problem_146 );

        CPPUNIT_TEST( test_case_146 );

        CPPUNIT_TEST_SUITE_END();

    public:
        void setUp() {}
        void tearDown() {}

        // Test cases
        void test_case_146();

};
