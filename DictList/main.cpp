#include "dictList.hpp"
#include <string>

int main()
{
    // DictionaryList<int> dictList;
    // dictList.insert(10);
    // dictList.insert(3);
    // dictList.insert(4);
    
    // dictList.insert(7);

    // dictList.insert(6);
    // dictList.insert(90);
    // dictList.insert(15);
    // dictList.insert(-90);

    // DictionaryList<int> second;
    // second.insert(90);
    // second.insert(100);
    // second.insert(-10);
    // second.insert(6);
    // second.insert(5);
    // second.insert(7);
    // second.insert(10);

    // second = std::move(second);
    // //std::cout <<"SSS " << sss << '\n';
    // std::cout << "Before merging\n";
    // std::cout << "FIRST  " << dictList << '\n';
    // std::cout << "SECOND  " << second << '\n';

    // // DictionaryList<int> sss;
    // // sss.merge(second);
    // // std::cout << "SSS: " << sss << '\n';
    // //dictList.merge(second);

    // // std::cout << "After merging\n";
    // // std::cout << "FIRST: " << dictList << '\n';
    // // std::cout << "SECOND: " << second << '\n';
    // //dictList.clear();
    // DictionaryList<int> iii;
    // iii.deleteWords(second);
    // dictList.deleteWords(second);
    // std::cout << "AFTER CLEANING " << dictList << '\n';
    // // dictList.clear();
    // //std::cout << "Cleaned FIRST: " << dictList << '\n';
    // // DictionaryList<int> third = getIntersection(dictList, second);
    // // std::cout << third << '\n';
    DictionaryList<int> aaa, bbb;
    aaa.merge(bbb);
    std::cout << aaa <<'\n'; 
    DictionaryList<std::string> words;
    words.insert("AAA");
    words.insert("BBB");
    words.insert("HELLO");
    std::cout << words << '\n';
    words.remove("G");
    words.remove("AAA");
    DictionaryList<std::string> second;
    second.insert("HELLO");
    second.insert("G");
    second.insert("NNN");
    std::cout  << getIntersection(words, second) << '\n';
    words.merge(second);
    std::cout << words << '\n';
    std::cout << words.search("HELLO") << '\n';
    std::cout << words << '\n';

    return 0;
}