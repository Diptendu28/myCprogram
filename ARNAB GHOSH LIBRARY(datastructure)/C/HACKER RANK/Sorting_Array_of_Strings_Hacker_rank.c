#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"printIO.h"
// -----------------------------------------------------------------------------------------
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(b,a);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a,b);
}

#define ALPHA 26
int distinct_chars(const char *ch){
    int i = 0, dist_chars = 0, chars[ALPHA] = {0};
    while (*ch) {
        int temp = (*ch++) - 'a';
        if (temp < ALPHA)
            chars[temp]++;
    }
    while(i<ALPHA){
        if (chars[i++])
            dist_chars++;
    }
    return dist_chars;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    return (distinct_chars(b) - distinct_chars(a)) ? (distinct_chars(b) - distinct_chars(a)) : lexicographic_sort(a, b);    
}

int sort_by_length(const char* a, const char* b) {
    return (strlen(b) - strlen(a)) ? (strlen(b) - strlen(a)) : lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i, j;
    char *key;
    for(i = 1; i < len; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && cmp_func(key, arr[j]) > 0){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

// -----------------------------------------------------------------------------------------
int main() 
{   
    OpenIO(fopen("Sorting_Array_of_Strings_Hacker_rank.c", "a"));
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

}

/*

fekls
qoi
sbv
wkue

wkue
sbv
qoi
fekls

qoi
sbv
wkue
fekls

qoi
sbv
wkue
fekls

--------------------------------------
int x = strcmp(a, b);
x = 0 -> if both are same
x = -ve -> correct dictionary order
x = +ve -> reverse dictionary order


cmp_func                                -- cmp_func
     *cmp_func                                --   is a pointer to
    (*cmp_func)(                            ) --   a function taking
    (*cmp_func)(            a               ) --     parameter a
    (*cmp_func)(          * a               ) --       is a pointer to
    (*cmp_func)(const char* a               ) --       const char
    (*cmp_func)(const char* a,             b) --     parameter b
    (*cmp_func)(const char* a,           * b) --       is a pointer to
    (*cmp_func)(const char* a, const char* b) --       const char
int (*cmp_func)(const char* a, const char* b) --   returning int

https://www.geeksforgeeks.org/sort-an-array-of-strings-based-on-count-of-distinct-characters/
https://stackoverflow.com/questions/62761242/parameter-passing-in-functions-in-c-language

char *strchr(const char *str, int c)
This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.
str − This is the C string to be scanned.
c − This is the character to be searched in str.
----
number of distinct character---using inbuilt function
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int counta_dist = 0, countb_dist = 0;
    while(*a){
         if (!strchr(a + 1, *a))
            counta_dist++;
        a++;
    }
    while(*b){
         if (!strchr(b + 1, *b))
            countb_dist++;
        b++;
    }
    
}
-----

amdfssbm
bjp
kbi
mexnxxtyi
mfbty
mfkvus
nn
ofcq
rmdlyiw
sajoefukc
zejl

zejl
sajoefukc
rmdlyiw
ofcq
nn
mfkvus
mfbty
mexnxxtyi
kbi
bjp
amdfssbm

nn
bjp
kbi
ofcq
zejl
mfbty
mfkvus
rmdlyiw
amdfssbm
mexnxxtyi
sajoefukc

nn
bjp
kbi
ofcq
zejl
mfbty
amdfssbm
mfkvus
mexnxxtyi
rmdlyiw
sajoefukc

*/
/*
in 1
------
11
nn
amdfssbm
mfbty
bjp
sajoefukc
zejl
ofcq
mexnxxtyi
kbi
rmdlyiw
mfkvus
in 2
-------
40
bkmjbd
aoxy
l
kdiacuhap
bkctw
uzcj
fmog
nglz
y
kagghgv
hhibezx
dioj
dryqxjrc
vohe
rmsxuahx
gwlmfav
foaxllp
vmeeszxf
wztd
zmwlydn
fsjhpw
gmqv
u
psskqteutd
qqgtdbb
mi
idxutu
q
dkcoa
swrxcjqkd
lgtxokiu
cpcp
msroguma
gyvpofsjt
espoa
ydaauimo
cxvrxo
vjmlqhxlhd
y
e

*/
/*

out 40
-------
aoxy
bkctw
bkmjbd
cpcp
cxvrxo
dioj
dkcoa
dryqxjrc
e
espoa
fmog
foaxllp
fsjhpw
gmqv
gwlmfav
gyvpofsjt
hhibezx
idxutu
kagghgv
kdiacuhap
l
lgtxokiu
mi
msroguma
nglz
psskqteutd
q
qqgtdbb
rmsxuahx
swrxcjqkd
u
uzcj
vjmlqhxlhd
vmeeszxf
vohe
wztd
y
y
ydaauimo
zmwlydn

zmwlydn
ydaauimo
y
y
wztd
vohe
vmeeszxf
vjmlqhxlhd
uzcj
u
swrxcjqkd
rmsxuahx
qqgtdbb
q
psskqteutd
nglz
msroguma
mi
lgtxokiu
l
kdiacuhap
kagghgv
idxutu
hhibezx
gyvpofsjt
gwlmfav
gmqv
fsjhpw
foaxllp
fmog
espoa
e
dryqxjrc
dkcoa
dioj
cxvrxo
cpcp
bkmjbd
bkctw
aoxy

e
l
q
u
y
y
mi
aoxy
cpcp
dioj
fmog
gmqv
nglz
uzcj
vohe
wztd
bkctw
dkcoa
espoa
bkmjbd
cxvrxo
fsjhpw
idxutu
foaxllp
gwlmfav
hhibezx
kagghgv
qqgtdbb
zmwlydn
dryqxjrc
lgtxokiu
msroguma
rmsxuahx
vmeeszxf
ydaauimo
gyvpofsjt
kdiacuhap
swrxcjqkd
psskqteutd
vjmlqhxlhd

e
l
q
u
y
y
cpcp
mi
aoxy
dioj
fmog
gmqv
nglz
uzcj
vohe
wztd
bkctw
bkmjbd
cxvrxo
dkcoa
espoa
idxutu
kagghgv
qqgtdbb
foaxllp
fsjhpw
hhibezx
dryqxjrc
gwlmfav
msroguma
rmsxuahx
vmeeszxf
ydaauimo
zmwlydn
kdiacuhap
lgtxokiu
psskqteutd
vjmlqhxlhd
gyvpofsjt
swrxcjqkd


*/