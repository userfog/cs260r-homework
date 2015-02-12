unsigned int ret;
int bit_wise_add(unsigned int x, unsigned int y)
{	
	unsigned int sum = 0;
	unsigned int carry = (x & y) << 1;
	sum = x ^ y;

	while(sum & carry){
		carry = (sum & carry) << 1;
		sum = sum ^ carry;
	}
	
	ret = sum ^ carry;
	//@ assert ret == x + y;
	return ret;
}
