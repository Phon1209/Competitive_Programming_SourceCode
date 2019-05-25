#include "mastermind-lib.h"
#include<bits/stdc++.h>
using namespace std;
#define endl printf("\n")
#define debug(x) cout<< #x << " = " << x;endl;
void find_answer(int N, int K, int U) //U =0 dup
{
	// Complete this function

	// Guessing function format:
	// void guess(string g, int& num_matched, int& num_misplaced)
    int match,misplace;
    if(N==1)
    {
        for(int i=1;i<=K;i++)
        {
            string s="";
            s+=('0'+i);
            // printf("%s\n",s.c_str());
            guess(s,match,misplace);
            if(match==N)return;
        }
    }
    vector<int>  use;
    for(int i=1;i<=K;i++)
    {
        string s="";
        for(int j=0;j<N;j++)s+=('0'+i);
        // printf("%s\n",s.c_str());

        guess(s,match,misplace);
        if(match==N)return;
        for(int j=0;j<match;j++)use.emplace_back(i);
    }
    string s="";
    for(int i=0;i<use.size();i++)
    {
        s+=('0'+use[i]);
    }
    // printf("%s\n",s.c_str());

    guess(s,match,misplace);
    // debug(match);
    if(match==N)return;
    while(next_permutation(use.begin(),use.end()))
    {
        s="";
        for(int i=0;i<use.size();i++)
        {
            s+=('0'+use[i]);
        }
        // printf("%s\n",s.c_str());

        guess(s,match,misplace);
        // debug(match);
        if(match==N)return;
    }
	// Call this function as few times as possible.
	// The answer is correct when num_matches == N.
	// When an error occurs, both returned ref values will be -1.
	// After guessing correctly, return from this function and do not
	// guess any further.

	// To compile:
	// g++ --std=c++11 mastermind-play.cpp mastermind-lib.cpp -o mastermind
	// To run:
	// ./mastermind < input_file
}
