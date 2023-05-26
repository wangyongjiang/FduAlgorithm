#include <iostream>
#include <vector>
using namespace std;

// 生成元素只有0和1的3行3列矩阵集合
vector<vector<vector<int>>> generate_matrices() {
    vector<vector<vector<int>>> matrices;

    // 生成所有可能的3行3列矩阵
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                for(int l=0; l<2; l++) {
                    for(int m=0; m<2; m++) {
                        for(int n=0; n<2; n++) {
                            for(int o=0; o<2; o++) {
                                for(int p=0; p<2; p++) {
                                    for(int q=0; q<2; q++) {
                                        vector<vector<int>> matrix = {{i,j,k},{l,m,n},{o,p,q}};
                                        matrices.push_back(matrix);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return matrices;
}

// 是否可逆矩阵
bool isReserve(vector<vector<int>> a) {
    int det = 0;

    // 计算行列式
    det = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
          - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
          + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);

    // 行列式为0，2，-2，就不是可逆矩阵
    return det != 0 && det != 2 && det != -2;
}


int main() {
    vector<vector<vector<int>>> allMatrices = generate_matrices();
    // 所有可逆矩阵
    vector<vector<vector<int>>> A;
    for (auto m : allMatrices) {
        if (isReserve(m)) {
            A.push_back(m);
        }
    }



//    // 打印矩阵集合
//    for(int i=0; i<matrices.size(); i++) {
//        for(int j=0; j<matrices[i].size(); j++) {
//            for(int k=0; k<matrices[i][j].size(); k++) {
//                cout << matrices[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }

    return 0;
}
