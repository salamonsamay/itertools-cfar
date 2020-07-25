

#pragma once

namespace itertools{
    class range{
        int num1, num2;

    public:
        range(int n1, int n2): num1(n1), num2(n2){}

        class iterator{
            int value;
        public:
            iterator(int v): value(v) {};
            iterator(const iterator& it) = default;

            iterator& operator=(const iterator& it){
                if(this != &it) this->value = it.value;
                return *this;
            }

            bool operator==(const iterator& it) {
                return (value == it.value);
            }

            bool operator!=(const iterator& it) {
                return (value != it.value);
            }

            iterator& operator++(){
                ++value;
                return *this;
            }

            iterator operator++(int){
                iterator iter = *this;
                value++;
                return iter;
            }

            int operator*(){
                return value;
            }
        };

        iterator begin(){ return iterator(num1); }
        iterator end(){ return iterator(num2); }
        typedef int	value_type;
    };
}

