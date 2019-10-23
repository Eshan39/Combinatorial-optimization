#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
bool flag=false;

int parent[100];

int find(int x)
{
    if(parent[x]==x){
        return x;
    }
    return find(parent[x]);
}

void mergeTwo(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    parent[fx]=fy;
}

int main()
{
    for(int i=0;i<100;i++){
        parent[i]=i;
    }
    int n,m,q;
    int u,v,w;
    int to,from;
    vector<pair<int,pair<int,int> > > edge;

    while(cin>>n>>m){

        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>w;
            edge.push_back(make_pair(w,make_pair(u,v)));
        }
        cout<<endl;
        int mst_weight=0,mst_edge=0;
        int mst_ni=0;

        sort(edge.begin(),edge.end());
        int p=edge.size();

        for(int i=0;i<p;i++)
        {
            u=edge[mst_ni].second.first;
            v=edge[mst_ni].second.second;
            w=edge[mst_ni].first;


            if(find(u)!=find(v))
            {
                mergeTwo(u,v);
                mst_weight+=w;

                mst_edge++;
            }
            else if(find(u)==find(v))
            {
                mergeTwo(u,v);
                flag=true;
                mst_edge++;
            }

            mst_ni++;

        }
        if(flag==false) cout<<"No second way"<<endl;
        else cout<<mst_weight<<endl;
       // for(int i=0;i<q;i++)
        //{
          //  cin>>from>>to;
            //if(find(from)!=find(to)) {
              //  mergeTwo(from,to);
                //cout<<"no path"<<endl;
            //}

        //}
      //  cout<<mst_weight<<endl;

    }

    return 0;
}

