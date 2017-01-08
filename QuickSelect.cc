#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<iostream>

using namespace std;

class QuickSelect
{
    public:
            QuickSelect(vector<int> aInArray)
            {
                    array = aInArray;
            }

            virtual ~QuickSelect(){}
            vector<int> getArray()
            {
                return array;
            }
            int findKthLargest(vector<int> aInArray, int kth);
            int findKthSmallest(vector<int> aInArray, int kth);

    private:

            vector<int> array;
};

int QuickSelect::findKthLargest(vector<int> aInArray, int kth)
{
    vector<int> lSmallArray, lLargerArray;

    int lMedian = aInArray.size()/2;

    for(int i=0;i<aInArray.size();i++) {
        if(aInArray[i] < aInArray[lMedian]) {
            lSmallArray.push_back(aInArray[i]);
        } else if(i == lMedian) {
            continue;
        } else {
            lLargerArray.push_back(aInArray[i]);
        }
    }

    if(lSmallArray.size() >= kth) {
        return findKthLargest(lSmallArray, kth);
    } else if((aInArray.size() - lLargerArray.size()) < kth) {
        return findKthLargest(lLargerArray, kth- lSmallArray.size()+1);//(aInArray.size() - lLargerArray.size()));
    } else {
        return array[lMedian];
    }
}

int QuickSelect::findKthSmallest(vector<int> aInArray, int kth)
{
    return 0;
}

int main()
{
    vector<int> v;
    int array[] = {1,8,11,34,56,89,2,3,6,7};

    for(int i =0;i<sizeof(array)/sizeof(int); i++) {
        v.push_back(array[i]);
    }

    QuickSelect q(v);

    int ret = q.findKthLargest(q.getArray(), 4);
    cout<<ret<<endl;


}

