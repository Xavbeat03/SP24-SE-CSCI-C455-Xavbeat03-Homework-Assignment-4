#include <iostream>

class MaxHeap {
public:
    MaxHeap(int* a, int s){
        this->size = s;
        this->heap_size = s;
        this->array = a;
    }

    ~MaxHeap()= default;

    int getSize(){
        return this->size;
    }

    int getHeap_Size(){
        return this->heap_size;
    }

    int* getArray(){
        return this->array;
    }

    int getArrayValue(int i){
        return getArray()[i];
    }

    void setSize(int s){
        this->size = s;
    }
    void setHeap_Size(int s){
        this->heap_size = s;
    }
    void setArray(int* s){
        this->array = s;
    }


    void Heapsort(){
        Build_Max_Heap();
        for(int i = this->size; i > 1; i--){
            swap(getArrayValue(0), getArrayValue(i));
            this->heap_size--;
            Max_Heapify(0);
        }
    }

    void Build_Max_Heap(){
        this->heap_size = this->size;
        for(int i = this->size >> 1; i > 0; i--){
            Max_Heapify(i);
        }
    }

    void Max_Heapify(int i){
        int l = left(i);
        int r = right(i);
        int largest;
        if(l<=this->heap_size && getArrayValue(l) > getArrayValue(i)){
            largest = l;
        } else {
            largest = i;
        }
        if(r<=this->heap_size && getArrayValue(r) > getArrayValue(largest)){
            largest = r;
        }

        if (largest != i){
            swap(this->getArray()[i], this->getArray()[largest]);
            Max_Heapify(largest);
        }

    }

private:
    int size;
    int heap_size;
    int* array;

    static void swap(int e, int f){
        int t = e;
        e = f;
        f = t;
    }

    static int left(int i){
        return 2*i;
    }

    static int right(int i){
        return 2*i+1;
    }

    static std::string heap_to_String(MaxHeap* h){
        std::string s = "";
        s+="[";
        for(int i = 0; i < h->size; i++ ){
            s+=std::to_string(h->getArrayValue(i));
            if(i!=h->size-1){
                s+=",";
            }
        }
        s+="]\n";
        return s;
    }
};


int main() {
    int A[] = {58, 72, 19, 41, 33, 62, 84};

    auto* heap = new MaxHeap(A, 7);

    heap->Build_Max_Heap();

    return 0;
}




