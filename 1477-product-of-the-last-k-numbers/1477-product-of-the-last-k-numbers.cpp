class ProductOfNumbers {
private:
    vector<int> prefixProduct;
    int size = 0;

public:
    ProductOfNumbers() {
        prefixProduct.push_back(1);
        size = 0;
    }
    void add(int num) {
        if (num == 0) {
            prefixProduct = {1};
            size = 0;
        } else {
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
        cout<<size<<endl;
        if (k > size) return 0;
        cout<<prefixProduct[size] << " " << prefixProduct[size - k] <<endl;
        return prefixProduct[size] / prefixProduct[size - k];
        
    }
};