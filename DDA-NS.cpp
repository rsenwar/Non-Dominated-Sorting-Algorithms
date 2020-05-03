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
    cout<<endl;
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

vector<int> Max(vector<vector<int> > D) {
    vector<int> M;
    for(int i=0;i<n;i++) {
        int m = -1;
        for(int j=0;j<n;j++) {
            m = max(m, D[j][i]);
        }
        M.push_back(m);
    }
    return M;
}

void initialize_to_minus_one(int f, vector<vector<int> > &D) {
    for(int i=0;i<n;i++) {
        D[i][f] = -1;
        D[f][i] = -1;
    }
}

int main() {
    auto start = high_resolution_clock::now(); 
    ifstream fi;
    fi.open("data_100_2_1.txt");
    ofstream fo;
    fo.open("output-NS.txt");
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
    int count = 0;
    int k = 0;
    
    while(1) {
        vector<int> curr_Front;
        vector<int> M = Max(Dom_degree_matrix);
        for(int i=0;i<n;i++) {
            if(M[i]<m && M[i]>=0) {
                curr_Front.push_back(i);
                count++;
            }
        }
        for(int i=0;i<curr_Front.size();i++) {
            initialize_to_minus_one(curr_Front[i], Dom_degree_matrix);
        }
        Fronts.push_back(curr_Front);
        k++;
        if(count==n)
            break;
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
     cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    for(int i=0;i<k;i++) {
        fo<<"Front "<<i+1<<":\n";
        for(int j=0;j<Fronts[i].size();j++) {
            fo<<Fronts[i][j]<<" ";
        }
        fo<<"\n\n";
    }
    return 0;
}
