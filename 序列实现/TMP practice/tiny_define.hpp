
struct none{};
struct tiny_tag{};
template<typename T0=none,typename T1=none,typename T2=none>
struct tiny
{
    using tag   =   tiny_tag;
    using type  =   tiny;
    using t0    =   T0;
    using t1    =   T1;
    using t2    =   T2;
};
template<typename T0,typename T1,typename T2>
struct tiny_size:int_<3>{};

template<typename T0,typename T1>
struct tiny_size<T0,T1,none>:int_<2>{};

template<typename T0>
struct tiny_size<T0,none,none>:int_<1>{};

template<>
struct tiny_size<none,none,none>:int_<0>{};

template<typename Tiny,typename T,int N>
struct tiny_push_back;

template<typename Tiny,typename T>
struct tiny_push_back<Tiny,T,0>:tiny<T,none,none>{};

template<typename Tiny,typename T>
struct tiny_push_back<Tiny,T,1>:tiny<typename Tiny::t0,T,none>{};

template<typename Tiny,typename T>
struct tiny_push_back<Tiny,T,2>:tiny<typename Tiny::t0,typename Tiny::t1,T>{};

namespace boost
{
    namespace mpl
    {
        template<>
        struct clear_impl<tiny_tag>
        {
            template<typename Tiny>
            struct apply:tiny<>{};
        };
        template<>
        struct push_front_impl<tiny_tag>
        {
            template<typename Tiny,typename T>
            struct apply:tiny<T,typename Tiny::t0,typename Tiny::t1>{};
        };
        
        /*template<>
        struct push_back_impl<tiny_tag>
        {
            template<typename Tiny,typename T>
            struct apply:tiny_push_back<Tiny, T,2>{};
        };*/
    }
}


