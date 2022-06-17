int diameter = 0;
int findDiameter(Node* root) {
//write your code here

if(root==NULL)
return 0;

int firstMax=0;
int secondMax=0;

for(auto child:root->children){
    int maxHeight=findDiameter(child);
    if(maxHeight>=firstMax){
        secondMax=firstMax;
        firstMax=maxHeight;
    }else if(maxHeight>=secondMax)
        secondMax=maxHeight;
}

diameter=max(diameter,firstMax+secondMax);

return 1+firstMax;
}
