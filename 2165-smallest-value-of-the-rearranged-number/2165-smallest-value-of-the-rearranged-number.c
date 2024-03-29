

long long smallestNumber(long long num){
if (num == 0)
		return num;
		
	//find length of long long
	long long x = num; 
	if (x < 0)
		x = -x;
	int size = 0;
	while (x != 0)
	{
		int digit = x%10;
		size++;
		x /= 10;
	}
	
	//array of digits
	int nums[size]; 
	int i = 0;
	x = num;
	while (x != 0)
	{
		int digit = x%10;
		nums[i++] = digit;
		x /= 10;
	}
	
	//shell sort array
	for (int n = size/2; n > 0; n /= 2)
	{
		for (int j = n; j < size; j++)
		{
			int k, temp = nums[j];
			for (k = j; k >= n && nums[k - n] > temp; k -= n)
				nums[k] = nums[k - n];
				nums[k] = temp;
		}
	}
	
	//checking that the first digit is not zero when original number is positive
	if (num > 0 && nums[0] == 0)
	{
		int i = 0;
		while (nums[i] == 0){
			i++;
		}
		nums[0] = nums[i];
		nums[i] = 0;
	}

	//turning the array into a number
	long long result = 0;
	for (int i = 0; i < size; i++)
	{
		result = result*10 + nums[i];
	}

	return result;

}