#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree{
private: vi st, A;
    int n;
    int left (int p) {return p<<1;}
    int right (int p) {return (p<<1) + 1;}

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = L;
        } else {
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) {return -1;} // Current segment tree out of query range.
        if (L >= i && R <= j) {return st[p];}
        // compute the min position in the left and right part of the interval.
        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);
        if (p1 == -1) {return p2;}
        if (p2 == -1) {return p1;}
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    int update(int p, int L, int R, int idx, int new_value) {
        int i = idx, j = idx;
        if (i > R || j < L) {return st[p];}
        if (L == i && R == j) {
            A[i] = new_value;
            return st[p] = L;
        }
        int p1, p2;
        p1 = update(left(p), L, (L+R)/2, idx, new_value);
        p2 = update(right(p), (L+R)/2 + 1, R, idx, new_value);

        return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }

public: 
    SegmentTree(const vi &_A) : A(_A), n((int)A.size()), st(4*n) {
        build(1, 0, n-1);
    }
    int rmq(int i, int j) {
        return rmq(1, 0, n-1, i, j);
    }
    int update(int i, int v) {
        return update(1, 0, n-1, i, v);
    }
};

int main() {
    int arr[] = {18, 17, 13, 19, 15, 11, 20};

    vi A(arr, arr+7);

    SegmentTree st(A);

    printf("RMQ(1,3) = %d\n", st.rmq(1,3));
    printf("RMQ(4,6) = %d\n", st.rmq(4,6));
    // Update A[5] to 99;
    st.update(5,99);
    printf("RMQ(1,3) = %d\n", st.rmq(1,3));
    printf("RMQ(4,6) = %d\n", st.rmq(4,6));
}