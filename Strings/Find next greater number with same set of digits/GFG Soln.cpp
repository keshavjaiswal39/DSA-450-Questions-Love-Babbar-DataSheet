class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
    // code here
    int i,j;
	
	for(i=N-1;i>0;i--)
	{
		if(arr[i]>arr[i-1])
			break;
	}
	
	if(i==0)
	{
		reverse(arr.begin(),arr.end());
		return arr;
	}
	
	int x=arr[i-1],smallest=i;
	
	for(j=i;j<N;j++)
	{
		if(arr[j]>x and arr[j]<arr[smallest])
			smallest=j;	
	}
	
	swap(arr[smallest],arr[i-1]);
	
	reverse(arr.begin()+i,arr.end());
	
	
	return arr;
    }
};
