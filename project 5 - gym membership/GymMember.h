//
//  GymMember.h
//  project5
//
//  Created by Izma Zuberi on 2/22/22.
//

#ifndef GymMember_h
#define GymMember_h

#include <iostream>
#include <string>
using namespace std;
#include "Kind.h"

class GymMember
{
    
private:
    string mName;
    string mAccountNumber;
    Kind mKind;
    int mWorkoutCount;
    
public:
    GymMember(string name, string accountnumber, Kind kind);
    int workoutsThisMonth();
    void startNewMonth();
    void newWorkout();
    
    Kind getKind();
    string getKindAsString();
    string getName();
    string getAccountNumber();
    
};

#endif /* GymMember_h */
