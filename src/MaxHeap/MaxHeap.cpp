#include <iostream>

class MaxHeap {
public:
    /**
     * Creates a MaxHeap
     * @param a array that's passed in to be created
     * @param s size of the array
     */
    MaxHeap(int* a, int s){
        this->size = s;
        this->heap_size = s;
        this->array = a;
        Build_Max_Heap();
    }

    ~MaxHeap()= default;

    /**
     * Turns the heap into an array string
     * @return a string representing the heap
     */
    std::string toString(){
        return heap_to_String(this);
    }

    /**
     * The size of the heap
     * @return an integer representing the size of the heap
     */
    int getSize(){
        return this->size;
    }

    /**
     * Gets the heap size
     * @return the size of the heap
     */
    int getHeap_Size(){
        return this->heap_size;
    }



    /**
     * Sets the size of the array
     * @param s the new size of the array
     */
    void setSize(int s){
        this->size = s;
    }

    /**
     * Sets the size of the heap
     * @param s the new size of the heap
     */
    void setHeap_Size(int s){
        this->heap_size = s;
    }

    /**
     * Runs heap sort on the internal array
     * returning an array in ascending order
     */
    void Heapsort(){
        Build_Max_Heap();
        for(int i = this->size-1; i > 0; i--){
            swap(this, 0, i);
            this->heap_size--;
            Max_Heapify(0);
        }
    }

    /**
     * Builds a Max Heap out of the internal array
     */
    void Build_Max_Heap(){
        this->heap_size = this->size;
        for(int i = this->size >> 1; i > -1; i--){
            Max_Heapify(i);
        }
    }

    /**
     * Performs Max Heapify starting at the index i
     * @param i the index to start performing max heapify at
     */
    void Max_Heapify(int i){
        int l = left(i);
        int r = right(i);
        int largest;
        if(l <= this->heap_size-1 && getArrayValue(l) > getArrayValue(i)){
            largest = l;
        } else {
            largest = i;
        }

        if(r <= this->heap_size-1 && getArrayValue(r) > getArrayValue(largest)){
            largest = r;
        }

        if (largest != i){
            swap(this, i, largest);
            Max_Heapify(largest);
        }

    }

    /**
     * inserts a value into the max heap
     * @param i the value to be inserted
     */
    void insert(int i){
        this->array[size] = i;
        this->size++;
        Build_Max_Heap();
    }

    /**
     * Remove the value at index i
     * @param i index the where value will be removed
     * @return true if value was removed, false otherwise
     */
    bool remove(int i){
        if (i < 0 && i > this->size) return false;
        int temp = i;
        while(i < this->size){
            if (this -> array[left(i)] >= this -> array[right(i)]){
                this -> array[i] = this -> array[left(i)];
                i = left(i);
            } else {
                this -> array[i] = this -> array[right(i)];
                i = right(i);
            }
        }
        this->size--;
        return true;
    }

    /**
     * Removes and returns the value at the root
     * @return the value at root
     */
    int retrieveAndRemoveRoot(){
        int i = this->array[0];
        remove(0);
        return i;
    }

    /**
     * Finds a value within the heap and returns its index
     * @param i the value to find
     * @return the index of the value
     */
    int find(int i){
        int temp = 0;

        while (getArrayValue(temp) != i && temp < this->size){
            temp++;
        }

        if(temp==this->size) return -1;
        else return temp;
    }

private:
    int size;
    int heap_size;
    int* array;

    static void swap(MaxHeap* m, int index1, int index2){
        int t = m->array[index1];
        m->array[index1] = m->array[index2];
        m->array[index2] = t;
    }

    static int left(int i){
        return 2*i+1;
    }

    static int right(int i){
        return 2*(i+1);
    }

    static std::string heap_to_String(MaxHeap* h){
        std::string s;
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

    /**
     * Gets the internal array of the datastructure
     * @return the internal integer array
     */
    int* getArray(){
        return this->array;
    }

    /**
     * Gets a specific value from the array
     * @param i the index value to get from
     * @return the value
     */
    int getArrayValue(int i){
        return getArray()[i];
    }

    /**
     * Sets the array
     * @param s the new array
     */
    void setArray(int* s){
        this->array = s;
    }
};


int main() {
    int A[] = {58, 72, 19, 41, 33, 62, 84};

    auto* heap = new MaxHeap(A, 7);

    heap->Heapsort();

    std::cout << heap->toString();

    return 0;
}




