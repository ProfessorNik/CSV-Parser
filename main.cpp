#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <ostream>
#include "tupleout.h"
#include "CSVParser.h"
#include "CSVLineParser.h"
#include "CSVParserParametrs/CSVCellMakerBuilderImpl.h"
#include "CSVParserParametrs/CSVCellMakerBuilder.h"
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


int main() {
    std::shared_ptr<CSVCellMakerBuilder> builder(new CSVCellMakerBuilderImpl());
    builder->setColumnSeparator('|');
    CSVParser<std::string, int, double> parser("in.txt", builder->build());
    for(auto t : parser){
        std::cout << t << std::endl;
    }
    auto t = std::make_tuple(std::make_tuple(10, 111, std::string("goodbye")), std::string("hello world"), 35.10);
    std::cout << t << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}