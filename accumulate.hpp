#include <iostream>
#include <vector>


namespace itertools{
    template<class T>
    struct accumulate{
        T* con;
        void* f=NULL;
        accumulate(T con){
            std::cout<<"constructorA\n"<<std::endl;
            this->con=&con;
            std::cout<<"constructorB\n"<<std::endl;
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
        template<typename FUNCTION>
        accumulate(T con, FUNCTION f){
         this->con= &con; 
         this->f=&f; 
       }
    

       struct iterator{
            //auto index=i.begin();
            T* conI;
            // void* f=NULL; 
            int countS, countF;
            iterator(T& con){
                countS=0;
                countF=0;
                conI=&con;
                for(auto i: con){
                    // std::cout<<i<<"\n"<<std::endl;
                    countF++;
                }
                std::cout<<"countf "<<countF<< "\n"<<std::endl;
                std::cout<<"conI "<<*(conI->begin())<< "\n"<<std::endl;

                // countF=con.size;
                  
            }

            // template<typename FUNCTION>
            // iterator(T& con, FUNCTION& f){
            //     countS=0;
            //     countF=0;
            //     conI=&con;
            //     for(auto i: con){
            //         // std::cout<<i<<"\n"<<std::endl;
            //         countF++;
            //     }
            //     std::cout<<"f: "<<f<<"\n"<<std::endl;
            //     this->f=&f;
            // }
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
                std::cout<<"conI2 "<<*(conI->begin())<< "\n"<<std::endl;
                decltype(*(conI->begin())) returnType= *(conI->begin());
                // decltype(*(conI->begin())) returnType;
                T tempCon= *conI;
                int tempCount=0;
                std::cout<<"returnType "<<returnType<< "\n"<<std::endl;
                std::cout<<"countS "<<countS<< "\n"<<std::endl;
                for(auto temp: tempCon){
                    //std::cout<<tempCount<<std::endl;
                    if(tempCount==0){
                        tempCount++;
                        if(countS==0)
                            break;
                        continue;
                    }
                    // if(f==NULL)   
                        returnType+=temp;
                    // else    
                    //     // returnType=*(FUNCTION*)f(returnType,temp);
                    //     returnType=toFunction(returnType,temp,f);
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
            // auto toFunction(decltype(*(conI->begin())) x, decltype(*(conI->begin())) y, FUNCTION f){
            //     return *((FUNCTION*)f)(x,y);
            // }

        };

        iterator begin(){
            std::cout<<"begin"<<std::endl;
            // if(f==NULL){
                iterator i (*con);
                return i;
            // }
            // else
            // {
            //     iterator i (*con, f);
            //     return i;  
            // }  
            
        }

        auto end(){
            iterator i (*con);
            i.countS=i.countF;
            return i;
        }
    };
    



    // template<typename FUNCTION>
    // struct accumulate{
    //     T* con;
    //     FUNCTION* f=NULL;
    // //     accumulate(T con){
    // //         std::cout<<"constructorA\n"<<std::endl;
    // //         this->con=&con;
    // //         std::cout<<"constructorB\n"<<std::endl;
    // //         // for(auto i=con.begin(); i!=con.end(); i++){
    // //         //     accVec.emplace_back(*i);
    // //         //     }
    // //         // for(int j=0; j<accVec.size(); j++){
    // //         //     int count=0;
    // //         //     for(auto i=con.begin(); i!=con.end(); i++){
    // //         //         accVec[j]=accVec[j]+*i;
    // //         //         if(count==j){
    // //         //             break;
    // //         //         }
    // //         //         count++;
    // //         //     }
    // //         // }
    // //    }
    //     // template<typename FUNCTION>
    //     accumulate(T con, FUNCTION f){
    //      this->con= &con; 
    //      this->f=&f; 
    //    }
    

    //    struct iterator{
    //         //auto index=i.begin();
    //         T* conI;
    //         FUNCTION* f=NULL; 
    //         int countS, countF;
    //         // iterator(T& con){
    //         //     countS=0;
    //         //     countF=0;
    //         //     conI=&con;
    //         //     for(auto i: con){
    //         //         // std::cout<<i<<"\n"<<std::endl;
    //         //         countF++;
    //         //     }
    //         //     std::cout<<"countf "<<countF<< "\n"<<std::endl;
    //         //     std::cout<<"conI "<<*(conI->begin())<< "\n"<<std::endl;

    //         //     // countF=con.size;
                  
    //         // }

    //         // template<typename FUNCTION>
    //         iterator(T& con, FUNCTION& f){
    //             countS=0;
    //             countF=0;
    //             conI=&con;
    //             for(auto i: con){
    //                 // std::cout<<i<<"\n"<<std::endl;
    //                 countF++;
    //             }
    //             std::cout<<"f: "<<f<<"\n"<<std::endl;
    //             this->f=&f;
    //         }
    //         void operator +(int b ){
    //             countS+=b;
    //         }

    //         void operator ++(){
    //             countS++;
    //         }
    //         bool operator !=(struct iterator b ){
    //             return countS!=b.countS;
    //         }
    //         auto operator *(){
    //             //auto iter= con.begin();
    //             std::cout<<"conI2 "<<*(conI->begin())<< "\n"<<std::endl;
    //             decltype(*(conI->begin())) returnType= *(conI->begin());
    //             // decltype(*(conI->begin())) returnType;
    //             T tempCon= *conI;
    //             int tempCount=0;
    //             std::cout<<"returnType "<<returnType<< "\n"<<std::endl;
    //             std::cout<<"countS "<<countS<< "\n"<<std::endl;
    //             for(auto temp: tempCon){
    //                 //std::cout<<tempCount<<std::endl;
    //                 if(tempCount==0){
    //                     tempCount++;
    //                     if(countS==0)
    //                         break;
    //                     continue;
    //                 }
    //                 // if(f==NULL)   
    //                 //     returnType+=temp;
    //                 // else    
    //                     // returnType=*(FUNCTION*)f(returnType,temp);
    //                 returnType=*f(returnType,temp);
    //                 if(countS<=tempCount)
    //                     break;
    //                 tempCount++;
    //             }
    //             // decltype(*(conI->begin())) typeF= *(conI->begin());
    //             // decltype(*(conI->begin())) typeP= *(conI->begin());
    //             // for(auto temp: tempCon){
    //             //     //std::cout<<tempCount<<std::endl;
    //             //     if(tempCount==0){
    //             //         tempCount++;
    //             //         if(countS==0)
    //             //             break;
    //             //         continue;
    //             //     }
    //             //     returnType=*f(returnType,typeF);
    //             //     //typeP=typeF;

    //             //  }
    //             return returnType;
    //         //   return 3;  
    //         }
            
    //         // template<typename FUNCTION>
    //         // auto toFunction(decltype(*(conI->begin())) x, decltype(*(conI->begin())) y, FUNCTION f){
    //         //     return *((FUNCTION*)f)(x,y);
    //         // }

    //     };

    //     iterator begin(){
    //         std::cout<<"begin"<<std::endl;
    //         // if(f==NULL){
    //         //     iterator i (*con);
    //         //     return i;
    //         // }
    //         // else
    //         // {
    //         iterator i (*con, *f);
    //         return i;  
    //         // }  
            
    //     }

    //     auto end(){
    //         iterator i (*con,*f);
    //         i.countS=i.countF;
    //         return i;
    //     }
    // };
};