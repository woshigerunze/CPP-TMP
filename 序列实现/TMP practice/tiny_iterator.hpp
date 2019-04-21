//
//  tiny_iterator.hpp
//  TMP practice
//
//  Created by 葛润泽 on 2019/4/19.
//  Copyright © 2019 葛润泽. All rights reserved.
//
#ifndef tiny_iterator_h
#define tiny_iterator_h
template<typename Tiny,typename pos>
struct tiny_iterator
{
    using category  =   boost::mpl::random_access_iterator_tag;
};


namespace boost
{
    namespace mpl
    {
        template<typename Tiny,typename pos>
        struct next<tiny_iterator<Tiny,pos>>
        {
            using type  =   tiny_iterator<Tiny,typename boost::mpl::next<pos>::type>;
        };
        
        template<typename Tiny,typename pos>
        struct prior<tiny_iterator<Tiny,pos>>
        {
            using type  =   tiny_iterator<Tiny,typename boost::mpl::prior<pos>::type>;
        };
        
        template<typename Tiny,typename pos>
        struct deref<tiny_iterator<Tiny,pos>>:at<Tiny,pos>{};
        
        template<typename Tiny,typename pos,typename N>
        struct advance<tiny_iterator<Tiny,pos>,N>
        {
            using type  =   tiny_iterator<Tiny, typename boost::mpl::plus<pos,N>::type>;
        };
        
        template<typename Tiny,typename pos,typename pos1>
        struct distance<tiny_iterator<Tiny, pos>,tiny_iterator<Tiny, pos1>>:minus<pos,pos1>{};
        
        template<>
        struct begin_impl<tiny_tag>
        {
            template<typename Tiny>
            struct apply
            {
                using type  =   tiny_iterator<Tiny,int_<0>>;
            };
        };
        
        template<>
        struct end_impl<tiny_tag>
        {
            template<typename Tiny>
            struct apply
            {
                using type  =   tiny_iterator<Tiny,typename tiny_size<typename Tiny::t0,typename Tiny::t1,typename Tiny::t2>::type>;
            };
        };
        /*template<>
        struct size_impl<tiny_tag>
        {
            template<typename Tiny>
            struct apply:tiny_size<typename Tiny::t0,typename Tiny::t1,typename Tiny::t2>{};
        };*/
    }
}


#endif /* tiny_iterator_h */
