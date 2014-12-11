//
//  main.cpp
//  ImpossibleBet
//
//  Created by Tomas De Lucca on 11/12/14.
//  Copyright (c) 2014 Tomas De Lucca. All rights reserved.
//

#include <iostream>

#define PERSON_NUMBER   100
#define TRIES   50

int boxes[PERSON_NUMBER];
bool verbose = false;

void randomizeBoxes(){
    
    for(int i=0;i<PERSON_NUMBER;i++){
        int index = rand()%(PERSON_NUMBER-i);
        
        int billValue = boxes[index];
        boxes[index] = boxes[PERSON_NUMBER-i-1];
        boxes[PERSON_NUMBER-i-1] = billValue;
    }
    
}


bool runOnce(){
    
    bool found = false;
    
    for(int i=0;i<PERSON_NUMBER;i++){
        int next = i;
        found = false;
        
        for(int j=0;j<TRIES;j++){
            int bill = boxes[next];
            if(verbose) std::cout<<"Box: "<<i<<" - Bill:"<<bill<<std::endl;
            if(bill == i){
                found = true;
                break;
            }
            next = bill;
        }
        
        if(!found)
            break;
    }
    
    return found;
}

float runSimulation (long loops){
    
    float total = 0;
    
    for(long i=0;i<loops;i++){
        randomizeBoxes();
        total += runOnce();
    }
    
    
    return (total/(float)loops);
};

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    
    for(int i=0;i<PERSON_NUMBER;i++){
        boxes[i] = i;
    }
    
    std::cout<<runSimulation(1000000)<<std::endl;
    
    return 0;
}
