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
    //     template<typename T, typename FUNCTION=void >
    //     accumulate(const T& con, FUNCTION f):con(con), f(f){
    //         std::cout<<"constructorA\n"<<std::endl;
    //         // this->con=&con;
    //         std::cout<<"constructorB\n"<<std::endl;
            
    //    }
        //template<typename FUNCTION>
        accumulate(const T& con, const FUNCTION& f=add()):con(con), f(f){
        //  this->con= &con; 
        //  this->f=&f; 
       }
    

       struct iterator{
            //auto index=i.begin();
            T* conI;
            FUNCTION* f; 
            int countS, countF;
            iterator(T& con){
                countS=0;
                countF=0;
                conI=&con;
                for(auto i: con){
                    // std::cout<<i<<"\n"<<std::endl;
                    countF++;
                }
                // std::cout<<"countf "<<countF<< "\n"<<std::endl;
                // std::cout<<"conI "<<*(conI->begin())<< "\n"<<std::endl;

                // countF=con.size;
                  
            }

            
            iterator(T& con, FUNCTION& f){
                countS=0;
                countF=0;
                this->conI=&con;
                this->f=&f;
                for(auto i: con){
                    // std::cout<<i<<"\n"<<std::endl;
                    countF++;
                }
                //std::cout<<"f: "<<f<<"\n"<<std::endl;
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
                //auto iter= con.begin();
                // std::cout<<"conI2 "<<*(conI->begin())<< "\n"<<std::endl;
                // decltype(*(conI->begin())) returnType (*(conI->begin()));
                //  decltype(*(conI->begin()))* returnType=new decltype(*(conI->begin()))(*(conI->begin()));
                typename std::decay<decltype(*(conI->begin()))>::type returnType (*(conI->begin())) ;
                T tempCon= *conI;
                int tempCount=0;
                std::cout<<"returnType "<<returnType<< "\n"<<std::endl;
                // std::cout<<"countS "<<countS<< "\n"<<std::endl;
                for(auto temp: tempCon){
                    std::cout<<"count: "<<tempCount<<std::endl;
                    std::cout<<" temp: "<<temp<<"\n"<<std::endl;
                    if(tempCount==0){
                        tempCount++;
                        if(countS==0)
                            break;
                        continue;
                    }   
                    returnType=(*f)(returnType,temp);
                    // returnType=toFunction(returnType,temp,*f);
                    if(countS<=tempCount)
                        break;
                    tempCount++;
                }
                // decltype(*(conI->begin())) typeF= *(conI->begin());
                // decltype(*(conI->begin())) typeP= *(conI->begin());
                // for(auto temp: tempCon){
                //     //std::cout<<tempCount<<std::endl;
                //     if(tempCount==0){
                //         tempCount++;
                //         if(countS==0)
                //             break;
                //         continue;
                //     }
                //     returnType=*f(returnType,typeF);
                //     //typeP=typeF;

                //  }
                return returnType;
            //   return 3;  
            }
            
            // template<typename FUNCTION>
            auto toFunction(decltype(*(conI->begin())) x, decltype(*(conI->begin())) y, FUNCTION& f){
                return (f)(x,y);
            }

        };

        iterator begin(){
            // std::cout<<"begin"<<std::endl;
                if(typeid(FUNCTION)==typeid(void)){
                    iterator i ((T&)con);
                    return i;
                }
                else{
                    iterator i ((T&)con, (FUNCTION&) f);
                    return i;
                }
            // }
            // else
            // {
            //     iterator i (*con, f);
            //     return i;  
            // }  
            
        }

        auto end(){
            if(typeid(FUNCTION)==typeid(void)){
                    iterator i ((T&)con);
                    i.countS=i.countF;
                    return i;
                }
                else{
                    iterator i ((T&)con, (FUNCTION&) f);
                    i.countS=i.countF;
                    return i;
                }
        }
    };

    
};