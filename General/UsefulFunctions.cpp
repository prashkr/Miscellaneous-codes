//string to integer
int stoi(string str)
	{
		stringstream id(str);
		int val;
		id >> val;
		return val;
	}
	
	
//Leap Year
bool isLeap(string year)
	{
		int yr;
		yr=stoi(year);
		
		if(yr%4==0 && yr%100!=0)
			return true;
		else if(yr%400==0)
			return true;
		else
			return false;
			
	}

 // For example, we make use of std::count in c++, it counts the number
 // of times the given string appears in regionCounts[].
 (count(regionCounts.begin(), regionCounts.end(), reg) == 1);
 
 
 
 
 //find function.
 // if the element is not there then it returns an iterator to the end of the (vector or for that matter any stl ds).
 find(reginCounts.begin,regionCounts.end(),value)!=regionCounts.end();

 
 
 
 //
  // This magic trick iterates (dx,dy) = (0,1), (1,0), (0,-1), (-1,0)
                    swap(dx,dy);
					dy *= -1;

					
					
					
					
					
					
//Longest Common Subsequence
//m=length of s1, n=length of s2.
int lcs(char *s1, char *s2, int m, int n)
{
    if(m==0 || n==0)
        return 0;
    else if(s1[m-1]==s2[n-1])
    {
        return (1+lcs(s1,s2,m-1,n-1));
    }
    else
    {
        return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
}					


//To check if a the i-th bit of a number n is set, we can see if ( n & 1 << i ) is non-zero.


