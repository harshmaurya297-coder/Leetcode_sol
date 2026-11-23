class ProductOfNumbers {
private:
    vector<int> product;
public:  
    ProductOfNumbers() {
        product.push_back(1);
    }
    
    void add(int num) {
        if(num != 0){
            product.push_back(num*product.back());
        }
        else{
            product.clear();
            product.push_back(1);
        }
    }
    
    int getProduct(int k) {
        if (k >= (int)product.size()) return 0;
        return product.back() / product[product.size() - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */