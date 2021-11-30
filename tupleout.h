//
// Created by nikol on 29.11.2021.
//

#ifndef LAB_4_TUPLEOUT_H
#define LAB_4_TUPLEOUT_H

template<class charT, class trT, class... Args>
auto& operator<< (std::basic_ostream<charT, trT>& os, const std::tuple<Args...>& t);

template<size_t n, class charT, class trT, class... Args>
typename std::enable_if<(n >= sizeof...(Args))>::type
printTuple(std::basic_ostream<charT, trT>& os, const std::tuple<Args...>& t){}

template<size_t n, class charT, class trT, class... Args>
typename std::enable_if<(n < sizeof...(Args))>::type
printTuple(std::basic_ostream<charT, trT>& os, const std::tuple<Args...>& t){
    if (n != 0)
        os << ", ";
    if(typeid(std::get<n>(t)) == typeid(std::string)){
        os << "\"";
    }
    os << std::get<n>(t);
    if(typeid(std::get<n>(t)) == typeid(std::string)){
        os << "\"";
    }
    printTuple<n+1>(os, t);
}

template<class charT, class trT, class... Args>
auto& operator<< (std::basic_ostream<charT, trT>& os, const std::tuple<Args...>& t){
    os << "[";
    printTuple<0>(os, t);
    os << "]";
    return os;
}

#endif //LAB_4_TUPLEOUT_H
