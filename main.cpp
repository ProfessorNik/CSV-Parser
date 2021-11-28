#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <ostream>
#include "CSVParser.h"
//💙💙💙💙💙💙💙
//template<class... Args>💙💙💙💙💙💙💙
//class A{💙💙💙💙💙💙💙
//private:💙💙💙💙💙💙💙
//    int a = 10;💙💙💙💙💙💙💙
//public:💙💙💙💙💙💙💙
//    friend auto& operator<< (std::basic_ostream<int>& os, const A& a);💙💙💙💙💙💙💙
//};💙💙💙💙💙💙💙
//💙💙💙💙💙💙💙
//template<class charT>💙💙💙💙💙💙💙
//auto operator<< (std::basic_ostream<charT>& os, std::vector<charT> a){💙💙💙💙💙💙💙
//💙💙💙💙💙💙💙
//    os << a[0];💙💙💙💙💙💙💙
//💙💙💙💙💙💙💙
//    return os;💙💙💙💙💙💙💙
//}💙💙💙💙💙💙💙
//💙💙💙💙💙💙💙
//is_same<t, int>::value💙💙💙💙💙💙💙
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

int main() {
    CSVParser<std::string, std::string> parser("in.txt");
    for(auto t : parser){
        std::cout << t << std::endl;
    }
    auto t = std::make_tuple(std::make_tuple(10, 111, std::string("goodbye")), std::string("hello world"), 35.10);
    std::cout << t << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}