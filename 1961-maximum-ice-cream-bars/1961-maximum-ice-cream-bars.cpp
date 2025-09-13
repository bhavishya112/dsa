class Solution {
public:
    void Count(vector<int> &Input,vector<int> &Hash){
        for(int x:Input){
            Hash[x] += 1;
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

        vector<int> Output(A.size());

        for(int i=A.size()-1;i>=0;i--){
            int index = Counts[A[i]]--;
            Output[index-1] = A[i];
            
        }

        A = Output;

    }
        
    int maxIceCream(vector<int>& costs, int coins) {
        CountingSort(costs);

        int count = 0;
        
        // for(int x:costs){
        //     cout << x << " ";
        // }
        // cout << endl;

        for(int x:costs){
            coins -= x;
            if (coins < 0){
                // cout << x;
                break;
            }
            count++;
        }

        return count;
    }
};