#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int solve(vector<int> &c,vector<vector<int>> &edges,int src,int len,unordered_map<int,int>&freq,int maxFreq)
{
    int ans = 0;
    freq[c[src]]++;
    maxFreq = max(maxFreq,freq[c[src]]);
    
    if(maxFreq>=ceil(len/2.0))
        ans++;

    for(int dest : edges[src])
    {
        ans = ans + solve(c,edges,dest,len+1,freq,maxFreq);
    }
    freq[c[src]]--;
    
    return ans;
}
int countGoodPaths(int n,vector<int> &c,vector<vector<int>> &edges)
{
    unordered_map<int,int> freq;
    return solve(c,edges,1,1,freq,1);
}
int main()
{
    int n;

    cin>>n;

    vector<int> c(n+1,0);

    for(int i = 0;i<n;i++)
    {
        cin>>c[i];
    }

    vector<vector<int>> edges(n+1);
    int src = 0;
    int dest = 0 ;

    for(int i = 1;i<=n-1;i++)
    {
        cin>>src;
        cin>>dest;
        edges[src].push_back(dest);
        
    }
    cout<<countGoodPaths(n,c,edges);
    return 0;
}

/*

Test Case 
6
1 2 1 3 1 1
1 6
1 4
4 5
4 2
4 3
ans - 5
*/

/*

If directed tree not works then can try with undirected tree.

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int solve(vector<int> &c,vector<vector<int>> &edges,int src,int len,unordered_map<int,int>&freq,int maxFreq,int parent)
{
    int ans = 0;
    freq[c[src]]++;
    maxFreq = max(maxFreq,freq[c[src]]);
    
    if(maxFreq>=ceil(len/2.0))
        ans++;

    for(int dest : edges[src])
    {
        if(dest!=parent)
            ans = ans + solve(c,edges,dest,len+1,freq,maxFreq,src);
    }
    freq[c[src]]--;
    
    return ans;
}
int countGoodPaths(int n,vector<int> &c,vector<vector<int>> &edges)
{
    unordered_map<int,int> freq;
    return solve(c,edges,1,1,freq,1,-1);
}
int main()
{
    int n;

    cin>>n;

    vector<int> c(n+1,0);

    for(int i = 0;i<n;i++)
    {
        cin>>c[i];
    }

    vector<vector<int>> edges(n+1);
    int src = 0;
    int dest = 0 ;

    for(int i = 1;i<=n-1;i++)
    {
        cin>>src;
        cin>>dest;
        edges[src].push_back(dest);
        edges[dest].push_back(src);
        
    }
    cout<<countGoodPaths(n,c,edges);
    return 0;
}
*/