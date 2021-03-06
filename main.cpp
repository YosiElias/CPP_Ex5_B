/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/OrgChart.hpp"
using namespace ariel;

int main() {
    Man* m1;
    OrgChart organization;

    int stat=0;
    string root_name;
    string new_name;
    while (stat != -1) {
        cout << "To add root enter 1 to add sub enter 2 (-1 to exit):\n";
        cin >> stat;
        if (stat == 1) {
            cout << "Enter name for root:\n";
            cin >> root_name;
            organization.add_root(root_name);
        }
        if (stat == 2) {
            cout << "Enter father and then the new child:\n";
            cin >> root_name;
            cin >> new_name;
            organization.add_sub(root_name, new_name);
        }
        cout << organization << endl;
    }



//    organization.add_root("CEO")
//            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
//            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
//            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
//            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
//            .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

    cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */
//    cout << "--------  level_order  --------"<<endl;
//    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); it++)
//    {
//        cout << (*it) << " " ;
//    } // prints: CEO CTO CFO COO VP_SW VP_BI
//    cout << endl<< "--------  reverse_order --------"<<endl;
//    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//    {
//        cout << (*it) << " " ;
//    } // prints: VP_SW VP_BI CTO CFO COO CEO
//    cout << endl<< "--------  preorder --------"<<endl;
//    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); it++) {
//        cout << (*it) << " " ;
//    }  // prints: CEO CTO VP_SW CFO COO VP_BI
//    cout << endl << "--------  level_order  --------"<<endl;
//
//    for (auto element : organization)
//    { // this should work like level order
//        cout << element << " " ;
//    } // prints: CEO CTO CFO COO VP_SW VP_BI
//    cout << endl;
//
//    // demonstrate the arrow operator:
//    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//    {
//        cout << it->size() << " " ;
//    } // prints: 3 3 3 3 5 5
}