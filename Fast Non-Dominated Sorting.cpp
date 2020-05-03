#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

int n, m;

bool dominates(vector<double> sol_1, vector<double> sol_2) {
    int f = 0;
    for(int i=0;i<m;i++) {
        if(sol_1[i]<sol_2[i])
            f = 1;
        if(sol_1[i]>sol_2[i])
            return 0;
    }
    if(f)
        return 1;
    return 0;
}

int main() {
    auto start = high_resolution_clock::now(); 
    ifstream fi;
    fi.open("data_100_2_1.txt");
    ofstream fo;
    fo.open("output-FNS.txt");
    fi>>n>>m;
    vector<vector<double> > P(n, vector<double>(m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            fi>>P[i][j];
        }
    }
    
    vector<int> S[n];
    vector<vector<int> > Fronts;
    int n_sol[n], sol_rank[n];

    for(int i=0;i<n;i++) {
        n_sol[i] = 0;
        for(int j=0;j<n;j++) {
            if(dominates(P[i], P[j])) {
                S[i].push_back(j);
            } else if(dominates(P[j], P[i])) {
                n_sol[i]++;
            }
        }
        if(n_sol[i]==0) {
            sol_rank[i] = 1;
            if(Fronts.size()==0) {
                Fronts.push_back({i});
            } else {
                Fronts[0].push_back(i);
            }
        }
    }
    int front_count = 0;
    while(Fronts[front_count].size()!=0) {
        vector<int> curr_Front;
        for(auto sol:Fronts[front_count]) {
            for(auto sol_d : S[sol]) {
                n_sol[sol_d]--;
                if(n_sol[sol_d]==0) {
                    sol_rank[sol_d] = front_count+1;
                    curr_Front.push_back(sol_d);
                }
            }
        }
        front_count++;
        Fronts.push_back(curr_Front);
    }

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    for(int i=0;i<front_count;i++) {
        fo<<"Front "<<i+1<<":\n";
        for(int j=0;j<Fronts[i].size();j++) {
            fo<<Fronts[i][j]<<" ";
        }
        fo<<"\n\n";
    }
    return 0;
}
