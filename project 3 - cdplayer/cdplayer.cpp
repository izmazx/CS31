//
//  main.cpp
//  project3
//
//  Created by Izma Zuberi on 1/30/22.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidCDPlayerString(string cdstring);
bool isOpen(string cdstring);
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
int currentTrack(string cdstring);

bool isValidCDPlayerString(string cdstring)
{
    
    if (cdstring.size() == 0) //cd string must not be empty
        return (false);
    
    if (cdstring.at(0) != 'O') //first char must be 'O'
        return (false);
    
    
    bool isOpen = false;
    bool hasCD = false;
    bool isPlaying = false;
    int currentTrack = 0;
    
    //checks for valid chars and order of chars
    for (size_t pos = 0; pos < cdstring.size(); pos++)
    {
        char c = cdstring.at(pos);
        switch (c)
        {
            case 'O':
                if (isOpen == true)
                    return (false);
                isOpen = true;
                isPlaying = false;
                break;
            case 'I':
                if (isOpen == false || hasCD == true)
                    return (false);
                hasCD = true;
                currentTrack = 0; //inserting new CD resets track counter
                break;
            case 'R':
                if (hasCD == false || isOpen == false)
                    return (false);
                hasCD = false;
                break;
            case 'C':
                if (isOpen == false)
                    return (false);
                isOpen = false;
                break;
            case 'P':
                if (hasCD == false || isOpen == true)
                    return (false);
                isPlaying = true;
                break;
            case 'S':
                if (isPlaying == false)
                    return (false);
                isPlaying = false;
                break;
            case '1': //49 in ASCII
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (isPlaying == false || currentTrack != c - 49 )
                    return (false);
                currentTrack++;
                break;
            default:
                return (false);
        }
    }
    return (true); //when all conditions are met, returns true
}



bool isOpen(string cdstring)
{
    if (isValidCDPlayerString(cdstring) == true)
    {
        bool open = false;
        for (size_t pos = 0; pos < cdstring.size(); pos++)
        {
            char e = cdstring.at(pos);
            if (e == 'O')
                open = true;
            if (e == 'C')
                open = false;
        }
        return (open);
    }
    else
    {
        return (false);
    }
}

bool hasCD(string cdstring)
{
    if (isValidCDPlayerString(cdstring) == true)
    {
        bool CD = false;
        for (size_t pos = 0; pos < cdstring.size(); pos++)
        {
            char e = cdstring.at(pos);
            if (e == 'I')
                CD = true;
            if (e == 'R')
                CD = false;
        }
        return (CD);
    }
    else
    {
        return (false);
    }
}

int totalTracksPlayed(string cdstring)
{
    if (isValidCDPlayerString(cdstring) == true)
    {
        int tracksPlayed = 0;
        for (size_t pos = 0; pos < cdstring.size(); pos++)
        {
            char c = cdstring.at(pos);
            switch (c)
            {
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    tracksPlayed++;
                    break;
                default:
                    break;
            }
        }
        return (tracksPlayed);
    }
    else
    {
        return (-1);
    }
}

int currentTrack(string cdstring)
{
    if (isValidCDPlayerString(cdstring) == true)
    {
        int track = -1;
        for (size_t pos = 0; pos < cdstring.size(); pos++)
        {
            char c = cdstring.at(pos);
            switch (c)
            {
                case 'I': //inserting a new cd resets the track counter
                    track = 1;
                    break;
                case 'R': //removing CD sets to -1
                    track = -1;
                    break;
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    track = c - 48 + 1; //48 is 0 on ascii chart
                    break;
            }
        }
        return (track);
    }
    else
    {
        return (-1);
    }
}

