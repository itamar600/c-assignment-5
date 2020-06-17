#include <iostream>
#include <vector>



namespace itertools{
template<typename FUNCTION, class T>
    struct filterfalse{
        const T& con;
        const FUNCTION& f;
        filterfalse(const FUNCTION& f, const T& con):
         con(con),f(f) {
            // this->con=&con;
            // this->f=&f;
       }

       struct iterator{
            T* con;
            FUNCTION* f;
            int countS, countF;
            iterator(FUNCTION& f, T& con){
                countS=0;
                countF=0;
                this->con=&con;
                this->f=&f;
                for(auto temp: con){
                    countF++;
                }
                // std::cout<<"countf: "<< countF<<"\n"<<std::endl;
                indForCountS();
            }
            // void operator +(int b ){
            //     countS+=b;
            // }

            void operator ++(){
                countS++;
                indForCountS();
            }
            bool operator !=(struct iterator b ){
                return countS!=b.countF;
            }
            int operator *(){
                int count =0;
                for(auto temp: *con){
                    if(count==countS)
                        return temp;
                    count++;
                }
                return 0;  
            }
            void indForCountS(){
                for(int i=countS;i<countF; i++){
                    if(isFalse(i)){
                        countS=i;
                        // std::cout<<"counts: "<< countS<<"\n"<<std::endl;
                        return;
                    }
                }
                countS=countF;
            }
            bool isFalse(int i){
                int count =0;
                for(auto temp: *con){
                    if(count==i){
                        if(!((*f)(temp)))
                            return true;
                        else
                            return false;
                    }
                    count++;
                }
                return false;
            }

        };

        iterator begin(){
            iterator i ((FUNCTION&)f, (T&)con);
            return i;
        }

        auto end(){
            iterator i ((FUNCTION&)f, (T&)con);
            i.countS=i.countF;
            return i;
        }
    };
}