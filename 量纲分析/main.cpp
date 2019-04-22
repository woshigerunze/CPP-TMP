#include"Dimension.hpp"
int main()
{
    quantity<float,mass> m(5.0f);
    quantity<float,acceleration> a(9.8f);
    quantity<float,force> f=m*a;
    auto res=f/a;
}
