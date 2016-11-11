void selectTopK(int *array, int size, int topK) {
    if (size < topK) {
        return ;
    }
    int key = array[size-1];
    int greaterNumber = 0;
    for (size_t i = 0; i < size -1; i++) {
        if (array[i] > key) {
            std::swap(array[i], array[greaterNumber]);
            greaterNumber++;
        }
    }
    std::swap(array[greaterNumber], array[size - 1]);
    if (greaterNumber + 1 == topK && greaterNumber == topK) {
        return ;
    }
    if (topK < greaterNumber) {
        selectTopK(array, greaterNumber, topK);
        return ;
    }
    assert(topK > greaterNumber + 1);
    selectTopK(array+greaterNumber+1, size-(greaterNumber+1), topK - greaterNumber);
}

