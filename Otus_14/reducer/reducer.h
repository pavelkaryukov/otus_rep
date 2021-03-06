﻿#pragma once      
#include <boost/format.hpp>
#include <fstream>
#include <functional>
#include <iostream>     
#include <map>          
#include <vector>

template<class THash>
void ReduceFunc( std::vector<THash>&& aHashs,  const std::size_t aNumberOfData, std::reference_wrapper<std::map<THash, std::size_t>> aMap) {
    for (const auto& hash : aHashs) {
        aMap.get()[hash]++;
    }
    
    std::ofstream file(boost::str(boost::format("reduced_part[%1%]") % aNumberOfData));
    if (!file || !file.is_open()) {
        std::cout << "Cant open file" << std::endl;
        return;
    }

    for (const auto&[hash, counter] : aMap.get()) {
        file << boost::format("HASH[%1%]; NUMBER[%2%]") % hash % counter << std::endl;
    }
}
