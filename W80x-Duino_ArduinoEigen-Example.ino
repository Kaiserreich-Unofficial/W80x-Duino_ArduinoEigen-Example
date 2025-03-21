#include "math_completion.h"
#include "eigen_utils.h"

using namespace Eigen;

void setup()
{
    // 初始化串口，设置波特率为115200
    Serial.begin(115200);

    // 定义一个3x3矩阵
    MatrixXd m(3, 3);
    m << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    Serial.println("Original matrix m:");
    printMatrix(m);
    Serial.println();

    // ----------------- SVD 分解测试 -----------------
    long start_time = micros();
    // 使用JacobiSVD进行奇异值分解，要求计算完整的U和V矩阵
    JacobiSVD<MatrixXd> svd(m, ComputeFullU | ComputeFullV);
    MatrixXd U_svd = svd.matrixU();
    VectorXd singularValues = svd.singularValues();
    MatrixXd V_svd = svd.matrixV();
    long svd_time = micros() - start_time;

    Serial.println("SVD Decomposition:");
    Serial.println("Matrix U:");
    printMatrix(U_svd);
    Serial.println("Singular values:");
    printMatrix(singularValues.transpose());
    Serial.println("Matrix V:");
    printMatrix(V_svd);
    Serial.println("Time taken for SVD: " + String(svd_time) + " microseconds");
    Serial.println();

    // ----------------- QR 分解测试 -----------------
    start_time = micros();
    // 使用 HouseholderQR 进行QR分解
    HouseholderQR<MatrixXd> qr(m);
    MatrixXd Q = qr.householderQ();
    // 由于QR分解中R存储在一个压缩矩阵中，通过triangularView<Upper>()获取上三角部分
    MatrixXd R = qr.matrixQR().triangularView<Upper>();
    long qr_time = micros() - start_time;

    Serial.println("QR Decomposition:");
    Serial.println("Matrix Q:");
    printMatrix(Q);
    Serial.println("Matrix R:");
    printMatrix(R);
    Serial.println("Time taken for QR: " + String(qr_time) + " microseconds");
}

void loop()
{
    // 空loop
}