void testone(int n)
{
    switch (n)
    {
        case  1:
            assert( !isValidCDPlayerString( "" ) );
            break;
        case  2:
            assert( !isValidCDPlayerString( "     " ) );
            break;
        case  3:
            assert( !isValidCDPlayerString("SCRIPP") );
            break;
        case  4:
            assert( !isValidCDPlayerString("123") );
            break;
        case  5:
            assert( !isValidCDPlayerString("OC+-") );
            break;
        case  6:
            assert( !isValidCDPlayerString("OC123") );
            break;
        case  7:
            assert( !isValidCDPlayerString("OCC") );
            break;
        case  8:
            assert( !isValidCDPlayerString("OCOO") );
            break;
        case  9:
            assert( !isValidCDPlayerString("OCIRRC" ) );
            break;
        case 10:
            assert( !isValidCDPlayerString("OCIIRC") );
            break;
        case 11:
            assert( !isValidCDPlayerString("OICR") );
            break;
        case 12:
            assert( !isValidCDPlayerString( "OIRCP" ) );
            break;
        case 13:
            assert( !isValidCDPlayerString("OCP") );
            break;
        case 14:
            assert( !isValidCDPlayerString("OICS"));
            break;
        case 15:
            assert( !isValidCDPlayerString("OICPSS") );
            break;
        case 16:
            assert( !isValidCDPlayerString("OICP123SS") );
            break;
        case 17:
            assert( !isValidCDPlayerString("OICPSR") );
            break;
        case 18:
            assert( !isValidCDPlayerString("PS") );
            break;
        case 19:
            assert( !isValidCDPlayerString("SP"));
            break;
        case 20:
            assert( !isValidCDPlayerString("OIP123") );
            break;
        case 21:
            assert( !isValidCDPlayerString("OIRCP123") );
            break;
        case 22:
            assert( !isValidCDPlayerString("OICPOI")  );
            break;
        case 23:
            assert( !isValidCDPlayerString("OICP789S") );
            break;
        case 24:
            assert( !isValidCDPlayerString("ORICP123S") );
            break;
        case 25:
            assert( !isValidCDPlayerString("OIRIRCP789S") );
            break;
        case 26:
            assert( !isValidCDPlayerString("oic") );
            break;
        case 27:
            assert( !isValidCDPlayerString("OIC      ") );
            break;
        case 28:
            assert( !isValidCDPlayerString("OICoic") );
            break;
        case 29:
            assert( !isValidCDPlayerString("OIRIRCC") );
            break;
        case  30:
            assert( isValidCDPlayerString("OIC") );
            break;
        case  31:
            assert( isValidCDPlayerString("OIRC") );
            break;
        case  32:
            assert( isValidCDPlayerString("OIRIRC") );
            break;
        case  33:
            assert( isValidCDPlayerString("OICP123") );
            break;
        case  34:
            assert( isValidCDPlayerString("OICP123S") );
            break;
        case 35:
            assert( isValidCDPlayerString("OICP123SP456") );
            break;
        case  36:
            assert( isValidCDPlayerString("OICP123SP456S") );
            break;
        case  37:
            assert( isValidCDPlayerString("OICP123SP456SORICP123") );
            break;
        case  38:
            assert( isValidCDPlayerString("OICPS") );
            break;
        case 39:
            assert( isValidCDPlayerString("OIRICP") );
            break;
        case 40:
            assert( isOpen( "hello" ) == false );
            break;
        case 41:
            assert( isOpen( "" ) == false );
            break;
        case 42:
            assert( isOpen( "   " ) == false);
            break;
        case 43:
            assert( isOpen( "m1o+20" ) == false  );
            break;
        case 44:
            assert( isOpen( "OIC" ) == false);
            break;
        case 45:
            assert( isOpen( "OIRCP" ) == false );
            break;
        case 46:
            assert( isOpen("OICP") == false );
            break;
        case 47:
            assert( isOpen( "OI" )  );
            break;
        case 48:
            assert( isOpen( "OIR" ) );
            break;
        case 49:
            assert( isOpen( "OIRIR" ) );
            break;
        case 50:
            assert( isOpen( "OICP123O" ) );
            break;
        case 51:
            assert( isOpen("OICP123SP456SO") );
            break;
        case 52:
            assert( hasCD( "COPS" ) == false );
            break;
        case 53:
            assert( hasCD( "SCOOP" ) == false);
            break;
        case 54:
            assert( hasCD( "OIR" ) == false);
            break;
        case 55:
            assert(hasCD( "OIRIR" ) == false);
            break;
        case 56:
            assert( hasCD( "OICR" ) == false);
            break;
        case 57:
            assert( hasCD("OCPS") == false );
            break;
        case 58:
            assert( hasCD( "OI" ) );
            break;
        case 59:
            assert( hasCD( "OICP123O" ) );
            break;
        case 60:
            assert( hasCD( "OICP123SO" ) );
            break;
        case  61:
            assert( hasCD( "OIRIRICP123SP456" ) );
            break;
        case 62:
            assert( hasCD( "OICPSO" ) );
            break;
        case 63:
            assert( hasCD("OIRIRICP123SORI")  );
            break;
        case  64:
            assert( currentTrack( "hello" ) == -1 );
            break;
        case  65:
            assert( currentTrack( "" ) == -1 );
            break;
        case  66:
            assert( currentTrack( "    " ) == -1);
            break;
        case  67:
            assert( currentTrack( "COOS" ) == -1 );
            break;
        case 68:
            assert( currentTrack( "POPO" ) == -1 );
            break;
        case  69:
            assert( currentTrack( "123" ) == -1 );
            break;
        case 70:
            assert( currentTrack("OIRIRC") == -1 );
            break;
        case  71:
            assert( currentTrack( "OIC" ) == 1 );
            break;
        case  72:
            assert( currentTrack( "OICP123" ) == 4 );
            break;
        case 73:
            assert( currentTrack( "OIRICP123SP456" ) == 7 );
            break;
        case 74: 
            assert( currentTrack( "OICPS" ) == 1);
            break;
        case 75:
            assert( currentTrack( "OICP123SORICP123" ) == 4 );
            break;
        case 76:
            assert( currentTrack("OICP123SORICP12345") == 6 );
            break;
        case 77:
            assert( totalTracksPlayed( "" ) == -1 );
            break;
        case 78:
            assert( totalTracksPlayed( "hershey bar" ) == -1);
            break;
        case 79:
            assert( totalTracksPlayed( "    " ) == -1 );
            break;
        case 80:
            assert( totalTracksPlayed( "OICR" ) == -1 );
            break;
        case 81:
            assert( totalTracksPlayed( "OIRCP" ) == -1 );
            break;
        case 82:
            assert( totalTracksPlayed( "OCP" ) == -1 );
            break;
        case 83:
            assert( totalTracksPlayed("OICP123+-") == -1 );
            break;
        case 84:
            assert( totalTracksPlayed( "OIC" ) == 0 );
            break;
        case 85:
            assert( totalTracksPlayed( "OIRC" ) == 0);
            break;
        case 86:
            assert( totalTracksPlayed( "OICP123SP456SORICP123" ) == 9);
            break;
        case 87:
            assert( totalTracksPlayed( "OICP123" ) == 3);
            break;
        case 88:
            assert( totalTracksPlayed( "OICP123S" ) == 3 );
            break;
        case 89:
            assert( totalTracksPlayed("OICP123SP456") == 6 );
            break;
                    
        default:
            cout << "Bad argument" << endl;
            break;
    }
}

int main()
{
    for(int n = 0; n < 90; n++)
    {
    testone(n);
    cout << "Passed test " << n << "!" << endl;
    }
        return( 0 );
}

//fails test cases 70, 71, 73, 74
//resolved.
