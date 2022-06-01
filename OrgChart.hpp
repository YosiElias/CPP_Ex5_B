#pragma once

//
// Created by Yossi on 5/12/2022.
//

//#ifndef PART_A_ORGCHART_HPP
//#define PART_A_ORGCHART_HPP

#include <iostream>
#include <stdexcept>
#include "sources/Man.hpp"
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

    // ------ Class Iterator --------
    class iterator_level {

        public:
            std::shared_ptr<Man> pointer_to_current_man;
            queue<std::shared_ptr<Man>> queue_man;
            bool first;

            iterator_level(std::shared_ptr<Man> ptr = nullptr)    //Todo: need to change to nullptr and not &
                    : pointer_to_current_man(ptr) {
                this->queue_man.push(ptr);
                this->first = true;
            }

//            ~iterator_level(){
//                cout<<"delete man: "<< pointer_to_current_man->_name <<endl;
//            };

            std::string & operator*() const {
                //return *pointer_to_current_man;
                return pointer_to_current_man->_name;
            }

            std::string* operator->() const {
                return &(pointer_to_current_man->_name);
            }

            // ++i;
            iterator_level& operator++() {
                if (this->queue_man.empty()){
                    this->pointer_to_current_man = nullptr;
                }
                else {
                    this->pointer_to_current_man = this->queue_man.front();
                    this->queue_man.pop();
                    for (int i = 0; i < this->pointer_to_current_man->get_Pchildren().size(); ++i) {
                        this->queue_man.push(this->pointer_to_current_man->get_Pchildren().at(i));
                    }
                    if (first){ // one recursive in case of first time
                        first = false;
                        ++(*this);
                    }
                }
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            iterator_level operator++(int) {
                iterator_level tmp = *this;
                if (this->queue_man.empty()){
                    this->pointer_to_current_man = nullptr;
                }
                else {
                    pointer_to_current_man = this->queue_man.front();
                    this->queue_man.pop();
                    for (int i = 0; i < this->pointer_to_current_man->get_Pchildren().size(); ++i) {
                        this->queue_man.push(this->pointer_to_current_man->get_Pchildren().at(i));
                    }
                    if (first){ // one recursive in case of first time
                        first = false;
                        (*this)++;
                    }
                }
                return tmp;
            }

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

            iterator_reverse_order(std::shared_ptr<Man> ptr);    //Todo: need to change to nullptr and not &

            std::string & operator*() const {
                //return *pointer_to_current_man;
                return pointer_to_current_man->_name;
            }

            std::string* operator->() const {
                return &(pointer_to_current_man->_name);
            }

            // ++i;
            iterator_reverse_order& operator++() {
                if (this->stack_man.empty()){
                    this->pointer_to_current_man = nullptr;
                    return *this;
                }
                this->pointer_to_current_man = this->stack_man.top();
                this->stack_man.pop();
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            iterator_reverse_order operator++(int) {
                iterator_reverse_order tmp = *this;
                if (this->stack_man.empty()){
                    this->pointer_to_current_man = nullptr;
                    return tmp;
                }
                this->pointer_to_current_man = this->stack_man.top();
                this->stack_man.pop();
                return tmp;
            }

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

            iterator_preorder(std::shared_ptr<Man> ptr);    //Todo: need to change to nullptr and not &

            std::string & operator*() const {
                return pointer_to_current_man->_name;
            }

            std::string* operator->() const {
                return &(pointer_to_current_man->_name);
            }

            // ++i;
            iterator_preorder& operator++();

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            iterator_preorder operator++(int);

            bool operator==(const iterator_preorder& rhs) const {
                return pointer_to_current_man == rhs.pointer_to_current_man;
            }

            bool operator!=(const iterator_preorder& rhs) const {
                return pointer_to_current_man != rhs.pointer_to_current_man;
            }
        };  // END OF CLASS iterator_preorder



        iterator_level begin_level_order(){return iterator_level{this->_root};};
        iterator_level end_level_order(){return iterator_level{nullptr};};

        iterator_reverse_order begin_reverse_order(){return iterator_reverse_order{this->_root};};
        iterator_reverse_order reverse_order(){return iterator_reverse_order{nullptr};};   //Todo: need to change name to end_reverse_order

        iterator_preorder begin_preorder(){return iterator_preorder{this->_root};};
        iterator_preorder end_preorder(){return iterator_preorder{nullptr};};

        iterator_level begin() {
            // return &(m_first->m_value);
            return iterator_level{this->_root};
        }

        iterator_level end() {
            // return nullptr;
            return iterator_level{nullptr};
        }

        void replace_root(const string &name);

        std::shared_ptr<Man> find_man(const string &name);
    };
};



//#endif //PART_A_ORGCHART_HPP
