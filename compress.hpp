//Created by yarden && shani on 09/06/2020

#pragma once
#include <iostream>
#include <vector>

namespace itertools{

    template<typename container1, typename container2>

    class compress {

        container1 _container1;
        container2 _container2;
        typedef typename container1::value_type _value;

    public:
        compress(container1 cont1, container2 cont2): _container1(cont1), _container2(cont2){}

        class iterator{
            typename container1::iterator _begin;
            typename container1::iterator _end;
            typename container2::iterator _begin2;

        public:
            iterator(typename container1::iterator begin, typename container1::iterator end, typename container2::iterator begin2): _begin(begin), _end(end), _begin2(begin2){
                while (_begin != _end && !(*_begin2)){
                    ++_begin;
                    ++_begin2;
                }
            }

            iterator& operator=(const iterator& it){
                if(this != &it) this->_begin = it._begin;
                return *this;
            }

            bool operator==(const iterator& it) {
                return _begin == it._begin;
            }

            bool operator !=(const iterator& it) {
                return _begin != it._begin;
            }

            iterator& operator++(){
                do{
                    ++_begin;
                    ++_begin2;
                } while (_begin!=_end && !(*_begin2));
                return *this;
            }

            iterator operator++(int){
                iterator iter = *this;
                ++(*this);
                return iter;
            }

            _value operator*(){
                return *_begin;
            }
        };

        iterator begin(){return iterator(_container1.begin(), _container1.end(), _container2.begin()); }
        iterator end(){ return iterator(_container1.end(), _container1.end(), _container2.end()); }
    };
}


