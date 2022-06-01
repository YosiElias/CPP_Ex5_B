//
// Created by Yossi on 5/12/2022.
//


#include <iostream>
#include <stdexcept>
#include <utility>
#include <bits/stdc++.h>
#include "../OrgChart.hpp"
using namespace std;

namespace ariel{

    OrgChart& OrgChart::add_root(const string &name) {
        if (this->_root != nullptr){
            this->replace_root(name);   //Todo: implement!
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
        cout << (*man)._name << " is father of " << (*man1)._name <<endl ;  //Todo: only for debug
        man->add_child(man1);
        man1->set_father(man);  //Todo: verify really set father
        return *this;
    }

    std::ostream &operator<<(ostream &output, OrgChart &c) {
        for (auto it = c.begin_level_order(); it != c.end_level_order(); ++it){
            output << *it<< " - ";
        }
        output << endl;
        return output;
    }

//    OrgChart::iterator_level OrgChart::begin_level_order() {
//        return iterator_level{this->_root};
//    }
//    OrgChart::iterator_level OrgChart::end_level_order() {
//        return {this->_root};
//    }

//    OrgChart::iterator_reverse_order OrgChart::begin_reverse_order() {
//        return {this->_root};
//    }

//    OrgChart::iterator_reverse_order OrgChart::reverse_order() {
//        return {this->_root};
//    }

//    OrgChart::iterator_level OrgChart::begin_preorder() {
//        return {this->_root};
//    }
//
//    OrgChart::iterator_level OrgChart::end_preorder() {
//        return {this->_root};
//    }

    void OrgChart::replace_root(const string &name) {

    }

    std::shared_ptr<Man> OrgChart::find_man(const string &name) {
        for (auto it = this->begin_level_order(); it != this->end_level_order(); ++it)
        {
            if (name == *it) {    //Todo: need override * to return the name
                return it.pointer_to_current_man;
            }
        }
        return nullptr; //Todo: implement!
    }

//    OrgChart::OrgChart() {
//        this->_root = NULL;
//    }
    OrgChart::iterator_reverse_order::iterator_reverse_order(std::shared_ptr<Man> ptr) {
        if (ptr == nullptr){
            pointer_to_current_man = nullptr;
            return;
        }
        this->queue_man.push(ptr);
        while (!this->queue_man.empty()){
            std::shared_ptr<Man> tmp = this->queue_man.front();
            this->stack_man.push(tmp);
            this->queue_man.pop();
            for(int i = tmp->get_Pchildren().size() - 1; i >= 0; i--){
//            for (int i = 0; i < tmp->get_Pchildren().size(); ++i) {   //Todo: dbs: if need revers in this order
                this->queue_man.push(tmp->get_Pchildren().at(size_t(i)));
            }
        }
//        cout<<"-------- stack_man: ----------"<<endl;
//        while (!stack_man.empty()){ //Todo: only for debug
//            cout<<stack_man.top()->_name<<endl;
//            stack_man.pop();
//        }
        pointer_to_current_man = this->stack_man.top();
        this->stack_man.pop();
    }

    OrgChart::iterator_preorder::iterator_preorder(std::shared_ptr<Man> ptr) {
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
        for(int i = pointer_to_current_man->get_Pchildren().size() - 1; i >= 0; i--){
//            for (int i = 0; i < tmp->get_Pchildren().size(); ++i) {   //Todo: dbs: if need revers in this order
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
        for(int i = pointer_to_current_man->get_Pchildren().size() - 1; i >= 0; i--){
//            for (int i = 0; i < tmp->get_Pchildren().size(); ++i) {   //Todo: dbs: if need revers in this order
            this->stack_man.push(pointer_to_current_man->get_Pchildren().at(size_t(i)));
        }
        if (first){ // one recursive in case of first time
            first = false;
            (*this)++;
        }
        return tmp;
    }


}