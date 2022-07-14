class MyCalendarTwo {
public:
    map<int,int>booking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        booking[start]++;
        booking[end]--;
        
        int totalBookings=0;
        for(auto &ele:booking){
            totalBookings+=ele.second;
            
            if(totalBookings>2){
                if(booking[start]==1)
                    booking.erase(start);
                else
                    booking[start]--;
                
                if(booking[end]==-1)
                    booking.erase(end);
                else
                    booking[end]++;
                
                return false;
            }
        }
        
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */