class NumArray {
public:
    vector<int> segment, arr;
    int n;

    NumArray(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        segment.resize(4 * n, 0);
        if (n > 0)
            build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int idx, int left, int right) {
        if (left == right) {
            segment[idx] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        build(nums, 2 * idx + 1, left, mid);
        build(nums, 2 * idx + 2, mid + 1, right);

        segment[idx] = segment[2 * idx + 1] + segment[2 * idx + 2];
    }

    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        updateTree(0, 0, n - 1, index, diff);
    }

    void updateTree(int idx, int left, int right, int pos, int diff) {
        if (left > pos || right < pos)
            return;

        segment[idx] += diff;

        if (left != right) {
            int mid = (left + right) / 2;
            updateTree(2 * idx + 1, left, mid, pos, diff);
            updateTree(2 * idx + 2, mid + 1, right, pos, diff);
        }
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
    int query(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right)
            return 0;
        if (ql <= left && right <= qr)
            return segment[idx];

        int mid = (left + right) / 2;
        return query(2 * idx + 1, left, mid, ql, qr) +
               query(2 * idx + 2, mid + 1, right, ql, qr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */