
/**************************

Problem Statement
There are ‘N’ Problem Setters in Coding Ninjas, Each of them has a unique id between 0 to N-1. A Problem Setter works in multiple non-overlapping time intervals during a day.
Formally, A Problem Setter having id ‘i’ works in ‘Ki’ non-overlapping intervals of the form [T1, T2], [T3, T4] ... [T(2ki-2), T(2ki-1)], where Ti is in between [0, 10^8] and Ti <= T(i+1). A day in Coding ninjas start from time 0 and end at time 10^8 (both inclusive).
You are given ‘N’ sorted lists of non-overlapping intervals, where the ith list gives a schedule (list of intervals in which the problem setter works) of a Problem Setter having id ‘i’. Your task is to find a sorted list of non-overlapping intervals in which all problem setters are free. If there are multiple possible such lists, output the list which is minimum in length.
Note :
1. In sorted order interval [T1, T2] comes before [T3, T4] if either T1 < T3, or (T1 == T3  and T2 < T4).
2. An interval [T1, T2] represents, time T1, T1+1, T1+2, ... T2, i.e all integers between T1, T2 both T1 and T2 inclusive.  
3. For simplicity, we represent the list of intervals in a 1D array where every two numbers show an interval, i.e list [1, 3, 5, 7, 9, 11] represent intervals [1, 3], [5, 7] and [9, 11] 
4. It is guaranteed that there will be at least one interval where all problem setters are free.
Example :
Let suppose there are 3 problem setters, their working intervals are represented by the following list of lists, ‘Schedules’: [[1, 2, 5, 6], [1,2], [5, 10]], where the ith interval of a setter is represented by 2*i and (2*i+1)th integer in their respective list,  I.e. Problem Setter with an id 0, works in the intervals [1, 2], [5, 6]. Problem Setter with an id 1, work in the interval  [1,2]. Problem Setter with id 2, works in the interval [5, 10], 
In this example, the time intervals where setter 0 is free are [0, 0], [3, 4], [7, 10^8]
And the time intervals where setter 1 is free are [0, 0], [3, 10^8].
And the time intervals where setter 2 is free are [0, 4], [11, 10^8].
We can clearly observe that time intervals, where all 3 setters are free are, [0, 0], [3, 4], and [11, 10^8].  
Thus we should output a list [0, 0, 3, 4, 11, 10^8] that represents these lists in 1D array form as described in notes. It can be shown easily, that this is the minimum possible length list of intervals representing common free time.
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases, then ‘T’ test cases follow.

The first line of each test case consists of a single integer ‘N’ representing the number of problem setters.

Then 2*‘N’ line follows, which gives the ‘schedule’ of each of the problem setters. The 2*i+1th line consist of single even integer ‘Ki’ representing the number of intervals of ith problem setter and (2*i+2)th line consist of 2*Ki space-separated integers representing the list of intervals in a 1-D array.
Output Format :
For each test case, in a separate line print the smallest and sorted list of non-overlapping intervals that give the common free time of ‘N’ problem setters. I.e if there are ‘K’ such intervals, then you need to print 2*K space-separated integers representing this list in a 1-D array. 
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10
1  <= N <= 1000
1 <= K <= 1000

Time limit: 1 sec
Sample Input 1 :
2
1
1
10 20
3
2
1 2 5 6
1
1 2
1
5 10
Sample Output 1 :
0 9 21 100000000
0 0 3 4 11 100000000
Explanation Of Sample Input 1 :
Test case 1:
There is only one problem setter, who is busy during an interval [10, 20].  A day in coding ninjas is given by interval [0, 10^8], thus he will be free between [0, 9] and [21, 10^8]

Test case 2:
See the problem statement for an explanation.
Sample Input 2 :
2
1
1
1 100000000
3
2
1 2 5 6
3
1 1 2 2 3 3
1
0 2
Sample Output 2 :
0 0
4 4 7 100000000
************************************/


#include<bits/stdc++.h>

bool compare(const pair<int,int>&p1,const pair<int,int>&p2){
    if(p1.first!=p2.first)
        return p1.first<p2.first;
    
    return p1.second>p2.second;
}

vector<int> findFreeIntervals(vector<vector<int>> &schedules) {
    /*	
		'schedules': vector of 'N' vectors, where schedules[i] 
					 is a vector of intergers in which every two 
					 numbers shows an interval in which Problem Setter 
					 with id 'i' works.
	*/

	// Write your code here
    
    
    vector<pair<int,int>>times;
    
    for(auto &schedule:schedules){
        int size=schedule.size();
        
        for(int index=0;index<size;index++){
            if(index%2==0)
                times.push_back({schedule[index],1});
            else
                times.push_back({schedule[index],-1});
        }
    }
    
    sort(times.begin(),times.end(),compare);
    
    int size=times.size();
    int startTime=0;
    int endTime=1e8;
    vector<int>res;
    
    if(times[0].first>startTime)
    {
        res.push_back(startTime);
        res.push_back(times[0].first-1);
    }
    
    int curPeople=0;
    for(int index=0;index<size;index++){
        
        if(index!=0 && curPeople==0){
            int start=times[index-1].first+1;
            int end=times[index].first-1;
           
            if(start<=end)
            {
                res.push_back(start);
                res.push_back(end);
            }
        }
        
        curPeople+=times[index].second;
    }
    
    
    if(times[size-1].first<endTime){
        res.push_back(times[size-1].first+1);
        res.push_back(endTime);
    }
    
    return res;
}
