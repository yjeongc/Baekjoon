#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Member {
    int age;
    char name[101];
};

void BubbleSort(struct Member arr[], int n){
    int i, j;
    struct Member temp;

    for (i = 0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if (arr[j].age > arr[j+1].age || (arr[j].age == arr[j+1].age && strcmp(arr[j].name, arr[j+1].name) > 0)){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    struct Member *members = (struct Member *)malloc(sizeof(struct Member)*N);
    for (int i=0; i<N; i++)
    {
        scanf("%d %s", &members[i].age, members[i].name);
    }

    BubbleSort(members, N);

    for (int i=0; i<N; i++)
    {
        printf("%d %s\n", members[i].age, members[i].name);
    }

    free(members);

    return 0;
}