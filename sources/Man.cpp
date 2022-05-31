//
// Created by Aviva on 5/12/2022.
//
#include <stdexcept>
#include "Man.hpp"
using namespace std;

namespace ariel{
    Man::Man(const string &name){   //, Man *Pfather
        this->_name = name;
//        this->_Pfather = Pfather;
        this->_Pchildren = {};
    }
}

