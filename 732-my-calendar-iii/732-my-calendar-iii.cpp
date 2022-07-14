class MyCalendarThree {
public:
    map<int,int>booking;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        booking[start]++;
        booking[end]--;
        
        int totalBookings=0;
        int maxBookings=0;
        
        for(auto &ele:booking){
            totalBookings+=ele.second;
            maxBookings=max(maxBookings,totalBookings);
        }
        
        
        return maxBookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */