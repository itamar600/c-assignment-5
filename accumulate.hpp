#include <iostream>
#include <vector>


namespace itertools{
    template<class T>
    struct accumulate{
        //T i;
        accumulate(T con){
            // i= con;
            // for(auto i=con.begin(); i!=con.end(); i++){
            //     accVec.emplace_back(*i);
            //     }
            // for(int j=0; j<accVec.size(); j++){
            //     int count=0;
            //     for(auto i=con.begin(); i!=con.end(); i++){
            //         accVec[j]=accVec[j]+*i;
            //         if(count==j){
            //             break;
            //         }
            //         count++;
            //     }
            // }
       }
       template<typename U>
       accumulate(T con, U f){

       }

       struct iterator{
            //auto index=i.begin();
            int countS, countF;
            iterator(){
                // for(auto temp:: i){
                //     countF++;
                // }
                countS=0;  
            }
            void operator +(int b ){
                countS+=b;
            }

            void operator ++(){
                countS++;
            }
            bool operator !=(struct iterator b ){
                return countS!=b.countS;
            }
            auto operator *(){
            //     auto retunType= *(i.begin());
            //     int tempCount=0;
            //     for(auto temp: i){
            //         if(tempCount==0)
            //             continue;
            //         retunType+=temp;
            //         if(countS==tempCount)
            //             break;
            //         tempCount++;
            //     }
            //     return returnType;
              return 3;  
            }

        };

        iterator begin(){
            iterator i;
            return i;
        }

        auto end(){
            iterator i;
            i.countS=i.countF;
            return i;
        }
    };
};