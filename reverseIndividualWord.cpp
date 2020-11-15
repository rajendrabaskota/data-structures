#include <iostream>

std::string reverse_words(std::string str){
    static int ptr1;
    static int ptr2;
    static int ptr3;
    static int len = str.length();
    static std::string result;
    if(str[ptr3] != ' ' && ptr3 < len){
        ptr1++;
        ptr3++;
        reverse_words(str);
        result += str[ptr3];
    }
    if(ptr3 < len && ptr3 == ptr2){
        ptr1++;
        ptr2 = ptr1;
        ptr3 = ptr1;
        ptr1 < len -1 ? result += ' ' : result;
        reverse_words(str);
    }
    ptr3--;
    return result;
}

int main(){
    std::string sentence = "double  spaced  words";
    int len = sentence.length();
    std::cout << len << std::endl;
    std::string result = reverse_words(sentence);
    std::cout << result << " " << result.length();
    return 0;
}
