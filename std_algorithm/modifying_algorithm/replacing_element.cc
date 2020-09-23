//void replace(ForwardIterator beg, ForwardIterator end, const T& oldValue, const T& Value);
//void replace_if(ForwardIterator beg, ForwardIterator end, UnaryPredicate op, const T& newValue);

#include "algorithm_test.hpp"

int main() {
    std::list<int> coll;
    INSERT_ELEMENTS(coll, 2, 7);
    INSERT_ELEMENTS(coll, 4, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    //replace all elements with value 6 with 42
    std::replace(coll.begin(), coll.end(), 6, 42);
    PRINT_ELEMENTS(coll, "coll: ");

    //replace all elements with value less than 5 with 0
    std::replace_if(coll.begin(), coll.end(), [](int elem){return elem < 5;}, 0);
    PRINT_ELEMENTS(coll, "coll: ");
}
