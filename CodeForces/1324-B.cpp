#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(vector<int> &temp,int n)
{
    int i=0,j=n-1;

    while(i<n && i < j)
    {
        if(temp[i] == temp[j] && i+1 != j)
        {
         //   cout<<"Temp i & j" <<temp[i]<<"  "<<temp[j]<<" i "<<i<<" j "<<j<<endl;
            return true;
        }

        j--;
        if(j == i)
        {
            j = n-1;
            i++;
        }
    }

    return false;
}

int main()
{
    int tc; // Number of test cases
    cin >> tc;

    for(int i=0 ;i<tc;i++)
    {
        int n; cin>>n;
        vector<int> arr(n,0);

        for(int i = 0 ;i<n;i++)
        {
            cin>>arr[i];
        }


        if(isPalindrome(arr,n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
