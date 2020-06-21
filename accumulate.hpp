#include <iostream>
#include <vector>


namespace itertools{
    
    typedef struct{
        template<typename U>
        U operator()(U x,U y){
        return x+y;
        }
    }add;
    template<typename T, typename FUNCTION=add>
    struct accumulate{
        const T& con;
        const FUNCTION& f;
        accumulate(const T& con, const FUNCTION& f=add()):con(con), f(f){
       }
    

       struct iterator{
            T* conI;
            FUNCTION* f; 
            int countS, countF;
            iterator(T& con){
                countS=0;
                countF=0;
                conI=&con;
                for(auto i: con){
                    countF++;
                }
            }

            
            iterator(T& con, FUNCTION& f){
                countS=0;
                countF=0;
                this->conI=&con;
                this->f=&f;
                for(auto i: con){
                    countF++;
                }
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
                typename std::decay<decltype(*(conI->begin()))>::type returnType (*(conI->begin()));
                int tempCount=0;
                // std::cout<<"begin "<<*(conI->begin())<< "\n"<<std::endl;
                // std::cout<<"returnType "<<returnType<< "\n"<<std::endl;
                for(auto temp: *conI){
                    // std::cout<<"count: "<<tempCount<<std::endl;
                    // std::cout<<" temp: "<<temp<<"\n"<<std::endl;
                    if(tempCount==0){
                        tempCount++;
                        if(countS==0)
                            break;
                        continue;
                    }   
                    returnType=(*f)(returnType,temp);
                    if(countS<=tempCount)
                        break;
                    tempCount++;
                }
                return returnType;  
            }
            
        };

        iterator begin(){
                    iterator i ((T&)con, (FUNCTION&) f);
                    return i;
            
        }

        iterator end(){
            
                    iterator i ((T&)con, (FUNCTION&) f);
                    i.countS=i.countF;
                    return i;
                
        }
    };

    
};