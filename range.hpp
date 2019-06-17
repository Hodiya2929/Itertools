#pragma once

namespace itertools {

template<typename T> 

struct RangeClass{ //struct - default access = public, class default access = private

T start, last;

RangeClass(T first, T last): start(first), last(last) { };

struct iterator{

T it; 

T operator* (){
    return it;
}

iterator& operator++(){
    ++it;
    return *this;
}

bool operator== (const iterator& other){ return it==other.it; }
bool operator!= (const iterator& other){ return it!=other.it; }
}; // end Iterator

iterator end() const{
    return iterator{last}; // cant have a field called end, compiler cant distinguish between
}

iterator begin() const{

return iterator{start};
}

}; // end RangeClass

template<typename T> RangeClass<T> range(T first, T last){

return RangeClass(first, last);
}


}//end namespace
