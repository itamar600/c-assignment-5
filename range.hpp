#include <iostream>
#include <vector>
namespace itertools{
    struct range{
        int x, y;
        range(int x, int y){
            this->x=x;
            this->y=y;
        }
        

        struct iterator{
            int index;
            iterator(){
                index=-1;
            }
            void operator +(int b ){
                index+=b;
            }

            void operator ++(){
                index++;
            }
            bool operator !=(struct iterator b ){
                return index!=b.index;
            }
            int operator *(){
                return index;
            }

        };
        range::iterator begin(){
            struct iterator i;
            i.index=x;
            return i;
            
        }

        range::iterator end(){
            iterator i;
            i.index=y;
            return i;
        }
        // int operator +(iterator a,int b ){
        //         return a.index+b;
        // }

        // bool iterator::operator !=(iterator a,iterator b ){
        //         return a.index!=b.index;
        // }

        // int operator ++(iterator a){
        //         return a.index+1;
        // }

        // int operator *(iterator a){
        //         return a.index;
        // }

        // std::vector<int> getContainer(){
        //     return rangeVec;
        // }

    };
};