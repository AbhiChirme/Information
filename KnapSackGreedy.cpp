#include<bits/stdc++.h>

using namespace std;

struct Item {
	int value;
	int weight;
};


double fractionalKnapsack(Item arr[] , int n , int W){
	
	vector<pair<double, int>> v;
	for(int i=0 ; i<n ; i++){
		double x = (arr[i].value*1.0)/(arr[i].weight*1.0);
		v.push_back({x,i});
	}
	sort(v.begin(), v.end(), greater<pair<double,int>>());
	int s=0;
	int ans = 0;
	for(int i=0 ; i<v.size() ; i++){
		if(s + arr[v[i].second].weight<=W){
			ans += arr[v[i].second].value;
			s += arr[v[i].second].weight;
		}
		else{
			double x = (W-s)*1.0;
			ans += x*v[i].first;
			break;
		}
	}
	return ans;
}

int main(){
	int n;
	cout<<"No of items: ";
	cin>>n;
	Item arr[n];
	for(int i=0 ; i<n ; i++){
		cout<< "Product" << i+1<<endl;
		cout<< "Value: ";
		cin>> arr[i].value;
		cout<< "Weight: ";
		cin>> arr[i].weight;
	}
	
	int W;
	cout<<"Enter the max Weight:";
	cin>>W;
	double ans = fractionalKnapsack(arr, n , W);
	cout<<"The profit is : "<<ans;
	return 0;
}