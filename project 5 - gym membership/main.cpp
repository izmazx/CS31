//
//  main.cpp
//  project5
//
//  Created by Izma Zuberi on 2/21/22.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Kind.h"
#include "Gym.h"
#include "GymMember.h"

using namespace std;

int main()
{
    Gym G("Bfit", "UCLA", PREMIER);
    GymMember X("student", "account", EXECUTIVE);
    GymMember Y("student2", "account2", REGULAR);

    assert (G.canWorkoutHere(X) == true);
    assert (G.checkin(X, 0, 0, 0, 1) == false);
    assert (G.checkin(X, 0, 0, 0, 0) == true);
    assert (X.workoutsThisMonth() == 1);
    assert (G.getKindAsString() == "PREMIER");
    assert (X.getKindAsString() == "EXECUTIVE");
    assert (X.getKind() == EXECUTIVE);
    
    (G.setFeatures(true, true, true, true));
    
    assert (G.checkin(X, true, false, false, true) == true);
    assert (X.workoutsThisMonth() == 2);
    assert (G.checkin(Y, 1, 1, 1, 1) == false);
    assert (G.canWorkoutHere(Y) == false);
    X.startNewMonth();
    assert (X.workoutsThisMonth() == 0);
    
    
    return 0;
}
