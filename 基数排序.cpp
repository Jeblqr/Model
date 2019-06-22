#include<bits/stdc++.h>
using namespace std;


//------------------------------------------
namespace RadixSort
{
    vector<int> sort(vector<int> dat,int radix=1<<8)
    {
        vector<int> tmp;
        vector<int> cnt;
        tmp.resize(dat.size());
        int p=1,c=4;
        for (int d=0;d!=c;d++)
        {
            cnt.clear();
            cnt.resize(radix);
            for (int i=0;i!=dat.size();i++)
            {
                int k=(dat[i]/p)%radix;
                cnt[k]++;
            }
            for (int i=1;i!=radix;i++)
                cnt[i]+=cnt[i-1];
            for (int i=dat.size()-1;i>=0;i--)
            {
                int k=(dat[i]/p)%radix;
                tmp[--cnt[k]]=dat[i];
            }
            dat=tmp;
            p*=radix;
        }
        return dat;
    }
}
//------------------------------------------


int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for (int i=1,a;i<=n;i++)
        cin>>a,vec.push_back(a);
    vec=RadixSort::sort(vec);
    for (auto i:vec)
        cout<<i<<' ';
    return 0;
}
