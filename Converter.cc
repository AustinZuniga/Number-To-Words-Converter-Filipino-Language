#include <vector>
#include <iostream>

std::string number_to_words( const unsigned int numero){
    const std::vector<std::string> isa_sampu = {"sero", "isa", "dalawa", "tatlo", "apat", "lima", "anim", "pito", "walo", "siyam", "sampu"};
    const std::vector<std::string> pang_dugtong = {"dalawam", "tatlum", "apatna", "limam", "animna", "pitum", "walum", "siyamna"};
    std::string to_concat;
    if( numero <= 10 ) // 0-10
        return isa_sampu.at(numero);
    if( numero < 20 ){ // 11 - 19
        std::string at_less = isa_sampu.at(numero-10);
        if(at_less == "isa" || at_less == "apat" || at_less == "anim")
            to_concat = "labing-";
        else
            to_concat = "labing";
        return to_concat + isa_sampu.at(numero-10);
    }
    if( numero < 100 ) { // 20 - 99
        unsigned int remainder = numero - (static_cast<int>(numero/10)*10);
        return pang_dugtong.at(numero/10-2) + (0 != remainder ? "pu't " + number_to_words(remainder) : "pu");
    }
    if( numero < 1000 ) { // hundreds
        unsigned int remainder = numero - (static_cast<int>(numero/100)*100);
        std::string numm = isa_sampu.at(numero/100);
        if(numm == "apat" || numm == "anim" || numm == "siyam")
            to_concat = " na raa";
        else
            to_concat = "ng daa";
        return isa_sampu.at(numero/100) + (0 != remainder ? to_concat+"'t " + number_to_words(remainder) : to_concat+"n");
    }
    if( numero < 1000000 ) { // thousands
        unsigned int thousands = static_cast<int>(numero/1000);
        unsigned int remainder = numero - (thousands*1000);
    
        if(thousands == 4 || thousands == 6 || thousands == 9)
            to_concat = " na libo";
        else
            to_concat = "g libo";
        return number_to_words(thousands) + (0 != remainder ? to_concat+"'t " + number_to_words(remainder) : to_concat);
    }
    if( numero < 1000000000 ) { // millions
        unsigned int millions = static_cast<int>(numero/1000000);
        unsigned int remainder = numero - (millions*1000000);
        std::string numm = number_to_words(millions);
        
        if(numm == "apat" || numm == "anim" || numm == "siyam")
            to_concat = " na milyong ";
        else
            to_concat = "ng milyon ";
        return numm + (0 != remainder ? to_concat + number_to_words(remainder) : to_concat);
    }
    throw std::out_of_range("Imposible na yan!"); // show error if too large
}
bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int main(){
        while(1){
        std::string numero;
        std::string test;
        std::cout << "Magbigay ng numero:";
        std::cin >>numero;
        std::string::size_type sz; 
        if (is_number(numero)){
            int i = std::stoi (numero,&sz);
            std::cout << i << " = " << number_to_words(i) << std::endl;
        }
    }
}