#include <iostream>
#include<map>
#include<unordered_map>

std::unordered_multimap<std::string, char> Morse;

//char translate(const std::string &morse);

char translate(const std::string &morse) {
    auto iterator = Morse.find(morse);
    if (iterator == Morse.end()) {
        return ' ';
    }

    printf("Your morse is: %c", iterator->second);
    return iterator->second;

}


int main() {

    Morse.insert(std::make_pair(".-",'A'));
    Morse.insert(std::make_pair("-...",'B'));
    Morse.insert(std::make_pair("-.-.",'C'));
    Morse.insert(std::make_pair("-..",'D'));
    Morse.insert(std::make_pair(".",'E'));
    Morse.insert(std::make_pair("..-.",'F'));
    Morse.insert(std::make_pair("--.",'G'));
    Morse.insert(std::make_pair("....",'H'));
    Morse.insert(std::make_pair("..",'I'));
    Morse.insert(std::make_pair(".---",'J'));
    Morse.insert(std::make_pair("-.-",'K'));
    Morse.insert(std::make_pair(".-..",'L'));
    Morse.insert(std::make_pair("--",'M'));
    Morse.insert(std::make_pair("-.",'N'));
    Morse.insert(std::make_pair("---",'O'));
    Morse.insert(std::make_pair(".--.",'P'));
    Morse.insert(std::make_pair("--.",'Q'));
    Morse.insert(std::make_pair(".-.",'R'));
    Morse.insert(std::make_pair("...",'S'));
    Morse.insert(std::make_pair("-",'T'));
    Morse.insert(std::make_pair("..-",'U'));
    Morse.insert(std::make_pair("...-",'V'));
    Morse.insert(std::make_pair(".--",'W'));
    Morse.insert(std::make_pair("-..-",'X'));
    Morse.insert(std::make_pair("-.--",'Y'));
    Morse.insert(std::make_pair("--..",'Z'));
    Morse.insert(std::make_pair(".----",'1'));
    Morse.insert(std::make_pair("..---",'2'));
    Morse.insert(std::make_pair("...--",'3'));
    Morse.insert(std::make_pair("....-",'4'));
    Morse.insert(std::make_pair(".....",'5'));
    Morse.insert(std::make_pair("-....",'6'));
    Morse.insert(std::make_pair("--...",'7'));
    Morse.insert(std::make_pair("---..",'8'));
    Morse.insert(std::make_pair("----.",'9'));
    Morse.insert(std::make_pair("-----",'0'));

//    for(it = Morse.begin(); it != Morse.end(); it++)
//        std::cout << it->second << std::endl;

    translate(".-");


//

//
//    tempMap.insert(std::make_pair("Peter", 4));
//    tempMap.insert(std::make_pair("Chris", 10));
//    tempMap.insert(std::make_pair("Charlie", 1));
//    tempMap.insert(std::make_pair("George", 2));
//

//    system("pause");
    return 0;
}