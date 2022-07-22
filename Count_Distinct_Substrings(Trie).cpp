
/****************************************88
Problem Statement
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.
Note :
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 

Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases.

Then, the ‘T’ test cases follow.

The first line of each test case contains a string.
Output Format :
For each test case, print an integer denoting the number of distinct substrings in the given string.

The output for each test case will be printed in a separate line.
Note :
You don’t need to print anything, It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= |S| <= 10^3

‘S’ contains only lowercase English letters.

Time Limit: 1 sec
Sample Input 1 :
2
sds
abc
Sample Output 1 :
6
7
Explanation Of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }

In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.
Sample Input 2 :
2
aa
abab
Sample Output 2 :
3
8
Explanation Of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }

************************************/


#include<bits/stdc++.h>

class Node{
    vector<Node*>child;
    bool isEnd;
    
    public:
    Node(){
        for(int index=0;index<26;index++)
            child.push_back(NULL);
        isEnd=false;
    }
    
    bool containsKey(char ch){
        if(child[ch-'a']==NULL)
            return false;
        return true;
    }
    
    void put(char ch){
        child[ch-'a']=new Node();
    }
    
    Node * getNext(char ch){
        return child[ch-'a'];
    }
    
    void setIsEnd(){
        isEnd=true;
    }
    
    
};

class Trie{
  Node* root;
    
    public:
    Trie(){
        root=new Node();
    }
    
    int insert(string &word){
        Node *node=root;
        int size=word.size();
        
        int count=0;
        for(int index=0;index<size;index++){
            char ch=word[index];
            
            if(!node->containsKey(ch)){
                count++;
                node->put(ch);
            }
            
            node=node->getNext(ch);
            node->setIsEnd();
        }
        
        return count;
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int size=s.size();
    Trie trie;
    
    int totalCount=1;
    for(int index=0;index<size;index++){
        string newStr=s.substr(index);
        totalCount+=trie.insert(newStr);
    }
    
    return totalCount;
}
