class Solution {
public:
    int minOperations(vector<int>& nums) {

        /*
        
        There can only be 2 valid arrays

        0,1,2,3,4....

        4,3,2,1,0....

        lekin first check that is it really possible to make array valid??


        */


        //find 0th idx

        int n=nums.size(),st_idx=-1;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                st_idx=i;
                break;
            }
        }

        cout<<"Start idx is "<<st_idx<<endl;

        //now check is it really possible to make a valid array??


        int next_idx=(st_idx+1)%n;

        int prev_idx=(st_idx-1>=0) ? st_idx-1 : n-1;

        bool next_possible=true,prev_possible=true;


        while(next_idx!=st_idx){

            int prev=(next_idx-1>=0)?next_idx-1:n-1;

            if(nums[prev]+1!=nums[next_idx]){  //agr next
                next_possible=false;   

                
                break;
            }

            cout<<nums[next_idx]<<" ";

            next_idx+=1;

            next_idx=next_idx%n;

        }

        cout<<endl;


        while(prev_idx!=st_idx){


            int next=(prev_idx+1)%n;

            if(nums[next]+1!=nums[prev_idx]){   //agr prev se impossible
                prev_possible=false;   //agr prev possible ho to mtlb 2,1,0,3

                
                break;
            }

            cout<<nums[prev_idx]<<" ";

            prev_idx=(prev_idx-1>=0) ? prev_idx-1 : n-1;


        }

        cout<<endl;
        if(!next_possible)
        cout<<"next is not possible"<<endl;

        if(!prev_possible)
        cout<<"prev is not possible"<<endl;
        if(!prev_possible and !next_possible) return -1;


        //abh agr yha tak aage hai mtlb valid hai array




        //bss abh yeh dekhna hai ki 0,1,2,3..n  yaa fir  n-1,n-2,..0 which is efficient in terms of cost


        //agr ham 0,1,2,3 nhi bna skte direct too pehle 2,1,0 banao then reverse

        int ans=INT_MAX;

        if(next_possible){//agr next possible hai too 3,0,1,2

            ans=min(ans,st_idx); //normal rotate krne pr

            ans=min(ans,n-st_idx+2);    


        }

        if(prev_possible){

            ans=min(ans,(st_idx+1)+1);

            ans=min(ans,n-st_idx);  
        }

        return ans;
        
    }
};