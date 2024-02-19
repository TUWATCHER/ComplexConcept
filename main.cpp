#include <concepts>
#include <string>
#include <iostream>
#include <functional>

template<typename T>
concept ComplexConcept = requires (T obj)
{
    {std::hash<T>{} (obj)} -> std::convertible_to<long>;
    {std::to_string(obj)} -> std::same_as<std::string>;
    
}
&&!std::has_virtual_destructor<T>();

template<ComplexConcept T>
void ComplexFunc (T& obj)
{
    std::hash<T> obj_hash;
    std::cout << obj_hash(obj) << " " << std::to_string(obj) << std::endl;
}

struct meow
{
    ~meow();
};

int main()
{
    long a = 192;
    ComplexFunc(a);  
 
    return 0;
}