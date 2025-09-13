class Solution {
public:
int Count(vector<int> &Input,vector<int> &Hash){
    int unique = 0;
        for(int x:Input){
            Hash[x] += 1;
            if (Hash[x]==1)
            {
                unique+=1;
            }
        }
        return unique;
    }

    void Copy(vector<int> &Source, vector<int> &Destination){
        for(int i=0;i<Source.size();i++){
            Destination[i] = Source[i];
        }
    }

    void CountingSort(vector<int> &A){
        int max = 0;
        for(int x:A){
            if(max<x){
                max = x;
            }
        }
        
        vector<int> Counts(max+1) ;

        Count(A,Counts);
    
        for(int i=1;i<Counts.size();i++){
            Counts[i] = Counts[i-1] + Counts[i];
        }

        // for(int x:Counts){
        //     cout << x << " ";
        // }

        vector<int> Output(A.size());

        for(int i=A.size()-1;i>=0;i--){
            int index = Counts[A[i]]--;
            Output[index-1] = A[i];
            
            // for(int x:Output){
            //     cout << x << " ";
            // }
            // cout << endl;
        }

        Copy(Output,A);

        // for(int x:A){
        //     cout <<x;
        // }
    }

    int minSetSize(vector<int>&arr) {

        int max = 0;
        for(int x:arr){
            if(max<x){
                max = x;
            }
        }

        vector<int> CountArray;
        {
        vector<int> Hash(max+1);
        int uniques = Count(arr,Hash);
        CountArray.resize(uniques);

        int j = 0;
        for(int i=0;i<Hash.size();i++){
            if (Hash[i]>0)
            {CountArray[j++] = Hash[i];
            }
        }
        }

        CountingSort(CountArray);

        int count = 0,cumm_count = 0,i = CountArray.size()-1;
        while(cumm_count < arr.size()/2){
            cumm_count += CountArray[i--];
            count++;
        }

        return count;
    }
};