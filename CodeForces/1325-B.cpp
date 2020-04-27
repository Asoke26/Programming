#include<iostream>
#include<set>

using namespace std;

//int LIS(vector<int> &temp)
//{
//    int count = 0;
//
//    return false;
//}

int main()
{
    int tc; // Number of test cases
    cin >> tc;

    for(int i=0 ;i<tc;i++)
    {
        int n,t; cin>>n;
        set<int> arr;

        for(int i = 0 ;i<n;i++)
        {
            cin>>t;
            arr.insert(t);
        }


        cout<<arr.size()<<endl;
    }

    return 0;
}
