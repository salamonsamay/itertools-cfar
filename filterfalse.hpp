
#pragma once
#include <iostream>
#include <vector>

namespace itertools{

    template<typename sign, typename container>

    class filterfalse {

        sign _s;
        container _container;
        typedef typename container::value_type value_;// typedef typename container::value_type value_

    public:
        filterfalse(sign s, container cont): _s(s), _container(cont){}

        class iterator{
            typename container::iterator _start;
            typename container::iterator _end;
            sign _s;

        public:
            iterator(typename container::iterator start, typename container::iterator end, sign s)
                 : _start(start), _end(end), _s(s){

                while (_start != _end && _s(*_start))
                    ++_start;
            }

            iterator& operator=(const iterator& it){
                if(this != &it) {
                    this->_start = it._start;
                    this->_end = it._end;
                    this->_s = it._s;
                }
                return *this;
            }


            bool operator==(const iterator& it) {
                return _start == it._start;
            }

            bool operator!=(const iterator& it) {
                return _start != it._start;
            }

            iterator& operator++(){
                do{
                    ++_start;
                } while (_start != _end && _s(*_start));
                return *this;
            }

            iterator operator++(int){
                iterator iter = *this;
                ++(*this);
                return iter;
            }

            value_ operator*(){
                return *_start;
            }
        };

        iterator begin(){ return iterator(_container.begin(), _container.end(), _s); }
        iterator end(){ return iterator(_container.end(), _container.end(), _s); }
    };
}

