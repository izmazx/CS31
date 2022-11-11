//
//  main.cpp
//  proj4
//
//  Created by Izma Zuberi on 2/15/22.
//

#include <iostream>
#include <string>
using namespace std;

int locateMinimum(const string array[], int n);
int countCommonElements(const string array1[], int n1, const string array2[], int n2);
int countVowels(const string array[], int n);
bool hasThreeOfX(const string array[], int n, string x);
string majorityElement(const string array[], int n);
bool shiftRight(string array[], int n, int amount, string placeholder);
bool rotateLeft(string array[], int n, int amount);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);


int main() {
    string folks[7] = { "AA", "AA", "BB", "AA", "cc", "dd", "ee" };
    string folks1[7] = { "aa", "AA", "BB", "BB", "cc", "dd", "ee" };
    
    cout << locateMinimum(folks, 7) << endl;
    cout << countVowels(folks, 7) << endl;
    cout << countCommonElements(folks, 7, folks1, 7) << endl;
    cout << hasThreeOfX(folks, 7, "AA") << endl;
    cout << majorityElement(folks, 7) << endl;
    cout << shiftRight(folks, 7, 3, "boo") << endl;
    cout << rotateLeft(folks1,7,8) << endl;
    cout << replaceAll(folks1, 7, 'a', 'z') << endl;
    cout << folks[0] << endl;
    cout << folks[1] << endl;
    cout << folks[2] << endl;
    cout << folks[3] << endl;
    cout << folks[4] << endl;
    cout << folks[5] << endl;
    cout << folks[6] << endl;

    
    return 0;
}

//done
int locateMinimum(const string array[], int n)
{
    if (n <= 0)
        return (-1);
    
    int stringpos = 0;
    int minimum = 0;
  
    for (int arraypos = 0; arraypos < n; arraypos++)
    {
        //compares each char in the string to smallest indexed string
        while (array[arraypos][stringpos] == array[minimum][stringpos] && stringpos < array[minimum].size())
        {
            stringpos++;
        }
        //replace minimum string if next string in array is smaller
        if (array[arraypos][stringpos] < array[minimum][stringpos])
            minimum = arraypos;
        stringpos = 0; //reset before checking next string
    }
    return(minimum);
}

//done
int countCommonElements(const string array1[], int n1, const string array2[], int n2)
{
    if (n1 <= 0 || n2 <= 0)
        return (-1);
    
    //loop thru both arrays and add to count if matching element is found
    int count = 0;
    for (int pos1 = 0; pos1 < n1; pos1++)
    {
        for (int pos2 = 0; pos2 < n2; pos2++)
        {
            if (array1[pos1] == array2[pos2])
                count++;
        }
    }
    return (count);
}

//done
int countVowels(const string array[], int n)
{
    if (n <= 0)
        return (-1);
    
    //loop thru each string of array, add to count if vowel is found
    int vowelcount = 0;
    for (int arraypos = 0; arraypos < n; arraypos++)
    {
        for (size_t stringpos = 0; stringpos < array[arraypos].size(); stringpos++)
        {
            char c = array[arraypos].at(stringpos);
            switch (c)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                    vowelcount++;
                    break;
            }
        }
    }
    return (vowelcount);
}

//done
bool hasThreeOfX(const string array[], int n, string x)
{
    if (n <= 0)
        return false;
    //count how many times x appears, 3 times true, anything else false
    int countx = 0;
    for (int pos = 0; pos < n; pos++)
    {
        if (array[pos] == x)
            countx++;
    }
    if (countx == 3)
        return true;
    else
        return false;
}

//done
string majorityElement(const string array[], int n)
{
    string majority = "";
    //array loops thru itself and adds count if same element is found multiple times
    //if found > n/2 times, returns as majority
    for (int pos = 0; pos < n; pos++)
    {
        int count = 0;
        for (int pos1 = 0; pos1 < n; pos1++)
        {
            if(array[pos] == array[pos1])
                count++;
        }
        if (count > n/2)
            majority = array[pos];
    }
    return(majority);
}


//done
bool shiftRight(string array[], int n, int amount, string placeholder)
{
    if (n <= 0 || amount <= 0)
        return false;
    
    if (amount > n) //entire array becomes placeholder if amount > n
    {
        for (int pos = 0; pos < n; pos++)
        {
            array[pos] = placeholder;
        }
        return true;
    }
    
    //shifts positions of array by amount
    for (int arraypos = n - 1; arraypos > amount - 1; arraypos--)
    {
        array[arraypos] = array[arraypos - amount];
        
    }
    //replaces empty spots with placeholder
    for (int placeholderpos = 0; placeholderpos < amount; placeholderpos++)
    {
        array[placeholderpos] = placeholder;
    }
    
    return true;
}

//done
bool rotateLeft(string array[], int n, int amount)
{
    if (n <= 0 || amount%n == 0)
        return false;
    
    //to account for amount > n
    while (amount > n)
        amount = amount - n;
    //rotates values of array by amount
    for (int pos = 0; pos < n - amount; pos++)
    {
        string hold = array[pos];
        array[pos] = array[pos + amount];
        array[pos + amount] = hold;
    }
    
    return true;
}

//done
int replaceAll(string array[], int n, char letterToReplace, char letterToFill)
{
    if (n <= 0)
        return (-1);
    //loop thru array
    int replacement = 0;
    for (int pos = 0; pos < n; pos++)
    {
        string unit = array[pos];
        //loop thru each string of array and replace char
        for (size_t stringpos = 0; stringpos < unit.size(); stringpos++)
        {
            char c = unit.at(stringpos);
            if (c == letterToReplace)
            {
                array[pos].at(stringpos) = letterToFill;
                replacement++;
            }
        }
    }
    return (replacement);
}
