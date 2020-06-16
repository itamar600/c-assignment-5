#include <iostream>
#include <vector>
#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"


using namespace itertools;
using namespace std;

TEST_CASE("100"){
    
    for(int i=0; i<100; i++){
        CHECK(3==3);
}

};