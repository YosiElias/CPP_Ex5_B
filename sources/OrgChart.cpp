//
// Created by Yossi on 5/12/2022.
//


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
#include "OrgChart.hpp"
using namespace std;

namespace ariel{

    OrgChart& OrgChart::add_root(const string &name) {
        if (this->_root != nullptr){
            this->replace_root(name);
            return *this;
        }
        std::shared_ptr<Man> m  =  make_shared<Man>(name);//, nullptr
        this->_root = m;
        return *this;
    }

    OrgChart& OrgChart::add_sub(const string &name, const string &name1) {
        std::shared_ptr<Man> man = this->find_man(name);
        if (man == nullptr){
            throw std::logic_error("Man not in org");
        }
        std::shared_ptr<Man> man1  =  make_shared<Man>(name1);
        man->add_child(man1);
        man1->set_father(man);
        return *this;
    }

    std::ostream &operator<<(ostream &output, OrgChart &c) {
        c._root->print(output, 1);
        return output;
    }

    std::shared_ptr<Man> OrgChart::find_man(const string &name) {
        for (auto it = this->begin_level_order(); it != this->end_level_order(); ++it)
        {
            if (name == *it) {
                return it.pointer_to_current_man;
            }
        }
        return nullptr;
    }

    void OrgChart::replace_root(const string &name) {
        this->_root->_name = name;
    }

    OrgChart::iterator_level OrgChart::begin_level_order() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_level{this->_root};}

    OrgChart::iterator_level OrgChart::end_level_order() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_level{nullptr};
    }

    OrgChart::iterator_reverse_order OrgChart::begin_reverse_order() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_reverse_order{this->_root};
    }

    OrgChart::iterator_reverse_order OrgChart::reverse_order() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_reverse_order{nullptr};
    }

    OrgChart::iterator_preorder OrgChart::begin_preorder() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_preorder{this->_root};
    }

    OrgChart::iterator_preorder OrgChart::end_preorder() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_preorder{nullptr};
    }

    OrgChart::iterator_level OrgChart::begin() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_level{this->_root};
    }

    OrgChart::iterator_level OrgChart::end() {
        if (this->_root == nullptr) { throw std::logic_error("org is empty"); }
        return iterator_level{nullptr};
    }


    OrgChart::iterator_reverse_order::iterator_reverse_order(const shared_ptr<Man> &ptr) {
        if (ptr == nullptr){
            pointer_to_current_man = nullptr;
            return;
        }
        this->queue_man.push(ptr);
        while (!this->queue_man.empty()){
            std::shared_ptr<Man> tmp = this->queue_man.front();
            this->stack_man.push(tmp);
            this->queue_man.pop();
            for(int i = int(tmp->get_Pchildren().size() - 1); i >= 0; i--){
                this->queue_man.push(tmp->get_Pchildren().at(size_t(i)));
            }
        }
        pointer_to_current_man = this->stack_man.top();
        this->stack_man.pop();
    }

    OrgChart::iterator_reverse_order &OrgChart::iterator_reverse_order::operator++() {
        if (this->stack_man.empty()){
            this->pointer_to_current_man = nullptr;
            return *this;
        }
        this->pointer_to_current_man = this->stack_man.top();
        this->stack_man.pop();
        return *this;
    }

    OrgChart::iterator_reverse_order OrgChart::iterator_reverse_order::operator++(int) {
        iterator_reverse_order tmp = *this;
        if (this->stack_man.empty()){
            this->pointer_to_current_man = nullptr;
            return tmp;
        }
        this->pointer_to_current_man = this->stack_man.top();
        this->stack_man.pop();
        return tmp;
    }

    OrgChart::iterator_preorder::iterator_preorder(const shared_ptr<Man> &ptr) {
        pointer_to_current_man = ptr;
        this->stack_man.push(ptr);
        first = true;
    }

    OrgChart::iterator_preorder &OrgChart::iterator_preorder::operator++() {
        if (this->stack_man.empty()){
            this->pointer_to_current_man = nullptr;
            return *this;
        }
        this->pointer_to_current_man = this->stack_man.top();
        this->stack_man.pop();
        for(int i = int(pointer_to_current_man->get_Pchildren().size() - 1); i >= 0; i--){
            this->stack_man.push(pointer_to_current_man->get_Pchildren().at(size_t(i)));
        }
        if (first){ // one recursive in case of first time
            first = false;
            ++(*this);
        }
        return *this;
    }

    OrgChart::iterator_preorder OrgChart::iterator_preorder::operator++(int) {
        iterator_preorder tmp = *this;
        if (this->stack_man.empty()){
            this->pointer_to_current_man = nullptr;
            return tmp;
        }
        this->pointer_to_current_man = this->stack_man.top();
        this->stack_man.pop();
        for(int i = int(pointer_to_current_man->get_Pchildren().size() - 1); i >= 0; i--){
            this->stack_man.push(pointer_to_current_man->get_Pchildren().at(size_t(i)));
        }
        if (first){ // one recursive in case of first time
            first = false;
            (*this)++;
        }
        return tmp;
    }


    OrgChart::iterator_level::iterator_level(const shared_ptr<Man> &ptr)
            : pointer_to_current_man(ptr) {
        this->queue_man.push(ptr);
        this->first = true;
    }

    OrgChart::iterator_level &OrgChart::iterator_level::operator++() {
        if (this->queue_man.empty()){
            this->pointer_to_current_man = nullptr;
        }
        else {
            this->pointer_to_current_man = this->queue_man.front();
            this->queue_man.pop();
            for (size_t i = 0; i < this->pointer_to_current_man->get_Pchildren().size(); ++i) {
                this->queue_man.push(this->pointer_to_current_man->get_Pchildren().at(i));
            }
            if (first){ // one recursive in case of first time
                first = false;
                ++(*this);
            }
        }
        return *this;
    }

    OrgChart::iterator_level OrgChart::iterator_level::operator++(int) {
        iterator_level tmp = *this;
        if (this->queue_man.empty()){
            this->pointer_to_current_man = nullptr;
        }
        else {
            pointer_to_current_man = this->queue_man.front();
            this->queue_man.pop();
            for (size_t i = 0; i < this->pointer_to_current_man->get_Pchildren().size(); ++i) {
                this->queue_man.push(this->pointer_to_current_man->get_Pchildren().at(i));
            }
            if (first){ // one recursive in case of first time
                first = false;
                (*this)++;
            }
        }
        return tmp;
    }
}