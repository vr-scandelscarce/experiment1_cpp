#include<iostream
#include<cassert>
using namespace std;
class Matrix {
    private:
    int data[2][2];
    public:
    Matrix(int a=0,int b=0,int c=0,int d=0){
        data[0][0]=a;
        data[0][1]=b;
        data[1][0]=c;
        data[1][1]=d;
    }
    Matrix operator+(const Matrix& m){
        Matrix result;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                result.data[i][j]=data[i][j]+m.data[i][j];
            }
        }
        return result;
    }
    Matrix operator *(const Matrix& m){
        Matrix result;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                result.data[i][j]=data[i][0]*m.data[0][j]+data[i][1]*m.data[1][j];
            }
        }
        return result;
    }
    int *operator[](int index){
        assert(index>=0 && index<2);
        return data[index];
    }
    friend ostream& operator<<(ostream& os,const Matrix& m){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<m.data[i][j]<<" ";
            }
            <<endl;
        }
        return cout;
    }
};
int main(){
  Matrix m1(1,2,3,4);
  Matrix m2(5,6,7,8);
Matrix sum = m1+m2;  
  Matrix product = m1*m2;
  assert(sum[0][0]==6 && sum[0][1]==8 && sum[1][0]==10 && sum[1][1]==12);
  assert(product[0][0]==19 && product[0][1]==22 && product[1][0]==43 && product[1][1]==50);
  cout<<"matrix A:"<<endl;
  cout<<m1;
  cout<<"matrix B:"<<endl;
  cout<<m2;
  cout<<"matrix A + B:"<<endl;
  cout<<sum;
  cout<<"matrix A * B:"<<endl;
  cout<<product;
  cout<<"All the tests passed successfully!"<<endl;
  return 0;
}