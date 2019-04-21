#include"tiny.hpp"


int main()
{
    using types       =       tiny<int,long>;
    using x           =       push_front<types, char>;
    using y           =       tiny_at<x, 0>::type;
    using z           =       tiny_iterator<x,int_<0>>;
    BOOST_STATIC_ASSERT((is_same<y,char>::value));
}
