/*
    Question 1 - https://docs.google.com/document/d/1FTaCGnjCg8WG962KT44VPiahCaC51RreCk_oEDNlbFc/edit
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node
{
    public:
    Node* links[26];
    int prefixLen = 0;
};

class Trie
{
    public:
    Node* root ;
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node* curr = root;
        for(int i = 0;i<s.size();i++)
        {
            int index = s[i]-'a';
            if(curr->links[index]==NULL)
                curr->links[index] = new Node();

            curr = curr->links[index];
            curr->prefixLen++;
        }
    }

    int findScore(string s)
    {
        int score = 0;
        Node* curr = root;
        for(int i = 0;i<s.size();i++)
        {
            int index = s[i]-'a';
            curr = curr->links[index];
            score = score + curr->prefixLen;
        }
        return score;
    }
};

void calculateScore(vector<string>&A)
{
    Trie trie;
    for(int i = 0;i<A.size();i++)
    {
        trie.insert(A[i]);
    }

    for(int i = 0;i<A.size();i++)
    {
        cout<<trie.findScore(A[i])<<endl;
    }
}
int main()
{
    vector<string> arr;
    int n = 0;
    cin>>n;
    string temp;
    for(int i = 0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    calculateScore(arr);
    return 0;
}
