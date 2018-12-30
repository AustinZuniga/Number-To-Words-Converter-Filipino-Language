#include <vector>
#include <iostream>


std::string pang_saling( const unsigned int numero){

    const std::vector<std::string> isa_sampu = {"sero", "isa", "dalawa", "tatlo", "apat", "lima", "anim", "pito", "walo", "siyam", "sampo"};
    const std::vector<std::string> pang_dugtong = {"dalawang", "tatlong", "apatna", "limang", "animna", "pitong", "walong", "siyamna"};

    if( numero <= 10 )
        return isa_sampu.at(numero);
    if( numero < 20 )
        return "labing " + isa_sampu.at(numero-10);
    if( numero < 100 ) {
        unsigned int remainder = numero - (static_cast<int>(numero/10)*10);
        return pang_dugtong.at(numero/10-2) + (0 != remainder ? "pu't-" + pang_saling(remainder) : "pu't-");
    }
    if( numero < 1000 ) {
        unsigned int remainder = numero - (static_cast<int>(numero/100)*100);
        return isa_sampu.at(numero/100) + (0 != remainder ? "ng daan " + pang_saling(remainder) : "ng daan");
    }
    if( numero < 1000000 ) {
        unsigned int thousands = static_cast<int>(numero/1000);
        unsigned int remainder = numero - (thousands*1000);
        return pang_saling(thousands) + (0 != remainder ? "ng libo't " + pang_saling(remainder) : "ng libo");
    }
    if( numero < 1000000000 ) {
        unsigned int millions = static_cast<int>(numero/1000000);
        unsigned int remainder = numero - (millions*1000000);
        return pang_saling(millions) + (0 != remainder ? "ng milyon " + pang_saling(remainder) : "ng milyon");
    }
    throw std::out_of_range("Imposible na yan!");
}
bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int main(){
        std::string numero;
        std::string test;
        std::cout << "Magbigay ng numero:";
        std::cin >>numero;
        std::string::size_type sz; 
        if (is_number(numero)){
            int i = std::stoi (numero,&sz);
            std::cout << i << " = " << pang_saling(i) << std::endl;
        }
}