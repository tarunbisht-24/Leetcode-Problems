class NumArray {
public:
  vector<int> arr, original;
  int N;
  
  void AddToElement(int index, int value){     
	  while(index < N){                           
		  arr[index] += value;
		  index = index | (index + 1);
  	}
  }

  void ModifyElement(int index, int value){    
    int delta = value - original[index];
    original[index] = value;
	  AddToElement(index , delta);
  }

  int PrefixSum(int x){                        
	  int prefix_sum = 0;
      for (; x >= 0; x = (x & (x + 1)) - 1) 
        prefix_sum += arr[x];
    
	  return prefix_sum;
  } 
   
  NumArray(vector<int>& nums){                 
    N = nums.size();
    arr.resize(N+1,0);
    original = nums;
    for(int i = 0; i < N ; i++) AddToElement(i, nums[i]);      
  }
    
  void update(int index, int val){
    ModifyElement(index, val);    
  }
    
  int sumRange(int left, int right){          
    return left ? PrefixSum(right) - PrefixSum(left - 1) : PrefixSum(right);    
  }
};
