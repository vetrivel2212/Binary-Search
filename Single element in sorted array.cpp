class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int low = 0;
        int high = a.size()-2;
        int mid ;
        while(low <= high)
        {
            mid = (high+low)/2;
            if(mid % 2 == 0) 
            {
                if(a[mid]==a[mid+1])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if(a[mid]==a[mid-1]){
                    low = mid +1;
                }
                else
                {
                    high = mid-1;
                }

            }
        }
        return a[low];
    }
};
