#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include<vector>
#include<map>
#include<set>

using namespace std;
struct comp
{
    template<typename T>
    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second)
            return l.second > r.second;
        return l.first > r.first;
    }
};


int main (int argc, char** argv) {
     //clock_t beginTime = clock();
     string temp,str,line;
     int ktuple,begin=0;
     using mypair = pair<string, int>;
     map<string, int> Distribution;
     map<string,int>::iterator it;
     if(argc !=3){
        cout<<"Please enter the parameters as mentioned below:" <<endl;
        cout<<"./DecipheringCode <filename> <k-size>" <<endl;
        exit(0);}
     ktuple=std::atoi(argv[2]);
     // Condition of k should not be > 10 as per the requirement of the problem
     if(ktuple<=10)
     {
     ifstream myfile(argv[1]);
     if (myfile.is_open())
     {
        while(getline (myfile,line))
        {
            //To convert the alphabets into lower case
            transform(line.begin(), line.end(), line.begin(), [](char c){return tolower(c);});
            for(int i=0;i<line.length();i++)
            {
                //Fetching only alphabets based on their ASCII range
                if(((int(line[i])>64) and (int(line[i])<91)) or ((int(line[i])>96) and (int(line[i])<123)))
                {
                    str.push_back(int(line[i]));
                }
            }
        }

        myfile.close();
       }
       else
       {
           cout<< "Could not open the file"<<endl;
       }
     int x=0;
     while((x+ktuple)<=str.length())
     {
        begin=x;
        temp=str.substr(begin,ktuple);
        auto it = Distribution.find(temp);
        if(it != Distribution.end()) 
            it->second = Distribution[temp]+1;
        else
        {    
            Distribution[temp]=1;
        }
        x=x+1;
     }
     //Sorting tuples by their values
     std::set<std::pair<std::string,int>, comp> set(Distribution.begin(), Distribution.end());
     for (auto const &pair: set) 
     {
        std::cout << pair.first << " " << pair.second << '\n';
     }

     }
     else
     {
        cout<<"Allowed k value is <=10"<<endl;
     }
     //clock_t endTime = clock();
     //double elapsedTime = double(endTime - beginTime) / CLOCKS_PER_SEC;
     //cout<<"Time taken in sec: "<< elapsedTime<<endl;
     return 0;
}
