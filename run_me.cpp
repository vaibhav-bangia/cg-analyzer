#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <numeric>
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
    map<string, vector<float>> m1 = datafilehandling("2K19_4sem.txt");
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
    return 0;
}