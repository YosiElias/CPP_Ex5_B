//#include <string>
//#include <vector>
//#include <algorithm>
//#include "doctest.h"
//#include "OrgChart.hpp"
//
//using namespace std;
//using namespace ariel;
//
//TEST_CASE("Bad input") {
//    OrgChart o;
//    CHECK_THROWS(o.add_root(""));
//    o.add_root("Yossi");
//    CHECK_THROWS(o.add_sub("Avi", "Moshe"));
//    CHECK_THROWS(cout << o << endl;);
//    CHECK_THROWS(OrgChart copy = o);    //internal use-not allow copy constructor
//
//
//}
//TEST_CASE("Insert the same name") {
//    //insert the same name:
//    OrgChart o;
//    for (int i = 0; i < 10; i++) {
//                CHECK_NOTHROW(o.add_root("Same Name"));
//    }
//    //for each not throw error:
//    CHECK_NOTHROW(for (string element : o){cout << element << " " ;});
//}
//TEST_CASE("Case 1") {
//    OrgChart o;
//    CHECK_NOTHROW(o.add_root("A")
//            .add_sub("A", "a1")
//            .add_sub("A", "B")
//            .add_sub("A", "a2")
//            .add_sub("B", "b1")
//            .add_sub("A", "a3"));
//    CHECK_FALSE(o.begin_reverse_order() == o.begin_level_order());
//    CHECK_FALSE(o.reverse_order() == o.end_level_order());
//    CHECK_EQ(o.begin_reverse_order(), o.end_level_order());
//    vector<string> result = {"A", "a1", "B", "b1", "a2", "a3"};
//    size_t i =0;
//    for (auto it=o.begin_preorder(); it!=o.end_preorder(); ++it) {
//        CHECK_EQ((*it),result.at(i));
//        i++;
//    }
//    result.clear();
//    result = {"A", "a1", "B", "a2", "a3", "b1"};
//    i =0;
//    for (auto it=o.begin_level_order(); it!=o.end_level_order(); ++it) {
//                CHECK_EQ((*it),result.at(i));
//        i++;
//    }
//    result = {"b1", "a3", "a2", "B", "a1", "A"};
//    i =0;
//    for (auto it=o.begin_reverse_order(); it!=o.reverse_order(); ++it) {
//                CHECK_EQ((*it),result.at(i));
//        i++;
//    }
//    //placeholder for 18 tests can't be checked yet:
//    for (int i=0; i<18; i++){CHECK_EQ("placeholder for tests cant be checked yet","");}
//
//
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
