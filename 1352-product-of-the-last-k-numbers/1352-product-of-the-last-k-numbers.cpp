class ProductOfNumbers {
private:
    vector<int> product;
    int size = 0;
public:  
    ProductOfNumbers() {
        product.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if(num != 0){
            product.push_back(num*product[size]);
            size++;
        }
        else{
            product = {1};
            size = 0;
        }
    }
    
    int getProduct(int k) {
        if (k > size) return 0;
        return product[size] / product[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */