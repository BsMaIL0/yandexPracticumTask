// Разместите здесь определение функции FindString.

#include <vector>
#include <string>

std::vector<int> FindString(std::string text, std::string text_to_find){
    std::vector<int> result;
    size_t pos = 0;
    if(text_to_find == ""){
        return result;
    }
    while(true){
        pos = text.find(text_to_find,pos);
        if(pos == std::string::npos){
            return result;
        }
        else{
            result.push_back(pos);
        }
        pos++;
    }
}