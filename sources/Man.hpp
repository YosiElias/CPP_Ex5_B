#pragma once

//
// Created by Aviva on 5/12/2022.
//

//#ifndef PART_A_MEN_HPP
//#define PART_A_MEN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

namespace ariel {
    class Man{

    public:
        std::vector<std::shared_ptr<Man>> _Pchildren;   //use public for internal use of the class
        std::weak_ptr<Man> _Pfather;   //use public for internal use of the class
        std::string _name;   //use public for internal use of the class
        Man(const std::string &name);
        void add_child(const std::shared_ptr<Man>& Pchild) {
            this->_Pchildren.push_back(Pchild);
        }
        std::string get_name() const{return this->_name;};
        std::vector<std::shared_ptr<Man>> get_Pchildren() const{return this->_Pchildren;};
        void set_father(const std::shared_ptr<Man>& Pfather){ this->_Pfather = Pfather;};
        void print(std::ostream &output, int level) {
            for (int i = 1; i < level; i++) {
                output << "\t";
            }
            output <<"|------"<< _name <<"\n";
            for (const auto& child : this->_Pchildren) {
                child->print(output, level + 1);
            }
        }

    };
}


//#endif //PART_A_MEN_HPP
