/*@ 
	requires len > 0;
	requires \valid_read(A+ (0..len-1));
	ensures \forall int i; 1 <= i <= len-1 ==> A[i-1] <= A[i];
*/
void insertion(int *A, unsigned len)
{
	//@ assert len > 0;
	if(len < 2) return;

	int j;
	/*@  loop invariant \forall integer z;
			0 <= z < j ==> A[z] <= A[z+1];
	*/
	for(j=1; j < len; j++)
	{
		int k = A[j];
		int i = j - 1;
		/*@ loop invariant \forall integer y;
				i <= y <= j ==> A[y] >= k;
		*/
		while(i >= 0 && A[i] > k)
		{
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = k;
	}
}


/*@ 
	requires len > 0;
	requires \valid_read(A+ (0..len-1));
	ensures \forall int t; 1 <= t <= len-1 ==> A[t-1] <= A[t];
*/
void bubble(int *A, unsigned len)
{
	if (len < 2) return; 
	//@ assert len >= 2;

	//@ ghost int e = 0; 
	//@ ghost int l = len;
	int i;
	for(i = 0; i < len; i++)
	{
		int j;
		for(j = i+1; j < len; j++)
		{
			if(A[i] >= A[j])
			{
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		} 
		//@ assert A[e] <= \min(e, l-1, \lambda integer g; A[g]);
		//@ ghost e = i;
	}
}

