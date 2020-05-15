#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

int n, m;
vector<vector<int> > cnstCompMat(vector<double> w) {
    vector<pair<double, int> > a_b(n);
    for(int i=0;i<n;i++) {
        a_b[i].first = w[i];
        a_b[i].second = i;
    }
    sort(a_b.begin(), a_b.end());
    vector<vector<int> > C_w(n, vector<int> (n, 0));
    for(int j=0;j<n;j++) 
        C_w[a_b[0].second][j] = 1;
    for(int i=1;i<n;i++) { 
        if(a_b[i].first==a_b[i-1].first) {
            for(int j=0;j<n;j++)
                C_w[a_b[i].second][j] = C_w[a_b[i-1].second][j];
        } else {
            for(int j=i;j<n;j++) {
                C_w[a_b[i].second][a_b[j].second] = 1;
            }
        }
    }
    return C_w;
}

vector<vector<int> > Add_CompMat(vector<vector<int> > &D, vector<vector<int> > &C) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            D[i][j] += C[i][j];

    return D;
}

vector<vector<int> > cnstDomMat(vector<vector<double> > P) {
    vector<vector<int> > D(n, vector<int> (n, 0));
    for(int i=0;i<m;i++) {
        vector<double> w(n);
        for(int j=0;j<n;j++)
            w[j] = P[j][i];
        vector<vector<int> > C = cnstCompMat(w);
        D = Add_CompMat(D, C);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(D[i][j]==m && D[j][i]==m) {
                D[i][j] = D[j][i] = 0;
            }
        }
    }
    
    return D;
}
bool presort_comparator( const vector<double>& v1, const vector<double>& v2 ) {
    for(int i=0;i<m;i++) {
        if(v1[i]==v2[i])
            continue;
        return v1[i]<v2[i];
    }
    return true;

}
vector<int> presort(vector<vector<double> > &P) {
    sort(P.begin(),P.end(), presort_comparator);
    vector<int> sorted_indices(n, 0);
    for(int i=0;i<n;i++)
        sorted_indices[i] = (int)P[i][m];
    return sorted_indices; 
}

int find_dominance(int sol_i, int sol_j, vector<vector<int> > D) {
    if(D[sol_j][sol_i]==m) return 1;
    return 0;
}

int main() {
    auto start = high_resolution_clock::now(); 
    ifstream fi;
    fi.open("data_100_2_1.txt");
    fi>>n>>m;
    vector<vector<double> > P(n, vector<double>(m+1,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m+1;j++) {
            if(j==m) {
                P[i][j] = i;
                continue;
            }
            fi>>P[i][j];
        }
    }
    vector<vector<int> > Dom_degree_matrix = cnstDomMat(P);
    vector<vector<int> > Fronts;
    vector<int> sorted_indices = presort(P);
    int front_count = 0;
    for(int sol:sorted_indices) {
        bool isInserted = 0;
        for(int k=0;k<front_count;k++) {
            bool isDominated = 0;
            for(int sol_d:Fronts[k]) {
                if(Dom_degree_matrix[sol_d][sol]==m) {
                    isDominated = 1;
                    break;
                }
            }
            if(!isDominated) {
                Fronts[k].push_back(sol);
                isInserted = 1;
                break;
            }
        }
        if(!isInserted) {
            front_count++;
            Fronts.push_back({sol});
        } 
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    for(int i=0;i<front_count;i++) {
        cout<<"Front "<<i+1<<":\n";
        for(int j=0;j<Fronts[i].size();j++) {
            cout<<Fronts[i][j]<<" ";
        }
        cout<<"\n\n";
    }
    return 0;
}
