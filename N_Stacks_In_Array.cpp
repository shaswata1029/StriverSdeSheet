class NStack
{
public:
    // Initialize your data structure.
    int *arr,*top,*next;
    int freeIndex;
    
    NStack(int N, int S)
    {
        // Write your code here.
        arr=new int[S];
        top=new int[N];
        next=new int[S];
        
        for(int i=0;i<N;i++)
            top[i]=-1;
        
        for(int i=0;i<S;i++)
            next[i]=i+1;
        next[S-1]=-1;
        
        freeIndex=0;
    }

    // Pushes 'val' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int val, int m)
    {
        // Write your code here.
        
        if(freeIndex==-1)
            return false;
        
        int index=freeIndex;
       freeIndex=next[freeIndex];
        
        next[index]=top[m-1];
        top[m-1]=index;
        
        arr[index]=val;
        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1]==-1)
            return -1;
        
        int topIndex=top[m-1];
        top[m-1]=next[topIndex];
        
        next[topIndex]=freeIndex;
        freeIndex=topIndex;
        
        return arr[topIndex];
    }
};
