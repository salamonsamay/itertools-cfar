

#pragma once

namespace itertools{
    typedef struct{
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } oper_plus;

    template <typename container, typename sign = oper_plus>

    class accumulate{
        container _container;
        sign _sign;
         typename container::value_type value_;// typedef typename container::value_type value_;

    public:
        explicit accumulate(container cont, sign s = oper_plus()) : _container(cont), _sign(s){}

        class iterator{
            typename container::value_type _data;
            typename container::iterator _start;
            typename container::iterator _end;
            sign _sign;

        public:
            explicit iterator(typename container::iterator iter, typename container::iterator end, sign s) : _start(iter), _end(end), _sign(s){
                if(_start != _end) _data = *iter;//if the size is bigger than 0
            };
    // rang(4,8)  accumulate(4,9,15,22)
    //
            iterator& operator=(const iterator& it){
                if(this != &it) {
                    this->_data = it._data;
                    this->_start = it._start;
                    this->_end = it._end;
                    this->_sign = it._sign;
                }
                return *this;
            };

            iterator& operator ++(){//++i
                ++_start;
                if(_start != _end) _data = _sign(_data, *_start);//
                return *this;
            }

            iterator operator ++(int){//i++
                iterator temp = *this;
                ++(*this);
                return temp;
            }

            bool operator !=(const iterator& it) {
                return (_start != it._start);
            }

            bool operator ==(const iterator& it) {
                return (_start == it._start);
            }

            auto operator *(){
                return _data;
            }
        };


        iterator begin(){ return iterator(_container.begin(), _container.end(), _sign); }
        iterator end(){ return iterator(_container.end(), _container.end(), _sign); }
    };
 
}
