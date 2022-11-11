//
//  Gym.cpp
//  project5
//
//  Created by Izma Zuberi on 2/21/22.
//

#include <iostream>
#include <string>
using namespace std;

#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

Gym::Gym(string name, string location, Kind kind)
{
    mName = name;
    mLocation = location;
    mKind = kind;
    
    hasCardio = false;
    hasWeights = false;
    hasPool = false;
    hasTrack = false;
}


void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track)
{
    hasCardio = cardio;
    hasWeights = weights;
    hasPool = pool;
    hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember m)
{
    if (m.getKind() >= mKind)
        return true;
    else
        return false;
}
bool Gym::checkin(GymMember &m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack)
{
    if (canWorkoutHere(m) == true)
    {
        if (wantsCardio == true && hasCardio == false)
            return false;
        if (wantsWeights == true && hasWeights == false)
            return false;
        if (wantsPool == true && hasPool == false)
            return false;
        if (wantsTrack == true && hasTrack == false)
            return false;
    
    m.newWorkout();
    return true;
        
    }
    else
        return false;
}

bool Gym::hasCardioFeatures()
{
    return hasCardio;
}
bool Gym::hasWeightsFeatures()
{
    return hasWeights;
}
bool Gym::hasPoolFeatures()
{
    return hasPool;
}
bool Gym::hasTrackFeatures()
{
    return hasTrack;
}

Kind Gym::getKind()
{
    return mKind;
}
string Gym::getKindAsString()
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
string Gym::getLocation()
{
    return mLocation;
}
string Gym::getName()
{
    return mName;
}
