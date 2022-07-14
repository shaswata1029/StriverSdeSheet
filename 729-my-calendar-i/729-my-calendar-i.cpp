class MyCalendar {
public:
    map<int,int>calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(calendar.size()==0){
            calendar[start]=end;
            return true;
        }
        
        auto it=calendar.upper_bound(start);
        
        if(it!=calendar.end()){
            int nextStart=(*it).first;
            if(end>nextStart)
                return false;
        }
        
        if(it!=calendar.begin()){
            it--;
            int prevEnd=(*it).second;
            if(start<prevEnd)
                return false;
        }
        
        calendar[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */