//
//  main.cpp
//  cellplan
//
//  Created by Izma Zuberi on 1/18/22.
//

#include <iostream>
#include <string>
using namespace std;

int main () {
  
    string plan, autopay, paperless, test;
    int lines, gigs, p, gigcost;
    double price;
    p = 0; //initializing the variable

    cout << "What type of cell plan do you have? "; //collecting plan information
    getline(cin, plan);
    if (plan == "Unlimited Elite" || plan == "Unlimited Extra" || plan == "Unlimited Starter" || plan == "Prepaid") {
        cout << "Are you on autopay? ";
        cin >> autopay;
        if (autopay == "Yes" || autopay == "No") {
            cout << "Are you on paperless billing? ";
            cin >> paperless;
            if (paperless == "Yes" || paperless == "No") {
                cout << "How many lines will be on your plan? ";
                cin >> lines;
                if (lines <= 3 && lines >= 1){
                    cout << "How many gigabytes did you consume this month? ";
                    cin >> gigs;
                    if (gigs >= 0 && gigs <= 30) {
                    
                        //calculating cost; p is per line cost

                        if (plan == "Unlimited Elite") //base cost of one line
                        { p = 85;    }
                        if (plan == "Unlimited Extra")
                        { p = 75;    }
                        if (plan == "Unlimited Starter")
                        { p = 65;    }
                        if (plan == "Prepaid")
                        { p = 50;    }
                     
                        if (lines > 1)   //extra line discount
                        { p = p - 10;  }
                        
                        if (autopay == "Yes")   //autopay and paperless discount
                        { p = p - 2;   }
                        if (paperless == "Yes")
                        { p = p - 3;   }
                        
                        if (plan == "Prepaid" && gigs > 4)  //gig cost calc (prepaid only)
                        { gigcost = (gigs - 4)/2 * 10;  }
                        else
                        { gigcost = 0;  }
                        
                        price = (p * lines) + gigcost; //total cost calculation
                       
                        cout.setf(ios::fixed);
                        cout.setf(ios::showpoint);
                        cout.precision(2);
                        cout << "Your " << plan << " cell plan costs $" << price << "." << endl;  //final output
                        
                    } else {
                        cout << "Your gigabytes are not valid!" << endl; }
                } else {
                    cout << "Your lines are not valid!" << endl; }
            } else {
                cout << "Your paperless billing is not valid!" << endl; }
        } else {
            cout << "Your autopay is not valid!" << endl; }
    } else {
        cout << "Your cell plan is not valid!" << endl; }
    
    return 0;
}
