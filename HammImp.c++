#include"hammHdr.h"

hamm::hamm()
{
        arr1 = new int[0];
}
void hamm::find_r(int l)
{
        int i;
        for(i=0;i<20;i++){
                if(power(2,i)>l+i+1){
                        r = i;
                        break;
                }
        }
        cout<<r<<"\n";
}

int hamm::power(int n,int m)
{
        int i,res = 1;
        for(i=0;i<m;i++)
        {
                res = res * 2;
        }
        return res;
}

void hamm::getdetails()
{
        cout<<"\n"<<"ENTER THE LENGTH OF DATA :"<<"\n";
        cin>>l;
        int i;
        arr = new int[l];
        for(i=0;i<l;i++)
        {
                cin>>arr[i];
        }
}

void hamm::makearray(int l,int r,int *arr1)
{
        int i;
        sum = l + r;
        arr1 = new int[sum];
        pow_a = new int[r];
        for(i=0;i<r+1;i++)
        {
                int n = power(2,i);
                pow_a[i] = n;
        }
        int j,k=0;
        bool test;
        for(i=0;i<r;i++)
        {
                cout<<pow_a[i];
        }
        for(i=0;i<sum;i++)
        {
                test = false;
                for(j=0;j<r;j++)
                {
                        if(i==pow_a[j])
                        {
                                test = true;
                        }
                }
                if(test == true)
                {
                        arr1[i] = -1;
                }
                else{
                        arr1[i] = arr[k];
                        k++;
                }
        }
        for(i=0;i<sum;i++)
        {
                cout<<arr1[i]<<"    ";
        }
}

void hamm::getBin(int sum){
        int i,j;
        par = new int*[sum];
        for(i=0;i<sum;i++)
        {
                par[i] = new int[sum];
        }
        for(i=0;i<sum;i++)
                for(j=0;j<sum;j++)
                        par[i][j] = -1;
        for(i=0;i<sum;i++)
        {
                par[i] = dec_bin(i+1);
        }
        cout<<endl;
        for(i=0;i<sum;i++)
        {
                for(j=0;j<sum;j++)
                {
                        if(par[i][j] == 0 or par[i][j] == 1 and par[i][j] != -1)
                                cout<<par[i][j];
                }
                cout<<endl;
        }
        change(par);
}

void hamm::change(int **par)
{
        new_par = new int*[sum];
        int i,j;
        for(i=0;i<sum;i++)
        {
                new_par[i] = new int[sum];
        }
        int l=0,k;
        for(i=0;i<sum;i++)
        {
                k = sum-1;
                for(j=sum-1;j>=0;j--)
                {
                        if(par[i][j] != -1 and par[i][j] < 100 and par[i][j] >= 0){
                                new_par[l][k] = par[i][j];
                                k--;
                        }
                }
                l++;
        }
        for(i=0;i<sum;i++)
        {
                for(j=0;j<sum;j++)
                {
                        cout<<"   "<<new_par[i][j];
                }
                cout<<endl;
        }
}

int* hamm::dec_bin(int num)
{
         int i,temp[30];
         for(i=0;i<30;i++)
         {
                 temp[i] = -1;
         }
         i = 0;
         while (num > 0) {
                      //storing remainder in binary array
                      temp[i] = num % 2;
                      num = num / 2;
                      i++;
        }
        bin = new int[30];
        for(i=0;i<30;i++)
                bin[i] = -1;
        int j = 0;
        for(i=30;i>=0;i--)
        {
                if(temp[i]!=-1){
                        bin[j] = temp[i];
                        j++;
                }
        }
        return bin;
}
void hamm::getpowers(int a,int r,int *arr1)
{
        int i,j,pos,l,par_array[20][20],s=0,k=0;
        int *arr4,*pow_b;
        my_par = new int*[sum];
        for(i=0;i<sum;i++)
        {
                my_par[i] = new int[sum];
        }
        sum = a + r;
        int n = 0;
        arr4 = new int[sum];
        pow_b = new int[r];
        for(i=0;i<r+1;i++)
        {
                int n = power(2,i);
                pow_b[i] = n;
        }
        for(i=0;i<sum;i++)
        {
                for(j=0;j<sum;j++)
                {
                        my_par[i][j] = -1;
                }
        }
        bool test;
        for(i=0;i<r;i++)
        {
                cout<<pow_b[i];
        }
        for(i=0;i<sum;i++)
        {
                test = false;
                for(j=0;j<r;j++)
                {
                        if(i==pow_b[j])
                        {
                                test = true;
                        }
                }
                if(test == true)
                {
                        arr4[i] = -1;
                }
                else{
                        arr4[i] = arr[k];
                        k++;
                }
        }
        int m = 0;
        for(i=0;i<sum;i++)
        {
                if(arr4[i] == -1)
                {
                        for(k=sum-1;k>=0;k--)
                        {
                                if(new_par[i-1][k] == 1){
                                        pos = k;
                                        my_par[m] = findpos(i-1,pos);
                                        m++;
                                        cout<<endl<<pos;
                                        break;
                                }
                        }
                        //my_par[m] = findpos(pos);
                        //m++;
                }
        }
        for(i=0;i<sum;i++)
        {
                for(j=0;j<sum;j++)
                {
                        cout<<"         "<<my_par[i][j];
                }
                cout<<endl;
        }
        int temp_array[4];
        int count = 0;
        for(i=0;i<r;i++)
        {
                for(j=0;j<10;j++)
                {
                        if(arr[my_par[i][j]] == 1)
                        {
                                count = count + 1;
                        }
                }
                if((count % 2) == 0)
                {
                        temp_array[i] = 1;
                }
                else if((count % 2) != 0)
                {
                        temp_array[i] = 0;
                }
        }
        for(i=0;i<r;i++)
        {
                cout<<temp_array[i]<<endl;
        }
        j =0;
        for(i=0;i<sum;i++)
        {
                if(arr4[i] == -1)
                {
                        arr4[i] = temp_array[j];
                        j++;
                }
        }
        cout<<"\nFINAL DATA : \n:";
        for(i=0;i<sum;i++)
        {
                cout<<"    "<<arr4[i];
        }
}

int* hamm::findpos(int n,int pos)
{
        int i,j,s=0;
        int *arr4;
        arr4 = new int[sum];
        for(i=0;i<sum;i++)
        {
                arr4[i] = -1;
        }
        for(i=0;i<sum;i++)
        {
                if(arr1[i] != -1)
                {
                        for(j=sum-1;j>=0;j--)
                        {
                                if(new_par[i][j] == 1 and j == pos)
                                {
                                        arr4[s] = i;
                                        s++;
                                }
                        }
                }
        }
        return arr4;
}

int hamm::findparity(int i,int temp_arr[])
{
        int j,count=0;
        for(j=0;j<4;j++)
        {
                if(arr1[temp_arr[j]] == 1)
                {
                        count = count + 1;
                }
        }
        if(count % 2 == 0)
        {
                return 0;
        }
        else{
                return 1;
        }
}
