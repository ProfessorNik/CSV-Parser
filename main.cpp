#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <ostream>
#include "tupleout.h"
#include "CSVParser.h"
#include "CSVParserParametrs/CSVCellMakerBuilderImpl.h"

int main() {
    try {
        std::shared_ptr<CSVCellMakerBuilder> builder(new CSVCellMakerBuilderImpl());
        builder->setColumnSeparator('|');
        CSVParser<std::string, int, double> parser("in.txt", builder->build());
        for (auto t : parser) {
            std::cout << t << std::endl;
        }
    } catch(const CSVParseException& ex){
        std::cout << "Parse error in " << ex.getRow() << " row " << ex.getColumn() << " column: " << ex.what() << std::endl;
    } catch(const CSVException& ex){
        std::cout << "unknown parse exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex){
        std::cout << "unknown exception: " << ex.what() << std::endl;
    } catch (...){
        std::cout << "unknown exception" << std::endl;
    }

    return 0;
}