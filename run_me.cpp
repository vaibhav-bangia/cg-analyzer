#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <numeric>
#include<math.h>
#include "myFunctions.h"
using namespace std;

int main()
{
    string file_name;
    // cout << " Enter File Name : ";
    // cin >> file_name;
    string  sem;
    float s3 = 0; 
    float s4 = 0;
    float s5 = 0;  
    // cout << "Enter Your 3,4,5 sem cg : " ;
    // cin >> s3 >> s4 >> s5 ; 
    map<string, vector<float>> m1 = datafilehandling("./TXT/2K18_EE.txt");
    // map<string, vector<float>> m2 = datafilehandling("2K18_4sem.txt");
    // map<string, vector<float>> m3 = datafilehandling("2K18_5sem.txt");

    // pair<int,float> p3 = rankCalculator(m1["EE"],s3);
    // pair<int,float> p4 =  rankCalculator(m2["EE"],s4);
    // pair<int,float> p5 = rankCalculator(m3["EE"],s5);
    // cout << endl << endl  ; 
    // cout << "Your Rank:" << p3.first  <<"/" << m1["EE"].size() << "\t\taverage cg:" << p3.second << endl << endl ; 
    // cout << "Your Rank:" << p4.first <<"/" << m2["EE"].size() << "\t\taverage cg:" << p4.second << endl << endl ; 
    // cout << "Your Rank:" << p5.first <<"/" << m3["EE"].size()<< "\t\taverage cg:" << p5.second << endl << endl ; 
    
    
    // cout << endl
    //      << endl
    //      << endl
    //      << endl;
    //cgCalculator(m1);
    // cout << endl
    //      << endl
    //      << endl
    //      << 1endl;
    // cgCalculator(m2);
    // cout << endl << endl ;
    // cout << endl << endl ;
    // cout << endl << endl ;
    // cout << endl << endl ;
    betterStatsFunction(m1);
    

    
    // dont ever call this!!!!!!!!!!!!!!
    //betterStatsPythonFunction(m1,"2K19sem4");
    cout << "yeayyyyyyy";
    return 0;
}