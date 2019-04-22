//
//  Dimension.hpp
//  practice
//
//  Created by 葛润泽 on 2019/4/14.
//  Copyright © 2019 葛润泽. All rights reserved.
//

#ifndef Dimension_hpp
#define Dimension_hpp
#include<boost/mpl/vector.hpp>
#include<boost/mpl/int.hpp>
#include<boost/mpl/vector_c.hpp>
#include<boost/mpl/transform.hpp>
#include<boost/mpl/equal.hpp>
#include<boost/mpl/plus.hpp>
#include<boost/mpl/minus.hpp>
#include<boost/static_assert.hpp>
#include<iostream>
using namespace std;
using mass                  =     boost::mpl::vector_c<int,1,0,0,0,0,0,0>;
using length                =     boost::mpl::vector_c<int,0,1,0,0,0,0,0>;
using times                 =     boost::mpl::vector_c<int,0,0,1,0,0,0,0>;
using charge                =     boost::mpl::vector_c<int,0,0,0,1,0,0,0>;
using temperature           =     boost::mpl::vector_c<int,0,0,0,0,1,0,0>;
using intensity             =     boost::mpl::vector_c<int,0,0,0,0,0,1,0>;
using amount_of_substance   =     boost::mpl::vector_c<int,0,0,0,0,0,0,1>;
using acceleration          =     boost::mpl::vector_c<int,0,1,-2,0,0,0,0>;
using force                 =     boost::mpl::vector_c<int,1,1,-2,0,0,0,0>;
struct plus_f
{
    template<typename T1,typename T2>
    struct apply
    {
        typedef typename boost::mpl::plus<T1,T2>::type type;
    };
};

struct minus_f
{
    template<typename T1,typename T2>
    struct apply
    {
        typedef typename boost::mpl::minus<T1,T2>::type type;
    };
};

template<typename T,typename Dimension>
struct quantity
{
    T m_Value;
    explicit quantity(T x):m_Value(x){}
    T Value() const {return m_Value;}
    template<typename otherDimension>
    quantity(const quantity<T,otherDimension>& rhs):m_Value(rhs.m_Value)
    {
        BOOST_STATIC_ASSERT(boost::mpl::equal<Dimension,otherDimension>::type::value);
    }
};

template<typename T,typename D>
quantity<T,D> operator+(quantity<T,D> x,quantity<T,D> y)
{
    return quantity<T,D>(x.Value()+y.Value());
}

template<typename T,typename D>
quantity<T,D> operator-(quantity<T,D> x,quantity<T,D> y)
{
    return quantity<T,D>(x.Value()-y.Value());
}

template<typename T,typename D1,typename D2>
quantity<T,typename boost::mpl::transform<D1,D2,plus_f>::type >
operator*(quantity<T,D1> x,quantity<T,D2> y)
{
    typedef typename boost::mpl::transform<D1,D2,boost::mpl::plus<boost::mpl::_1,boost::mpl::_2> >::type dim;
    return quantity<T,dim>(x.Value()*y.Value());
}

template<typename T,typename D1,typename D2>
quantity<T,typename boost::mpl::transform<D1,D2,minus_f>::type >
operator/(quantity<T,D1> x,quantity<T,D2> y)
{
    typedef typename boost::mpl::transform<D1,D2,boost::mpl::minus<boost::mpl::_1,boost::mpl::_2> >::type divide;
    return quantity<T,divide>(x.Value()/y.Value());
}
#endif /* Dimension_hpp */
