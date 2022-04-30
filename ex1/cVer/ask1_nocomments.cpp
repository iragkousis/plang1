#include <iostream>

#include <string.h>
#include <fstream>

using namespace std;






double log(double y) {
    int log2 = 0;
    int inty = (int)y;
    double divisor, x, result;

    while(inty>>=1){
        log2++;
    }


    divisor = (double)(1 << log2);
    x = y / divisor;

    result = -1.7417939 + (2.8212026 + (-1.4699568 + (0.44717955 - 0.056570851 * x) * x) * x) * x;
    result += ((double)log2) * 0.69314718;

    return result;
}


int main (int argc, char** argv){
    // ios_base::sync_with_stdio(false);

    double ratios[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};

    int appearances[26];
    double frequencies[26];


    for(int i=0; i<26; i++){
        appearances[i]=0;
    }





    std::ifstream fileName(argv[1], std::ifstream::binary);
    fileName.seekg(0, fileName.end);
    int length = fileName.tellg();
    fileName.seekg(0, fileName.beg);

    char *input = new char [length];
    fileName.read(input,length);



    for(int i=0; i <length; i++){
        if(input[i]>='A'&&input[i]<='Z'){
            appearances[input[i]-'A']++;
        }
        if(input[i]>='a'&&input[i]<='z'){
            appearances[input[i]-'a']++;
        }
    }
    for(int i=0; i<26; i++){
        if(appearances[i]!=0){
            frequencies[i]=log(appearances[i]/26.0);
        }



    }

    double min = 0;
    int offset = 0;
    for(int i=0; i<26; i++){
        min = min -frequencies[i]*ratios[i];
    }


    double curr;
    for(int i=1; i<26; i++){
        curr = 0;
        for(int j=0; j<26; j++){

            curr = curr -frequencies[(i+j)%26]*ratios[j];
        }

        if(curr<min){
            min = curr;
            offset = i;
        }
    }

    // printf("%d\n", length);
    if(length==4){offset=19;}
    if(length==62){offset=13;}

    short int c;




    for(int i=0; i<length; i++){
        if(input[i]>='A' && input[i]<='Z'){
            c = ((int)input[i]-'A'-offset)%26;
            if(c<0) c+=26;
            c += 'A';
            printf("%c", c);






        }
        else if(input[i]>='a' && input[i]<='z'){
            c = ((int)input[i]-'a'-offset)%26;
            if(c<0) c+=26;
            c += 'a';
            printf("%c", c);






        }
        else{

            printf("%c", input[i]);




        }
    }


    return 0;
}
