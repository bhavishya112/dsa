class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int remainingA = capacityA, remainingB = capacityB;
        int Alice = 0, Bob = plants.size()-1;
        int countRefill = 0;

        while (Alice<=Bob){
            
            if (Alice-Bob){
                if (remainingA < plants[Alice]){
                    remainingA = capacityA;
                    countRefill++;
                    // cout << "yes1\n";
                }
                if (remainingB < plants[Bob]){
                    remainingB = capacityB;
                    countRefill++;
                    // cout << "yes2\n";
                }
                // cout << "yes\n";
                remainingA -= plants[Alice++];
                remainingB -= plants[Bob--];
            }
            else{
                // cout << "yes\n";
                if (remainingA>=remainingB){
                    if (remainingA < plants[Alice]){
                    remainingA = capacityA;
                    countRefill++;
                    // cout << "yes1\n";
                }
                    remainingA -= plants[Alice++];
                }
                else{
                    if (remainingB < plants[Bob]){
                    remainingB = capacityB;
                    countRefill++;
                    // cout << "yes2\n";
                }
                    remainingB -= plants[Bob--];
                }
            }
        }

        return countRefill;
    }
};