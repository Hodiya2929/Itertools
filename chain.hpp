
namespace itertools{

template <typename T, typename V>

struct ChainRanges{

    T t1;
    V v1;

ChainRanges (const T& first, const V& second): t1(first), v1(second) {
    using V1 = const decltype (*first.begin())&;
    using V2 = const decltype (*second.begin())&;
    static_assert(std::is_same_v<V1,V2>, "The two arguments of 'chain' must have the same value type!");

 }

struct iterator{

 

auto operator* (){
    return var;
}

iterator& operator++(){
    return *this;
}


bool operator== (const iterator& other){ return var==other.var; }
bool operator!= (const iterator& other){ return var!=other.var; }

}; // end Iterator


auto end() const{
   return iterator{*v1.end()};
}

auto begin() const{
return iterator(*(t1.begin()));
}
     


}; // end struct chain

template<typename T, typename V> ChainRanges<T,V > chain(T first, V second){

    return ChainRanges(first, second);
}
} //end namespace