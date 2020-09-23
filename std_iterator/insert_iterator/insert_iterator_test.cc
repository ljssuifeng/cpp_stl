#include <iterator>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <algorithm>

template<typename T>
void print_elements(const T& a) {
    for(auto& elem:a) {
        std::cout<<elem<<' ';
    }
    std::cout<<std::endl;
}

int main() {
    std::list<int> coll = {1, 2,3,4,5,6,7,8,9};
    std::vector<int> coll2;
    //back_inserter(container) need container have function: push_back()
    std::copy(coll.cbegin(), coll.cend(), std::back_inserter(coll2));
    print_elements(coll2);

    std::deque<int> coll3;
    //front_inserter(container) need container have function: push_front()
    std::copy(coll.cbegin(), coll.cend(), std::front_inserter(coll3));
    print_elements(coll3);

    std::set<int> coll4;
    //general inserter,   inserter(container, pos)
    std::copy(coll.cbegin(), coll.cend(), std::inserter(coll4, coll4.begin()));
    print_elements(coll4);
}




