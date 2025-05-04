#include "geneBank.h"

GENE_BANK::GENE_BANK()
{
    fileSize = 0;
    entryByte = sizeof(Sample);
}

GENE_BANK::~GENE_BANK() {}

void GENE_BANK::sort(Sample array[], int fileSize)
{
    p_timSort(array, fileSize);
}

void GENE_BANK::indexSamples(Sample array[], int indexArray[])
{
    p_index(array, indexArray);
}

void GENE_BANK::displayResearcher(int speciesCode, int offset, char* filename)
{
    p_displayResearcher(speciesCode, offset, filename);
}

bool GENE_BANK::searchSample(int speciesCode, int offset, char* filename)
{
    ifstream file(filename, ios::binary);
    if (!file) return false;

    Sample temp;
    file.seekg(offset * entryByte);
    file.read(reinterpret_cast<char*>(&temp), entryByte);

    return temp.speciesCode == speciesCode && temp.sampleID != -1;
}

void GENE_BANK::updateResearcher(int speciesCode, int offset, char* newName, char* filename)
{
    p_updateResearcher(speciesCode, offset, newName, filename);
}

void GENE_BANK::deleteSample(int speciesCode, int offset, char* filename)
{
    p_deleteSample(speciesCode, offset, filename);
}

void GENE_BANK::printSampleRange(int speciesCode, int startIndex, int endIndex, char* filename)
{
    p_printRange(speciesCode, startIndex, endIndex, filename);
}

// Private functions

void GENE_BANK::p_timSort(Sample array[], int fileSize)
{
    const int RUN = 32;

    // Step 1: Sort small runs using insertion sort
    for (int i = 0; i < fileSize; i += RUN)
    {
        int end = std::min(i + RUN - 1, fileSize - 1);
        p_insertionSort(array, i, end);
    }

    // Step 2: Merge sorted runs
    for (int size = RUN; size < fileSize; size = 2 * size)
    {
        for (int left = 0; left < fileSize; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (fileSize - 1));

            if (mid < right)
                p_merge(array, left, mid, right);
        }
    }
}

void GENE_BANK::p_insertionSort(Sample array[], int beg, int end)
{
    for (int i = beg + 1; i <= end; ++i)
    {
        Sample key = array[i];
        int j = i - 1;

        // Sort by speciesCode (primary key)
        while (j >= beg && array[j].speciesCode > key.speciesCode)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void GENE_BANK::p_merge(Sample array[], int beg, int mid, int end)
{
    int leftSize = mid - beg + 1;
    int rightSize = end - mid;

    Sample* left = new Sample[leftSize];
    Sample* right = new Sample[rightSize];

    for (int i = 0; i < leftSize; ++i)
        left[i] = array[beg + i];
    for (int i = 0; i < rightSize; ++i)
        right[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = beg;

    while (i < leftSize && j < rightSize)
    {
        if (left[i].speciesCode <= right[j].speciesCode)
        {
            array[k++] = left[i++];
        }
        else
        {
            array[k++] = right[j++];
        }
    }

    while (i < leftSize)
        array[k++] = left[i++];
    while (j < rightSize)
        array[k++] = right[j++];

    delete[] left;
}

void GENE_BANK::p_index(Sample array[], int indexArray[])
{
    // Initialize index array with -1 (species not found)
    for (int i = 0; i < 5; ++i)
        indexArray[i] = -1;

    for (int i = 0; i < fileSize; ++i)
    {
        int species = array[i].speciesCode;
        if (indexArray[species] == -1)
            indexArray[species] = i; // First occurrence of each species
    }
}

void GENE_BANK::p_displayResearcher(int speciesCode, int offset, char* filename)
{
    ifstream inputFile(filename, ios::in | ios::binary);
    if (!inputFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Sample temp;
    inputFile.seekg(offset * entryByte);
    inputFile.read(reinterpret_cast<char*>(&temp), entryByte);

    if (temp.sampleID == -1)
    {
        cout << "This sample has been deleted." << endl;
    }
    else if (temp.speciesCode == speciesCode)
    {
        cout << "Researcher Name: " << temp.researcher << endl;
        cout << "Sample ID: " << temp.sampleID << endl;
        cout << "Purity Score: " << temp.purityScore << endl;
    }
    else
    {
        cout << "Species mismatch. No sample found." << endl;
    }

    inputFile.close();
}

void GENE_BANK::p_updateResearcher(int speciesCode, int offset, char* newName, char* filename)
{
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Sample temp;
    file.seekg(offset * entryByte);
    file.read(reinterpret_cast<char*>(&temp), entryByte);

    if (temp.sampleID == -1)
    {
        cout << "Sample is deleted. Cannot update." << endl;
    }
    else if (temp.speciesCode == speciesCode)
    {
        strncpy(temp.researcher, newName, sizeof(temp.researcher) - 1);
        temp.researcher[sizeof(temp.researcher) - 1] = '\0'; // Null-terminate
        file.seekp(offset * entryByte);
        file.write(reinterpret_cast<char*>(&temp), entryByte);
        cout << "Researcher name updated!" << endl;
    }
    else
    {
        cout << "Species mismatch. Update aborted." << endl;
    }

    file.close();
}

void GENE_BANK::p_deleteSample(int speciesCode, int offset, char* filename)
{
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Sample temp;
    file.seekg(offset * entryByte);
    file.read(reinterpret_cast<char*>(&temp), entryByte);

    if (temp.sampleID == -1)
    {
        cout << "Sample is already deleted." << endl;
    }
    else if (temp.speciesCode == speciesCode)
    {
        temp.sampleID = -1; // Logical deletion
        file.seekp(offset * entryByte);
        file.write(reinterpret_cast<char*>(&temp), entryByte);
        cout << "Sample marked for deletion." << endl;
    }
    else
    {
        cout << "Species mismatch. Cannot delete." << endl;
    }

    file.close();
}

void GENE_BANK::p_printRange(int speciesCode, int startIndex, int endIndex, char* filename)
{
    ifstream file(filename, ios::in | ios::binary);
    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Sample temp;
    for (int i = startIndex; i <= endIndex; ++i)
    {
        file.seekg(i * entryByte);
        file.read(reinterpret_cast<char*>(&temp), entryByte);

        if (temp.sampleID != -1 && temp.speciesCode == speciesCode)
        {
            cout << "Sample ID: " << temp.sampleID << endl;
            cout << "Researcher: " << temp.researcher << endl;
            cout << "Purity Score: " << temp.purityScore << endl;
            cout << "---------------------------" << endl;
        }
    }

    file.close();
}
