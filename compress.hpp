#include <iostream>
#include <vector>
namespace itertools{
template<class T, class U>
    struct compress{
        const T& con;
        const U& boolCon;
        compress(const T& con, const U& boolCon):
         con(con),boolCon(boolCon){
            // this->con= &con;
            // this->boolCon= &boolCon;
            // std::cout<<"booladdr: "<<this->boolCon << "\n"<<std::endl;
            // std::cout<<"first: "<<*boolCon.begin()<< std::endl;
            // for(auto temp: *this->boolCon){
            //         std::cout<<"temp: "<< temp<< "\n"<<std::endl;
                // }
        
        }
            

       struct iterator{
            T* con;
            U* boolCon;
            int countS, countF;
            iterator(T& con, U& boolCon){
                this->con= &con;
                this->boolCon= &boolCon;
                // std::cout<<"booladdr: "<<this->boolCon << "\n"<<std::endl;
                // std::cout<<"first: "<<*boolCon.begin()<< std::endl;
                countF=0;
                countS=0;
                for(auto temp: boolCon){
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
            auto operator *(){
                int count =0;
                decltype(*(con->begin())) type= *(con->begin());
                for(auto temp: *con){
                    if(count==countS){
                        return temp;
                    }
                    count++;
                }
                return type;
            }
            
            void indForCountS(){
                for(int i=countS;i<countF; i++){
                    if(isTrue(i)){
                        countS=i;
                        // std::cout<<"counts: "<< countS<<"\n"<<std::endl;
                        return;
                    }
                    // std::cout<<"i: "<< i<<std::endl;
                }
                countS=countF;
            }
            bool isTrue(int i){
                int count =0;
                //std::cout<<"*boolCon: "<< *boolCon<<"\n"<<std::endl;
                for(bool temp: *boolCon){
                    // std::cout<<"temp: "<< temp<< "\n"<<std::endl;
                    if(count==i){
                        if(temp)
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
            
            iterator i ((T&)con, (U&)boolCon);
            return i;
        }

        auto end(){
            iterator i ((T&)con, (U&)boolCon);
            i.countS=i.countF;
            return i;
        }
    };
}