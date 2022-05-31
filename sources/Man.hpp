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
//    private:



    public:
        std::vector<std::shared_ptr<Man>> _Pchildren;
        std::weak_ptr<Man> _Pfather;
        Man(const std::string &name); //, Man *Pfather
        std::string _name;
        void add_child(const std::shared_ptr<Man>& Pchild) {
            this->_Pchildren.push_back(Pchild);
//            (*Pchild)._Pfather = (*this); /Todo: need to add father !
        }
        std::string get_name() const{return this->_name;};
        const std::vector<std::shared_ptr<Man>> get_Pchildren() const{return this->_Pchildren;};
        void set_father(const std::shared_ptr<Man>& Pfather){ this->_Pfather = Pfather;};


//        void add_root(const std::string &str);

    };
}


//#endif //PART_A_MEN_HPP
