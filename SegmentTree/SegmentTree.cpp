#include<bits/stdc++.h>
using namespace std;

template <class T>
class SegTree
{
private:
    vector<T> tree;
    static Object sentinel = new Object();

private
    template <class T>
    void build_tree(vector<T> data, int v, int tlow, int thigh)
    {
        if (tlow == thigh)
            tree[v] = data[tlow];
        int tmid = (tlow + thigh) / 2;
        build_tree(data, v * 2 + 1, tl, tmid);
        build_tree(data, 2 * v + 2, tmid + 1, thigh);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }

public
    template <class T>
    SegTree(iterable<T> data)
    {
        for (auto it = data.begin(); it != data.end(); it++)
            tree.push_back(*it);

        build_tree(tree, 0, 0, data_list.size());
    }

    void update(int curr, int tlow, int thigh, int position, int new_val)
    {
        if (tlow == thigh)
            tree[curr] = new_val;
        int tmid = (tlow + thigh) / 2;
        if (position <= tmid)
            update(curr * 2, tlow, tmid, position, new_val);
        else
            update(curr * 2 + 1, tmid + 1, thigh, position, new_val);

        tree[curr] = tree[curr * 2] + tree[curr * 2 + 1];
    }

    template <class T>
    T sum_query(int curr, int low, int high, int queryLow, int queryHigh)
    {
        if (low > high)
            return sentinel;
        if (queryLow == low && queryHigh == high)
            return tree[curr];
        int tmid = (low + high) / 2;
        return sum_query(curr * 2 + 1, low, tmid, queryLow, min(queryHigh, tmid)) 
            + sum_query(curr * 2 + 2, tmid + 1, high, max(tmid + 1, queryLow), queryHigh)
    }

}
