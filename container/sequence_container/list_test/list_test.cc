#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <list>

void printLists(const std::list<int>& l1, const std::list<int>& l2) {
  std::cout << "list1: ";
  std::copy(l1.cbegin(), l1.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl << "list2: ";
  std::copy(l2.cbegin(), l2.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
void printLists(const std::string& s, const std::forward_list<int>& l1, const std::forward_list<int>& l2) {
    std::cout<<s<<std::endl;
  std::cout << "list1: ";
  std::copy(l1.cbegin(), l1.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl << "list2: ";
  std::copy(l2.cbegin(), l2.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

int main() {
  std::list<char> coll;

  for (char c = 'a'; c <= 'z'; ++c) {
    coll.push_back(c);
  }
  for (auto elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  std::list<char>::const_iterator cpos;
  for (cpos = coll.begin(); cpos != coll.end(); ++cpos) {
    std::cout << *cpos << ' ';
  }
  std::cout << std::endl;

  std::list<char>::iterator pos;
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    *pos = toupper(*pos);
    std::cout << *pos << ' ';
  }
  std::cout << std::endl;

  while (!coll.empty()) {
    std::cout << coll.front() << ' ';
    coll.pop_front();
  }
  std::cout << std::endl;

  std::forward_list<long> f_coll = {2, 3, 5, 7, 11, 13, 17};
  f_coll.resize(9);
  f_coll.resize(10, 99);

  for (auto elem : f_coll) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  std::list<int> list1, list2;
  for(int i = 0; i < 6; ++i) {
      list1.push_back(i);
      list2.push_back(i);
  }
  printLists(list1, list2);

  list2.splice(std::find(list2.begin(), list2.end(), 3), list1);
  printLists(list1, list2);

  list2.splice(list2.end(), list2, list2.begin());
  printLists(list1, list2);

  list2.sort();
  list1 = list2;
  list2.unique();
  printLists(list1, list2);

  list1.merge(list2);
  printLists(list1, list2);

  std::forward_list<int> flist1 = {1,2,3,4};
  std::forward_list<int> flist2 = {77, 88, 99};
  printLists("initial: ", flist1, flist2);

  flist2.insert_after(flist2.before_begin(), 99);
  flist2.push_front(10);
  flist2.insert_after(flist2.before_begin(), {10,11,12,13});
  printLists("6 new elems: ", flist1, flist2);

  flist1.insert_after(flist1.before_begin(), flist2.begin(), flist2.end());
  printLists("list2 into list1: ", flist1, flist2);

  flist2.erase_after(flist2.begin());
  flist2.erase_after(std::find(flist2.begin(), flist2.end(), 99), flist2.end());
  printLists("delete 2nd and after 99: ", flist1, flist2);

  flist1.sort();
  flist2 = flist1;
  flist2.unique();
  printLists("sorted and unique: ", flist1, flist2);

  flist1.merge(flist2);
  printLists("merged: ", flist1, flist2);

}
