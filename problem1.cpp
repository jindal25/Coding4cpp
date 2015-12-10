/***************************************************************
Given a random string S and another string T with unique elements, find the minimum consecutive sub-string of S such that it contains all the elements in T. 
example: 
S='adobecodebanc' 
T='abc' 
answer='banc'
***************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int findMinWindow(const char *S, const char *T,int* begin,int* end);

int main()
{
	
	int begin=0,end =0;
	int minLength=0;
	const char*S ="adobecodebanc";
	const char *T="abc";
        minLength=findMinWindow(S,T,&begin,&end);
	
	printf("minLength=%d,begin=%d,end=%d \n",minLength,begin,end);
	printf("\nPrinting Min Sub String\n");

	for(int i=0;i<minLength;i++)
        	printf("%c",S[begin+i]);

	return 0;
}



int findMinWindow(const char *S, const char *T,int * begin,int* end ){
        int SLen = strlen(S);
        int TLen = strlen(T);

        // Declare 2 arrays which keep tab of required & found frequency of each char in T
        int isReq[256] ;
        int isFound[256];
	memset(isReq,'0',sizeof(isReq));
        memset(isFound,'0',sizeof(isFound));

        int count = 0; //For valid window

	int minWindow = INT_MAX;

        //Prepare the isReq[] array by parsing the T
        for(int i=0;i<TLen;i++){
            isReq[T[i]]++;
        }

        //Let's start parsing the S now; Take 2 pointers: i and j - both starting at 0
        int i=0, j=0;
        
        //Keep moving j forward, keep i fixed till we get a valid window
        for(int c=j;c<SLen;c++,j++){
           //Check if the character read appears in T or not
           if(isReq[S[c]] == 0){
              //This character does not appear in the T; skip this
              continue;
           }
           //We have this character in the T, lets increment isFound for this char
           isFound[S[c]]++;

           //increment the count if this character satisfies the invariant
           if(isFound[S[c]] <= isReq[S[c]]){
              count++;
           }

           //Did we find a valid window yet?
           if(count == TLen){
              //A valid window is found..lets see if we can do better from here on
              //better means: increasing i to reduce window length while maintaining invariant
              while(isReq[S[i]] == 0 || isFound[S[i]] > isReq[S[i]]){
                   //Either of the above 2 conditions means we should increment i; however we 
                   // must decrease isFound for this char as well.
                   //Hence do a check again
                   if(isFound[S[i]] > isReq[S[i]]){
                      isFound[S[i]]--;
                   }
                   i++;
		   printf("\nIn while loop %c,i=%d,S[c]=%c,c=%d",S[i],i,S[c],c);
              }

               // Note that after the while loop, the invariant is still maintained
               // Lets check if we did better
               int winLength = j-i+1;
	       printf("\nwinLength=%d \n",winLength);

               if(winLength < minWindow){
                  //update the references we got
                  *begin = i;
                  *end = j;
                  //Update new minimum window length
                  minWindow = winLength;
		 // printf("\nminWindow=%d",minWindow);
               }
          } //End of if(count == TLen)
     } //End of for loop 
	return minWindow;
}
