/*
    Question 2 - https://docs.google.com/document/d/1FTaCGnjCg8WG962KT44VPiahCaC51RreCk_oEDNlbFc/edit
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(int start,string s,int m,int k,vector<int>&odd,vector<vector<int>> &dp)
{
    if(k==0)  
        return start == s.size();

    if(start>=s.size())
        return 0;

    if(dp[start][k]!=-1)
        return dp[start][k];

    int ans = 0;

    if((s[start]-'0')%2==0)
    {
        int endIndex = lower_bound(odd.begin(),odd.end(),start+m-1) - odd.begin();

        while(endIndex<odd.size())
        {
            ans = ans  +  solve(odd[endIndex]+1,s,m,k-1,odd,dp);
            endIndex++ ;
        }
    }
    return dp[start][k] = ans;
}
int countPartitions(string s, int m , int k)
{
    vector<vector<int>> dp(s.size(),vector<int>(k+1,-1));

    vector<int> odd;
    
    for (int i = 0; i < s.size(); i++)
    {
        if((s[i]-'0')%2==1)
            odd.push_back(i);
    }
    return solve(0,s,m,k,odd,dp);
}

int main()
{
    int n , m,k;
    string s;
    cin>>n;
    cin>>m;
    cin>>k;
    cin>>s;

    cout<<countPartitions(s,m,k);
    return 0;
}