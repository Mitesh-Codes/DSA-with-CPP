#include<iostream>
using namespace std;

int main(){
    // int n;
    // cin>>n;
    // int i=1;
    
    
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<j;
    //         j++;
    //     }
    //     cout<<"\n";
    //     i++;
    // }


    // int n;
    // cin>>n;
    // int i=1;
    // int count=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=n){
    //         cout<<count<<" ";
    //         count++;
    //         j++;
    //     }
    //     cout<<"\n";
    //     i++;

    // }

    // int n;
    // cin>>n;
    // int i=1;
    

    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<i;
    //         j++;
            
    //     }
        
    //     cout<<"\n";
    //     i+=1;
    // }


    // int n;
    // cin>>n;
    // int i=1;
    // int count=1;
    

    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<count<<" ";
    //         count++;
    //         j++;
            
    //     }
        
    //     cout<<"\n";
    //     i+=1;
    // }


    // int n;
    // cin>>n;
    // int i=1;
    // while(i<=n){
    //     int j=i;
    //     while(j<2*i){
    //         cout<<j<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;

    // }

    // int n;
    // cin>>n;

    // int i=1;
    // while(i<=n){
    //     int j=1;
    //     while(j<=i){
    //         cout<<(i-j+1)<<" ";
    //         j++;
    //     }
    //     cout<<"\n";
    //     i++;
    // }

    // int n;
    // cin>>n;

    // int i=1;
    // char ch='A';
    // while(i<=n){
    //     //char ch='A'+i-1;
    //     int j=1;
    //     while(j<=n){
    //         cout<<ch<<" ";
            
    //         j++;
    //     }
    //     ch++;
    //     cout<<"\n";
        
    //     i++;
    // }


    // int n;
    // cin>>n;

    // int i=1;
    // //char ch='A';
    // while(i<=n){
    //     char ch='A'+i-1;
    //     int j=1;
    //     while(j<=n){
    //         cout<<ch<<" ";
            
    //         j++;
    //     }
    //     ch++;
    //     cout<<"\n";
        
    //     i++;
    // }

    // int i=1;
    // char ch='A';
    // while(i<=n){
    //     //char ch='A';
    //     int j=1;
    //     while(j<=n){
    //         cout<<ch<<" ";
    //         ch++;
            
    //         j++;
    //     }
    //     cout<<"\n";
    //     ch++;
        
    //     i++;
    // }

    // int i=1;
    // char ch='A';
    // while(i<=n){
    //     //char ch='A';
    //     int j=1;
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         //ch++;
            
    //         j++;
    //     }
    //     cout<<"\n";
    //     ch++;
        
    //     i++;
    // }

    // int i=1;
    // char ch='A';
    // while(i<=n){
    //     //char ch='A';
    //     int j=1;
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         ch++;
            
    //         j++;
    //     }
    //     cout<<"\n";
    //     //ch++;
        
    //     i++;
    // }

    // int i=1;
    // //char ch='A';
    // while(i<=n){
    //     int j=1;
    //     char ch='A'+i+j-2;
        
    //     while(j<=i){
    //         cout<<ch<<" ";
    //         ch++;
            
    //         j++;
    //     }
    //     cout<<"\n";
    //     //ch++;
        
    //     i++;
    // }


    // int n;
    // cin>>n;

    // int row=1;
    // while(row<=n){
    //     int space=n-row;
    //     while(space){
    //         cout<<" ";
    //         space=space-1;
    //     }

    //     int col=1;
    //     while(col<=row){
    //         cout<<"*";
    //         col++;
    //     }
    //     cout<<endl;
    //     row++;
        
    // }


    // int n;
    // cin>>n;
    // int i=1;
    
    // while(i<=n){
    //     int j=n;
    //     while(j>=i){
    //         cout<<"*";
    //         j--;
    //     }
    //     cout<<"\n";
    //     i++;
        
    // }


    // int n;
    // cin>>n;
    // int row=1;
    // while(row<=n){
    //     int space=n-row;
    //     while(space){
    //         cout<<" ";
    //         space--;

    //     }
    //     int j=1;
    //     while(j<=row){
    //         cout<<j;
    //         j++;
    //     }
        

    //     int start=row-1;
    //     while(start){
    //         cout<<start;
    //         start=start-1;
    //     }

    //     cout<<endl;
    //     row++;
    // }





    int n;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int start = 1;
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << start;
            start++;
            j++;
        }
        // for stars
        int star = i - 1;
        while (star)
        {
            cout << "*";
            star--;
        }
        int star2 = i - 1;
        while (star2)
        {
            cout << "*";
            star2 = star2 - 1;
        }
        int count = n - i + 1;
        while (count)
        {
            cout << count;
            count = count - 1;
        }

        cout << endl;
        i = i + 1;
    }

    





}