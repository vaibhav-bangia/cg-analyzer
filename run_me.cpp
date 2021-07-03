#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <numeric>
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
    map<string, vector<float>> m1 = datafilehandling("./TXT/2K18_6sem.txt");
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
    cgCalculator(m1);
    // cout << endl
    //      << endl
    //      << endl
    //      << endl;
    // cgCalculator(m2);
    cout << endl << endl ;
    cout << endl << endl ;
    cout << endl << endl ;
    cout << endl << endl ;
    betterStatsFunction(m1);
    // vector< pair<string, map<int,int> > > betterStatsVector = betterStatsFunction(m1); 
    // for(auto&i:m1){
    //     map<int,int> m_xx = betterStats(m1[i.first]);
    //     betterStatsVector.push_back({i.first,m_xx});
    // }
    // for(auto&i:betterStatsVector){
    //     cout << "ANALYSIS OF " << i.first << " branch : " << endl ;
    //     int no_of_student_in_this_branch = 0;  
    //     for(auto j:i.second){
    //         no_of_student_in_this_branch+=j.second;
    //         //float perc = j.second/no_of_student_in_this_branch * 100  ;
            
    //     }  
    //     cout << endl  << no_of_student_in_this_branch << " studssss " << endl ;
    //     for(auto j:i.second){
    //         float x = j.second *0.1 * 10 ;
    //         float y = no_of_student_in_this_branch *0.1 * 10 ;
    //         float perc = x/y ;
    //         cout << j.first << " : " << j.second << "/" << no_of_student_in_this_branch  << "       " << perc  * 100  << endl  ; 
            
    //     }
    //     cout << endl << endl ; 
    // }    
    return 0;
}