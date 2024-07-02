class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {

    int n=arr.size();
    stack<int> s; 
    vector<int> right(n);
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            right[i] = n;
        } else {
            right[i] = s.top();
        }
        s.push(i);
    }

    stack<int> st; 
    vector<int> left(n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = -1;
        } else {
            left[i] = st.top();
        }
        st.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans, (right[i]-left[i]-1)*arr[i] );
    }
     return ans;
    }
};