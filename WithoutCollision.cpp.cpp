#include <iostream>
#include <vector>

// Number of buckets in the hash table
const int N = 11;

// Hash function
uint64_t hash(uint64_t hash_code)
{
    return hash_code % N;
}

// Hash table
std::vector<uint64_t> table(N);

// Insert a new element into the hash table
void insert(uint64_t data)
{
    // Calculate the index of the bucket where the data should be stored
    int index = hash(data);

    // If the bucket is already occupied, try the next bucket until we find an empty one
    while (table[index] != 0)
    {
        index = (index + 1) % N;
    }

    // Insert the data into the bucket at the calculated index
    table[index] = data;
}

// Print the contents of the hash table
void print()
{
    for (int i = 0; i < N; i++)
    {
        std::cout << "Bucket " << i << ": " << table[i] << std::endl;
    }
}

int main()
{
    // Insert some values into the hash table
    insert(11);
    insert(22);
    insert(33);
    insert(44);
    insert(55);
    insert(66);
    insert(77);
    insert(88);
    insert(99);
    insert(110);
    insert(120);

    // Print the contents of the hash table
    print();

    return 0;
}