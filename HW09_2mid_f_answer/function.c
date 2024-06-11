int addition(int* oned, int array_num, int* entry[], int* index_to_add, int num_ind)
{
    int i, idx;
    int sum = 0;
    for (i=0; i<num_ind; i++) {
        idx = index_to_add[i*2]*50+index_to_add[i*2+1];
        sum = sum + oned[idx] + entry[array_num][idx];
    }

    return sum;
}
