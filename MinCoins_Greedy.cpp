int findMinimumCoins(int amount) 
{
    // Write your code here
    
    int denominations[9]={1,2,5,10,20,50,100,500,1000};
    
    int curIdx=8;
    int minCoins=0;
    
    while(amount>0){
        int coins=amount/denominations[curIdx];
        minCoins+=coins;
        amount=amount-coins*denominations[curIdx];
        curIdx--;
    }
    
    return minCoins;
    
    
}
