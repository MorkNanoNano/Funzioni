#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>

void merge(double *arr, int low, int hight, int mid){
    int i = low; int j = mid+1; int k = low;
    double *tmp = new double[hight+1];

    while(i <= mid && j <= hight){
        if(arr[i] <= arr[j]){
            tmp[k] = std::move(arr[i]);
            i++; k++;
        }
        else {
            tmp[k] = std::move(arr[j]);
            j++; k++;
        }
    }
    while(i <= mid){
        tmp[k] = arr[i];
        i++; k++;
    }
    while(j <= hight){
        tmp[k] = std::move(arr[j]);
        j++; k++;
    }
    for(int r = low; r <= hight; r++)
        arr[r] = std::move(tmp[r]);
}

void merge_sort(double *arr, int low, int hight){
    if(low < hight){
        int mid = (low + hight)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, hight);
        merge(arr, low, hight, mid);
    }
}

void bubble_sort(double *arr, int lenght){
    for(int i = 0; i < lenght-1; i++){
        for(int j = i+1; j < lenght; j++){
            if(arr[j] <  arr[i]){
                double tmp = arr[i];
                arr[i] = arr[j];
                arr[j]= tmp;
            }
        }
    }
}

void print(double *vec, int lenght){
    for(int i = 0; i < lenght; i++)
        std::cout << vec[i] << "\n";
    std::cout << std::endl;
}

void print(std::vector<double> vec){
    for(auto value : vec)
        std::cout << value << " ";
    std::cout << std::endl;
}

int main(){

    double *data = new double[100000];
    std::ifstream infile("data.dat");

    for(int i = 0; i < 100000; i++)
        infile >> data[i];
    infile.close();

    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(data,0,100000-1);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by merge sort: " << duration.count() << " microseconds" << std::endl;


    auto first = std::chrono::high_resolution_clock::now();
    bubble_sort(data,100000);
    auto last = std::chrono::high_resolution_clock::now();

    auto time = std::chrono::duration_cast<std::chrono::microseconds>(last - first);

    std::cout << std::endl;
    std::cout << "Time taken by bubble sort: " << time.count() << " microseconds" << std::endl;

    std::vector<double> m_data;
    std::ifstream in("data.dat");

    while(!in.eof()){
        double tmp = 0;
        in >> tmp;
        m_data.push_back(tmp);
    }
    in.close();

    auto str = std::chrono::high_resolution_clock::now();
    std::sort (m_data.begin(), m_data.end());
    auto lst = std::chrono::high_resolution_clock::now();

    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(lst - str);

    std::cout << std::endl;
    std::cout << "Time taken by std::sort: " << dur.count() << " microseconds" << std::endl;

    // std::cout << "\n";
    // print(m_data);
    // std::cout << std::endl;

    std::cin.get();
}
