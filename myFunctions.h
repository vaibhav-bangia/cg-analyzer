#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <numeric>
#include <math.h>
using namespace std;
std::vector<float> cg;
vector<string> pattern_arr = {"AE", "BT", "CE", "CO", "EC", "EE", "EL", "EN", "EP", "IT", "MC", "ME", "PE", "PS", "SE"};
map<int,int> betterStats(vector<float> cg){
    map<int,int> freq; 
    for(auto &num:cg){
        freq[int(num)]++;
    }
    return freq;
}
vector<int> betterStatsPython(vector<float>cg){
    // returns a vector (frequency vector)
    // taks a vector (cg vecotr of a branch)
    vector<int> result(11); // 0 to 10 cg 
    for(auto &num:cg){
        result[int(num)]++;
    }
    return result;
}
void cgCalculator(map<string, vector<float>> m)
{
    for (auto &i : m)
    {
        cout << "Branch Name: " << i.first << '\t';
        int no_of_students = i.second.size();
        cout << "No of Students " << no_of_students << '\t';
        float sum_of_elements = std::accumulate(i.second.begin(), i.second.end(), 0.0);
        cout << "AVERAGE: " << sum_of_elements / no_of_students;
        cout << endl
             << endl;
    }
    return;
}
bool exists(string text, string pattern)
{
    if (text.find(pattern) != string::npos)
    {
        return true;
    }
    return false;
}
float PrintMatches2(std::string str, std::regex reg)
{

    // This holds the first match
    std::sregex_iterator currentMatch(str.begin(),
                                      str.end(), reg);
    // Used to determine if there are any more matches
    std::sregex_iterator lastMatch;
    float num = 0;
    // While the current match doesn't equal the last
    while (currentMatch != lastMatch)
    {
        std::smatch match = *currentMatch;
        //std::cout << match.str() << "\n";
        string s = match.str();
        float digit = std::stoi(s.substr(0, 1));
        float fraction = std::stoi(s.substr(2));
        num = digit + fraction / 100;
        cg.push_back(num);
        currentMatch++;
    }
    return num;
}
void getIndex(vector<float> v, int K)
{
    sort(v.begin(), v.end(), greater<int>());
    //printing the vector

    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        cout << index << endl;
    }
    else
    {
        // If the element is not
        // present in the vector
        cout << "-1" << endl;
    }
}
pair<int,float>  rankCalculator(vector< float> dept_cg, float my_cg){
    int no_of_students = dept_cg.size();
    float sum_of_elements = std::accumulate(dept_cg.begin(), dept_cg.end(), 0.0);
    float avg = sum_of_elements / no_of_students;
    
    sort(dept_cg.begin(),dept_cg.end());
    reverse(dept_cg.begin(),dept_cg.end());
    auto it = find(dept_cg.begin(), dept_cg.end(), my_cg);

    // If element was found
    if (it != dept_cg.end())
    {

        // calculating the index
        // of K
        int index = it - dept_cg.begin();
        return {index+1,avg}; 
    }
    return {-1,-1}; 
    
}
map<string, vector<float>> datafilehandling(string file_name)
{
    map<string, vector<float>> m;
    // opening file in read mode
    ifstream fin;

    fin.open(file_name);
    string branch;
    // cout << "ENTER PATTERN :";
    string pattern;
    // cin >> pattern;
    string tp;

    while (getline(fin, tp))
    { //read data from file object and put it into string.
        for (int i = 0; i < pattern_arr.size(); i++)
        {
            pattern = "/" + pattern_arr[i] + "/" ;
            if (exists(tp, pattern))
            {
                //cout << tp << endl ;
                if (exists(tp, "10.00")){
                    m[pattern_arr[i]].push_back(10.0);
                }
                std::string str14 = tp;
                std::regex reg14("[1-9][.][0-9][0-9]");
                //print the data of the string
                float num = PrintMatches2(str14, reg14);
                m[pattern_arr[i]].push_back(num);
            }
        }
    }
    // closing the file
    fin.close();
    return m;
}
void  betterStatsFunction(map<string, vector<float>> m1){
    vector< pair<string, map<int,int> > > betterStatsVector ; 
    for(auto&i:m1){
        map<int,int> m_xx = betterStats(m1[i.first]);
        betterStatsVector.push_back({i.first,m_xx});
    }
    for(auto&i:betterStatsVector){
        cout << "ANALYSIS OF " << i.first << " branch : " << endl ;
        int no_of_student_in_this_branch = 0;  
        for(auto j:i.second){
            no_of_student_in_this_branch+=j.second;
            //float perc = j.second/no_of_student_in_this_branch * 100  ;
            
        }  
        cout << endl  << no_of_student_in_this_branch << " studssss " << endl ;
        for(auto j:i.second){
            float x = j.second *0.1 * 10 ;
            float y = no_of_student_in_this_branch *0.1 * 10 ;
            float perc = x/y ;
            cout << j.first << " : " << j.second << "/" << no_of_student_in_this_branch  << "       " << perc  * 100  << endl  ; 
            
        }
        cout << endl << endl ; 
    }    
}

void  betterStatsPythonFunction(map<string, vector<float>> m1,string add_me_string){
    
    // will store the frequcey vector of all branches
    vector< pair<string, vector<int> > > betterStatsVector ; 
    
    for(auto&i:m1){
        // we send a vector and recieve a vector
        vector<int> m_xx = betterStatsPython(m1[i.first]);
        betterStatsVector.push_back({i.first,m_xx});
    }
    for(auto&i:betterStatsVector){
        float no_of_student_in_this_branch = 0.0;  
        vector<int> freq = i.second;
        // traversing over frequcney vector of this bracnh
        for(auto num:freq){
            no_of_student_in_this_branch+=num;
        }
        vector<float> perc_vector(11,0);
        for(int it=0;it<=10;it++){
            perc_vector[it]=(freq[it]/no_of_student_in_this_branch *0.1*10*100);
            // rounding to 2 decimal places
            // float n = perc_vector[it];
            // int pq = floor(n);
            // float yz = n - pq ; 
            // yz = int(yz * 100);
            // n = pq + yz/100 *0.1*10;  
            // perc_vector[it] = n;
        }
        std::ofstream outfile;
        outfile.open("percentages.py", std::ios_base::app); // append instead of overwrite
        string copy_this_string =i.first + add_me_string   ;
        copy_this_string = copy_this_string + "= [" ;
        for(int x=0;x<=10;x++){
            copy_this_string =copy_this_string+  to_string(perc_vector[x])  ;
            if(x!=10){
                copy_this_string = copy_this_string +",";
            }
        }
        copy_this_string = copy_this_string + "] \n" ;
        outfile << copy_this_string; 
        // copy vector to pyton file
        cout << endl << endl ; 
    }    
}