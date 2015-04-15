//calculate (a^b)%m


LL BIGMOD(LL a, LL b, LL m)
{
	if(b == 0) return 1%m;
	
	LL x = BIGMOD(a, b/2, m);
	x = (x*x)%m;
	
	if(b&1) x = (x*a)%m;   // if 'b' is odd
	
	return x;
}