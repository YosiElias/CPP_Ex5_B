#pragma once

//
// Created by Yossi on 5/12/2022.
//

//#ifndef PART_A_ORGCHART_HPP
//#define PART_A_ORGCHART_HPP

#include <iostream>
#include <stdexcept>
#include "Man.hpp"
#include <queue>
#include <stack>
#include <memory>
using namespace std;

namespace ariel {
    class OrgChart{
    private:
        // fields
        std::shared_ptr<Man> _root;

    public:
        OrgChart():_root(nullptr){};

        OrgChart& add_root(const std::string &name);

        OrgChart& add_sub(const std::string &name, const std::string &name1);

        friend std::ostream& operator<< (std::ostream& output, OrgChart& c);

/*-----------------------------------------------------------------------------------------------------
                                        Class of Iterator
-----------------------------------------------------------------------------------------------------*/

        class iterator_level {

        public:
            std::shared_ptr<Man> pointer_to_current_man;
            queue<std::shared_ptr<Man>> queue_man;
            bool first;

            iterator_level(const std::shared_ptr<Man> &ptr = nullptr);

            std::string & operator*() const {
                //return *pointer_to_current_man;
                return pointer_to_current_man->_name;
            }

            std::string* operator->() const {
                return &(pointer_to_current_man->_name);
            }

            // ++i;
            iterator_level& operator++();

            // i++;
            iterator_level operator++(int);

            bool operator==(const iterator_level& rhs) const {
                return pointer_to_current_man == rhs.pointer_to_current_man;
            }

            bool operator!=(const iterator_level& rhs) const {
                return pointer_to_current_man != rhs.pointer_to_current_man;
            }
        };  // END OF CLASS iterator_level

        class iterator_reverse_order {

        public:
            std::shared_ptr<Man> pointer_to_current_man;
            queue<std::shared_ptr<Man>> queue_man;
            stack<std::shared_ptr<Man>> stack_man;

            iterator_reverse_order(const shared_ptr<Man> &ptr);

            std::string & operator*() const {
                //return *pointer_to_current_man;
                return pointer_to_current_man->_name;
            }

            std::string* operator->() const {
                return &(pointer_to_current_man->_name);
            }

            // ++i;
            iterator_reverse_order& operator++();

            // i++;
            iterator_reverse_order operator++(int);

            bool operator==(const iterator_reverse_order& rhs) const {
                return pointer_to_current_man == rhs.pointer_to_current_man;
            }

            bool operator!=(const iterator_reverse_order& rhs) const {
                return pointer_to_current_man != rhs.pointer_to_current_man;
            }
        };  // END OF CLASS iterator_reverse_order


        class iterator_preorder {

        public:
            std::shared_ptr<Man> pointer_to_current_man;
            stack<std::shared_ptr<Man>> stack_man;
            bool first;

            iterator_preorder(const shared_ptr<Man> &ptr);

            std::string & operator*() const {
                return pointer_to_current_man->_name;
            }

            std::string* operator->() const {
                return &(pointer_to_current_man->_name);
            }

            // ++i;
            iterator_preorder& operator++();

            // i++;
            iterator_preorder operator++(int);

            bool operator==(const iterator_preorder& rhs) const {
                return pointer_to_current_man == rhs.pointer_to_current_man;
            }

            bool operator!=(const iterator_preorder& rhs) const {
                return pointer_to_current_man != rhs.pointer_to_current_man;
            }
        };  // END OF CLASS iterator_preorder



        iterator_level begin_level_order();
        iterator_level end_level_order();

        iterator_reverse_order begin_reverse_order();
        iterator_reverse_order reverse_order();

        iterator_preorder begin_preorder();
        iterator_preorder end_preorder();

        iterator_level begin();
        iterator_level end();

        void replace_root(const string &name);
        std::shared_ptr<Man> find_man(const string &name);
    };
};



//#endif //PART_A_ORGCHART_HPP
