class ProductOfNumbers {
public:
    vector<int> stream;
    int pro = 1;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            stream.clear();
            pro = 1;
        } else {
            pro *= num;
            stream.push_back(pro);
        }
    }

    int getProduct(int k) {
        if (stream.size() < k) return 0;
        if (stream.size() == k) return stream.back();
        return stream.back() / stream[stream.size() - k - 1];
    }
};