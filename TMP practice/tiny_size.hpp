//
//  tiny_size.hpp
//  TMP practice
//
//  Created by 葛润泽 on 2019/4/21.
//  Copyright © 2019 葛润泽. All rights reserved.
//

#ifndef tiny_size_h
#define tiny_size_h
template<typename T0,typename T1,typename T2>
struct tiny_size:int_<3>{};

template<typename T0,typename T1>
struct tiny_size<T0,T1,none>:int_<2>{};

template<typename T0>
struct tiny_size<T0,none,none>:int_<1>{};

template<>
struct tiny_size<none,none,none>:int_<0>{};

#endif /* tiny_size_h */
