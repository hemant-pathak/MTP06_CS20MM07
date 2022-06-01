// C++ program to compute sum of pairwise bit differences  row wise

#include <bits/stdc++.h>
using namespace std;

int sumBitDifferences(int arr[], int n)
{
	int ans = 0; // Initialize result

	// traverse over all bits
	for (int i = 0; i < 32; i++) {
		// count number of elements with i'th bit set
		int count = 0;
		for (int j = 0; j < n; j++)
			if ((arr[j] & (1 << i)))
				count++;

		// Add "count * (n - count) * 2" to the answer
		ans += (count * (n - count) * 2);
	}

	return ans;
}

// Driver program
int main()
{
	vector<vector<int> > vec{{1,1,1},{4,5,6},{7,8,9}};// vector 1 3x3
	vector<vector<int> > rec{{1,1,4},{5,1,8},{3,1,9}};// vector 2 3x3
	
	// transposing vector 2 for easy calculation
	for(int i=0;i<rec.size();i++){
	    for(int j=i+1;j<rec[i].size();j++){
	        swap(rec[i][j],rec[j][i]);
	    }
	}
	
	vector<int> row;  //count pairwise bit toggle for vector 1
	vector<int> col;  //count pairwise bit toggle for vector 2
	
	for(int i=0;i<vec.size();i++){
	    int n=vec[i].size();
	    int arr[n];
	    for(int j=0;j<n;j++){
	        arr[j]=vec[i][j];
	    }
	    int m=sumBitDifferences(arr, n);
	    row.push_back(m);
	}
	
	for(int i=0;i<rec.size();i++){
	    int n=rec[i].size();
	    int arr[n];
	    for(int j=0;j<n;j++){
	        arr[j]=rec[i][j];
	    }
	    int m=sumBitDifferences(arr, n);
	    col.push_back(m);
	}
	
	for(int i=0;i<row.size();i++){    //—>give toggle value of first matrix
	    cout<<row[i]<<" ";
	}
	row.clear();
	cout<<endl;
	for(int i=0;i<col.size();i++){      // —>give toggle value of second matrix

	    cout<<col[i]<<" ";
	}
	col.clear();
	return 0;
}
