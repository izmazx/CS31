//
//  GymMember.cpp
//  project5
//
//  Created by Izma Zuberi on 2/21/22.
//

#include <iostream>
#include <string>
using namespace std;

#include "Kind.h"
#include "GymMember.h"

GymMember::GymMember(string name, string accountnumber, Kind kind)
{
    mName = name;
    mAccountNumber = accountnumber;
    mKind = kind;
    mWorkoutCount = 0;
}

int GymMember::workoutsThisMonth()
{
    return (mWorkoutCount);
}


void GymMember::startNewMonth()
{
    mWorkoutCount = 0;
}


void GymMember::newWorkout()
{
    mWorkoutCount++;
}


Kind GymMember::getKind()
{
    return mKind;
}


string GymMember::getKindAsString()
{
    string kind;
    if (mKind == 0)
        kind = "OTHER";
    if (mKind == 1)
        kind = "REGULAR";
    if (mKind == 2)
        kind = "PREMIER";
    if (mKind == 3)
        kind = "EXECUTIVE";
        
    return kind;
}


string GymMember::getName()
{
    return mName;
}


string GymMember::getAccountNumber()
{
    return mAccountNumber;
}


