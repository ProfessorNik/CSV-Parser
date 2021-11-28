//
// Created by nikol on 26.11.2021.
//

#ifndef LAB_4_CSVPARSER_H
#define LAB_4_CSVPARSER_H

#include <string>
#include <fstream>
#include <memory>
#include <vector>


template<class... Args>
class CSVParser {
public:
    explicit CSVParser(const std::string& fileName, int skipFirstLinesCount = 0);

    virtual ~CSVParser();

    struct InputIterator{
        typedef typename std::tuple<Args...> value_type;
        typedef value_type& reference;
        typedef value_type* pointer;
        typedef std::input_iterator_tag iterator_category;

        explicit InputIterator(typename std::vector<std::tuple<Args...> >::iterator it);
        InputIterator(const InputIterator& other);

        InputIterator& operator++();

        //InputIterator operator++(int) const;

        value_type operator*() const;

        bool operator==(const InputIterator&);
        bool operator!=(const InputIterator&);
    private:
        typename std::vector<std::tuple<Args...> >::iterator it;
    };

    InputIterator begin();
    InputIterator end();

private:

    std::vector<std::tuple<Args...>> table;
    std::ifstream file;
    int skipFirsLinesCount{};
    int lineNumber{};

    void customizeInputStream(const std::string& fileName);


    void goToBeginningFile();

    void parseFile();

    std::tuple<Args...> readNextLine();
};


#endif //LAB_4_CSVPARSER_H
