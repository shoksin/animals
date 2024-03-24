#include"reading.cpp"

int main(){
    Cat cat1("Gosha",15,"eng");
    //std::cout<<cat1;
    Cat cat2("Murzik",22,"brit");
    Cat cat3;
    std::cout<<cat3;
    //std::cout<<cat2;
    cat2 = std::move(cat1);
    std::cout<<cat1;
    std::cout<<cat2;

}