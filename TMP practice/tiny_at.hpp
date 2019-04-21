//
//  tiny_at.hpp
//  TMP practice
//
//  Created by 葛润泽 on 2019/4/19.
//  Copyright © 2019 葛润泽. All rights reserved.
//
#ifndef tiny_at_h
#define tiny_at_h
template<typename Tiny,int N> struct tiny_at{};

template<typename Tiny>
struct tiny_at<Tiny,0>
{
    using type  =   typename Tiny::t0;
};

template<typename Tiny>
struct tiny_at<Tiny,1>
{
    using type  =   typename Tiny::t1;
};

template<typename Tiny>
struct tiny_at<Tiny,2>
{
    using type  =   typename Tiny::t2;
};

namespace boost
{
    namespace mpl
    {
        template<typename T0,typename T1,typename T2,typename pos>
        struct at<tiny<T0,T1,T2>,pos>
        {
            using type  =   typename tiny_at<tiny<T0,T1,T2>,pos::value>::type;
        };
    }
}



#endif /* tiny_at_h */
