/**
 * Write a program that will take a list of integers from the user via the console and 
 * calculate a histogramof the numbers entered. Assume that the size of the array will 
 * be entered by the user first, followed by a list ofnon-negative integers. A histogram
 * is a representation of the distribution of data based on which bin they fall into.
 * A bin is a range of numbers determined based on data. For this problem, assume that 
 * bins are of size 10 (i.e. bin 1= 0...9, bin 2 = 10...19, etc). Output the histogram 
 * to the console as a list of bins and number of values that fallinto each one. 
 * Use array to store the user input and create functions as needed to create a modular 
 * design. Test your code with multiple inputs to ensure robustness.
 */

#include <iostream>

using namespace std; 

void getInput(int arr[], int size){
    cout << "Enter " << size << " non-negative integers: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
}

void compute(int arr[], int size, int bins[], int numBins){
    for (int i = 0; i < numBins; i++){
        bins[i] = 0;
    }

    for (int i = 0; i < size; i++){
        int binIndex = arr[i] / 10;
        if (binIndex >= numBins){
            binIndex = numBins -1; 
            bins[binIndex]++;
        }
    }
}

void print(int bins[], int numBins){
    cout << "Histogram:" << endl;
    for (int i = 0; i < numBins; i++){
        cout << "Bin " << i + 1 << " (" << i*10 << " - " << (i+1)*10 - 1 << "): " << bins[i] << endl;
    }
}
int main(){
    int size;
    cout << "Enter the number of integers: ";
    cin >> size;
 
    while (size <= 0) {
        cout << "Size must be positive. Enter again: ";
        cin >> size;
    }
 
    int arr[size];
    getInput(arr, size);
 
    const int NUM_BINS = 10;
    int bins[NUM_BINS];
    compute(arr, size, bins, NUM_BINS);
    print(bins, NUM_BINS);

    return 0;

}