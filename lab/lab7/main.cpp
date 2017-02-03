#include <algorithm>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "valid_check.hpp"

int min(int a,int b)
{
    return a>b?b:a;
}

void print_menu();
void do_user_choice(int choice);
void linear_search(int val, const std::string in_file);
void binary_search(int val, const std::string in_file);                     //should be sortted
void merge_sort(const std::string in_file, const std::string out_file);



int main()
{
    int choice = -1;
    while (true)
    {

        print_menu();
        while (choice < 1 || choice > 4)
        {
            std::cout << "Choice: ";
            choice = valid_check::is_valid_int();
        }

        do_user_choice(choice);

        choice = -1;
    }
                    
    return 1;
}

void print_menu()
{
    std::cout <<"1) Search for target value\n"<<"2) Binary Search\n"<<"3) Merge Sort\n" <<"4) Exit\n\n"; 
}

void do_user_choice(int choice)
{
    switch (choice)
    {
        case 1:
            {
                std::cout << "Which input file should be used?\n";
                std::string filename;
                std::getline(std::cin, filename);

                std::cout << "Linear search for which integer?\n";
                int value = valid_check::is_valid_int();


                linear_search(value, filename);            
            }
            break;
        case 2:
            {
                std::cout << "Which sorted input file should be used?\n";
                std::string filename;
                std::getline(std::cin, filename);


                std::cout << "Binary search for which integer?\n";
                int value = valid_check::is_valid_int();


                binary_search(value, filename);
            }
            break;
        case 3:
            {
                std::cout << "Which input file should be used?\n";
                std::string in_file;
                std::getline(std::cin, in_file);

                std::cout << "Which output file should be used?\n";
                std::string out_file;
                std::getline(std::cin, out_file);


                std::cout << "Merge Sort (Ascending)\n";
                merge_sort(in_file, out_file);
            }
            break;
        default:
            exit(0);
    }
}

void linear_search(int value, const std::string in_file)
{
    std::cout << "Linear Search for " << value << " in \'" << in_file << 
                 "\'...\n";

    std::ifstream in;
    valid_check::open_in_file(in, in_file);        // open file

    std::vector<int> list;

    int cur;
    while (in >> cur)
        list.push_back(cur);

    std::cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        std::cout << list[i] << ' ';
    std::cout << '\n';

    // algorithm
    bool found = false;
    for (int i = 0; i < num_vals; ++i)
        if (list[i] == value)
        {
            std::cout << "Found " << value << " at index: [" << i<<"]" << '\n';
            found = true;
        }

    if (found == false)
        std::cout << "Did not find " << value << " in the file.\n";

    in.close();
}


void binary_search(int value, const std::string in_file)
{
    std::cout << "Binary Search for " << value << " in \'" << in_file << 
                 "\'...\n";

    std::ifstream in;
    valid_check::open_in_file(in, in_file);       // open file 

    std::vector<int> list;

    int cur;
    while (in >> cur)
        list.push_back(cur);

    std::cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        std::cout << list[i] << ' ';
    std::cout << '\n';

    int begin = 0;
    int end = num_vals;
    int middle = 0;
    bool found = false;
    int pos = -1;


    while (!found && begin <= end)
    {
        middle = (begin + end) / 2;
        if (list[middle] == value)
        {
            found = true;
            pos = middle;
        }
        else if (list[middle] > value)
            end = middle - 1;
        else
            begin = middle + 1;
    }

    if (pos == -1)
        std::cout << "Did not find value " << value << " in the file.\n";
    else
        std::cout << "Found " << value << " at index [" << pos<<"] " << '\n';

    in.close();
}


void merge_sort(const std::string in_file, const std::string out_file) {
   
    std::ifstream in;
    valid_check::open_in_file(in, in_file);         //open file

    std::vector<int> list;

    int cur;
    while (in >> cur)
        list.push_back(cur);

    int len = list.size();
    int *arr=(int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i)
        arr[i]=list[i];

    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start;
            int mid = min(start + seg, len);
            int high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);


    for (int i = 0; i < len; ++i)
        list[i]=arr[i];

    std::ofstream out;
    valid_check::open_out_file(out, out_file);

    
    std::cout << "Sorted contents: ";
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i] << ' ';
        out << list[i] << ' ';
    }
    std::cout << '\n';
    out.close(); 


}
